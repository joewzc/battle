#ifndef _SOCKET_SERVER_H
#define _SOCKET_SERVER_H

/**
 *TODO 后面可能需要再修改，因为对一些条件处理过于简单,该服务可能会不太稳定
 *
 * epoll和socket相关接口
**/
class epoll_server {
    int m_listen_sock;
    int m_epoll_fd;
    int m_max_count;
    struct epoll_event *m_epoll_events;
    
    public:
    int do_bind(char* host, int port, int protocal = IPPROTO_TCP);
    int do_listen(int sock_count=1024, int listen_count=5);
    int do_accept(int);
    int recv_data(int, char*);
    int send_data(int sockfd, char* send_buf, int buf_len);

    bool sync_read_write_data(int sockfd. char* send_buf, int send_buf_len, char* recv_buf);

    int run(int time_out);

}

#endif
