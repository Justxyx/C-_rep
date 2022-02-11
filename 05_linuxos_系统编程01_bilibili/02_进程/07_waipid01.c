#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>


int main(){
    int i;
    pid_t pid,wpid,tmpid = 0;

    for(i = 0; i<5;i++){
        pid = fork();

        if  (pid == 0){
            // 新创建的子进程
            if  ( i == 2){
                tmpid = getpid();
                printf(" when i == 2, chilidren pid = : %d\n",tmpid);
            }
            break;
            }
        }

        if( i == 5){
            sleep(1);
            // 父进程
        printf(" parent process , tempid ==: %d\n",tmpid);
        printf(" I'm parent ,pid = %d\n",getpid());
        // wpid = waitpid(tmpid,NULL,0);   阻塞wait
        wpid = waitpid(tmpid,NULL,WNOHANG);     // 非阻塞wait,此时 tmpid 并不是 i = 2 时 的pid。
        printf(" kill children process, wpid = %d\n",wpid);
        }else{
            printf(" I'm children ,pid = %d\n",getpid());
        }
        
    return 0;
}