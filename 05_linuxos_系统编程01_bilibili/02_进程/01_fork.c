#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

    pid_t pid = 0;
    pid = fork();

    if  (pid == 0){
        // 子进程
        printf("son process.%d\n",getpid());
    } else if( pid == -1 ){
        perror("prcoess error%d\n");
    }else if (pid > 0)
    {
        printf(" father process\n");
    }
    
    printf("-----------------------------\n");
    return 0;

}


