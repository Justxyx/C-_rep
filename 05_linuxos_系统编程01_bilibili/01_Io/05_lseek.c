#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>


int main(){
    int fd,ret;
    fd = open("03_cp.c",O_RDONLY);
    ret = lseek(fd,0,SEEK_END);
    printf("%d",ret);
}