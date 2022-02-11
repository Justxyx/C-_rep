// 回收多个子进程

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>


int main(int argc, char *argv[])
{
    int i;
    pid_t pid, wpid;

    for (i = 0; i < 5; i++) {       
        pid = fork();
        if (pid == 0) {       // 循环期间, 子进程不 fork 
            break;
        }
    }

    if (5 == i) {       // 父进程, 从 表达式 2 跳出
    
  	while((wpid=waitpid(-1,NULL,0))>0)
  	{
  		printf("I'm parent,wait a child finish:%d\n",wpid);
  	}
  	
    } else {            // 子进程, 从 break 跳出
        sleep(i);
        printf("I'm %dth child, pid= %d\n", i+1, getpid());
    }

    return 0;
}
