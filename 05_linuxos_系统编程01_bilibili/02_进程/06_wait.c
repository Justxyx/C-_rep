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
#include<sys/wait.h>



int main(){
    pid_t pid,wpid;
    int status;

    pid = fork();
    if(pid == 0){
        printf(" child,my id = %d,going to sleep 10 s\n",getpid());
        sleep(10);
        printf("child is going to died\n");
    }else if(pid > 0){
        wpid = wait(&status);
        if (wpid == -1)
        {
            // 进程回收失败
            perror("wait error");
            exit(1);
        }
        printf("praent wait finish: wpid = %d\n",wpid);
        
    }else{
        perror("fork error");
        return 1;
    }
}