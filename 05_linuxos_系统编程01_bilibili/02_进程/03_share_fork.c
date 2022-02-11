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


int var = 100;

int main(){

    int flag = fork();
    if (flag == -1)
    {
        perror(" new fork falut");
        exit(1);
    }

    if ( flag == 0)
    {
        var = 101;
    }else{
        var = 102;
    }

    printf("%d\n",var);
    
}