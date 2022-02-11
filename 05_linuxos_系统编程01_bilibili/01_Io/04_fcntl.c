#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>


int main(){
    int flag = 0;
    flag = fcntl(STDIN_FILENO,F_GETFD);
    if (flag == -1)
    {
        perror("fcntl error");
        exit(1);
    }
    // printf("%d",flag);   // 0


    flag  |= O_NONBLOCK;  // 调为非阻塞状态  位或
    int ret = fcntl(STDIN_FILENO,F_SETFD,flag);  // F_SETFD

    return 0;
}