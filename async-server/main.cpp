#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutexattr_t attr;

int main()
{
    int err;
    int number = 5;
    pthread_t tids[number];
    if ((err = pthread_mutexattr_init(&attr)) != 0)
        err_exit(err, "pthread_mutexattr_init failed");
    if ((err = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK)) != 0)
        err_exit(err, "can't set recursive type");
    if ((err = pthread_mutex_init(&mutex, &attr)) != 0)
        err_exit(err, "can't create recursive mutex");
    return 0;
}


