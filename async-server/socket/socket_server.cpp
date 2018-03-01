
bool epoll_server::do_bind(const char *host, int port, int protocol = IPPROTO_TCP) {
    int status;
    int reuse = 1; 
    struct addrinfo ai_hints;
    struct addrinfo *ai_list = NULL;
    char portstr[16];
    if (host == NULL || host[0] == 0) { 
        host = "0.0.0.0";   // INADDR_ANY
    }    
    sprintf(portstr, "%d", port);
    memset( &ai_hints, 0, sizeof( ai_hints ) ); 
    ai_hints.ai_family = AF_INET;
    if (protocol == IPPROTO_TCP) {
        ai_hints.ai_socktype = SOCK_STREAM;
    } else {
        assert(protocol == IPPROTO_UDP);
        ai_hints.ai_socktype = SOCK_DGRAM;
    }    
    ai_hints.ai_protocol = protocol;

    status = getaddrinfo( host, portstr, &ai_hints, &ai_list );
    if ( status != 0 ) {
        return -1;
    }    
    int family = ai_list->ai_family;
    this.m_listen_fd = socket(int family, ai_list->ai_socktype, 0);
    if (this.m_listen_fd < 0) { 
        goto _failed_fd;
    }    
    if (setsockopt(this.m_listen_fd, SOL_SOCKET, SO_REUSEADDR, (void *)&reuse, sizeof(int))==-1) {
        goto _failed;
    }    
    status = bind(this.m_listen_fd, (struct sockaddr *)ai_list->ai_addr, ai_list->ai_addrlen);
    if (status != 0)
        goto _failed;

    freeaddrinfo( ai_list );
    return true;
_failed:
    close(m_listen_fd);
_failed_fd:
    freeaddrinfo( ai_list );
    return false;
}

bool epoll_server::do_listen(int sock_count=1024, int listen_count=5) {
    if (listen(this.m_listen_fd, backlog) == -1) {
        close(m_listen_fd);
        return -1;
    }
    
    m_epoll_events = new struct epoll_event[sock_count];
    if(m_epoll_events == NULL) {
        std::cout<< "epoll_event memory new failed" << std::endl;
        return false;
    }

    m_epoll_fd = epoll_create(sock_count);
    struct epoll_event ev;
    ev.data.fd = sockfd;
    ev.events = EPOLLIN;
    epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, this.m_listen_fd, &ev);
    return true;
}

int epoll_server::do_accept(int sockfd) {
    sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    socklen_t len = sizeof(struct sockaddr);
    int new_sock = accept(sockfd, (struct sockaddr*)&client_addr, &len);
    struct epoll_event ev;
    ev.data.fd = new_sock;
    ev.events = EPOLLIN | EPOLLOUT;
    epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, new_sock, &ev);
    return new_sock;
}

int epoll_server::recv_data(int sockfd, char* recv_buf) {
    char buf[1024] = {0};
    int len = 0;
    int ret = 0;
    while(ret >= 0) {
        ret = recv(sockfd, buf, sizeof(buf), 0);
        if (ret < 0) {
            if(errno == EINTR) {
                continue;
            }
            struct epoll_event ev;
            ev.data.fd = sock;
            ev.events = EPOLLERR;
            epoll_ctl(this.m_epoll_fd, EPOLL_CTL_DEL, sock, &ev);
            close(sockfd);
            break;
        }
        else if(ret < 1024) {
            memcpy(recv_buf, buf, ret);
            len += ret;
            struct epoll_event ev;
            ev.data.fd = sockfd;
            ev.events = EPOLLOUT | EPOLLIN;
            epoll_ctl(this.m_epoll_fd, EPOLL_CTL_MOD, sockfd, &ev);
            break;
        } 
        else {
            memcpy(recv_buf, buf, sizeof(buf));
            len += ret;
        }
    }
    return ret < 0 ? ret : len;
}

int epoll_server::send_data(int sockfd, char* send_buf, int buf_len) {
    int len = 0;
    int ret = 0;
    while(len < buf_len) {
        ret = send(sockfd, send_buf + len, 1024, 0);
        if (ret < 0) {
            if (errno == EINTR) {
                std::cout<< "EINTR" << std::endl;
                continue;
            }
            struct epoll_event ev;
            ev.data.fd = sockfd;
            ev.events = EPOLLERR;
            epoll_ctl(this.m_epoll_fd, EPOLL_CTL_DEL, sockfd, &ev);
            close(sockfd);
            break;
        } 
        else {
            len += ret;
        }

        if(ret < 1024) {
            break;
        }
    }

    if (ret > 0) {
        struct epoll_event ev;
        ev.data.fd = sockfd;
        ev.events = EPOLLIN | EPOLLOUT;
        epoll_ctl(this.m_epoll_fd, EPOLL_CTL_MOD, sockfd, &ev);
    }

    return ret <= 0 ? ret : len;
}

//TODO 用于同步收发消息，后面再改
bool epoll_server::sync_read_write_data(int sockfd, char* send_buf, int send_buf_len, char* recv_buf) {
    int send_len = 0;
    int ret = 0;
    while(send_len < send_buf_len) {
        ret = send(sockfd, send_buf+send_len, 1024, 0);
        if(ret < 0) {
            struct epoll_event ev;
            ev.data.fd = sockfd;
            ev.events = EPOLLERR;
            epoll_ctl(this.m_epoll_fd, EPOLL_CTL_DEL, sockfd, &ev);
            close(fd);
            return false;
        }
        else {
            len += ret;
        }

        if (ret < 1024) {
            break;
        }
    }

    if (ret > 0) {
        struct epoll_event ev;
        ev.data.fd = sockfd;
        ev.events = EPOLLIN | EPOLLOUT;
        epoll_ctl(this.m_epoll_fd, EPOLL_CTL_MOD, sockfd, &ev);
    }
}

int epoll_server::run(int time_out) {
    char* recv_buf = new char[65535];
    char* send_buf = new char[65535];
    while(true) {
        int ret = epoll_server_wait(time_out);
        if(ret == 0) {
            std::cout<<"time out"<<std::endl;
            continue;
        }

        else if (ret == -1) {
            std::cout<<"error"<<std::endl;
        }

        else {
            for(int i=0; i<ret; i++) {
                if (m_epoll_events[i].data.fd == m_listen_sock) {
                    if (m_epoll_events[i].events & EPOLLIN) 
                    {
                        int new_sock = accept_new_client();
                    }
                } 
                else 
                {
                    if (m_epoll_events[i].events & EPOLLIN) {
                        int recv_count = recv_data(m_epoll_events[i].data.fd, recv_buf);
                    }
                    else if (m_epoll_events[i].events & EPOLLOUT)
                    {
                        int send_cout = send_data(m_epoll_events[i].data.fd, send_buf, strlen(send_buf));
                    }
                }
            }
        }
    }
}


