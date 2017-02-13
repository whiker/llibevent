int epoll_create(int size);
    创建一个新的epoll句柄epfd。

int epoll_ctl(int epfd, int op, int fd, epoll_event* event)
    向epfd注册事件。
    > op: EPOLL_CTL_ADD, EPOLL_CTL_MOD, EPOLL_CTL_DEL
    > fd: 哪个文件描述符的事件
    < return: if 成功, 0

struct epoll_event {
    __uint32_t events;  // EPOLLIN, EPOLLOUT, EPOLLPRI, EPOLLHUGP, EPOLLET, EPOLLONESHOT
    epoll_data_t data;
}

typedef union epoll_data {
    void* ptr;
    int fd;
    uint32_t u32;
    uint64_t u64;
} epoll_data_t;

int epoll_wait(int epfd, epoll_event* event, int maxevents, int timeout)
    > epfd
    < event: 内核返回的事件集合，一般传入一个数组
    > maxevents: 最多返回的事件数，<= event的容量
    > timeout: -1, 阻塞;  0, 立即返回;  >0, 等待多少微秒
    < return: if 成功, 通过event返回的事件数; else 失败, -1