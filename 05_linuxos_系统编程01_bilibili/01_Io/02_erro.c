 #include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <stdio.h>
 #include<string.h>

/**
 *      x   ---  1
 *      w  ---  2
 *      r  ----  4 
 */

 int main(){
     int fd = 0;
     fd = open("temp.txt",O_RDONLY);
     // 把errno看为一个操作系统的全局变量即可啦
    printf("%d\n",errno);     
    printf("------------------------\n");
    printf("%s\n",strerror(errno));
    return 0;
 }