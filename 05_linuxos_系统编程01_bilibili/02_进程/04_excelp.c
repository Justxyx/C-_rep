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

    pid_t pid = fork();

if (pid == -1  )
{
    perror(" fork error");
    exit(1);
} else if (pid == 0)
{
    execlp("ls","ls","-l",NULL);    
    perror("exec error");
    exit(1);
}else if(pid > 0){
    sleep(1);
    printf("I m parent");
    
}
return 0;
}