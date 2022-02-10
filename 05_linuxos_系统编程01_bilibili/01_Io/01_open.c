#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
 #include <fcntl.h>

/**
 *      x   ---  1
 *      w  ---  2
 *      r  ----  4 
 */

 int main(){
     int fd = 0;
     // 只写
     fd = open("temp.txt",O_WRONLY);
    // 追加写
    fd = open("temp2.txt",O_WRONLY|O_APPEND);
    // 只读的方式打开 若不存在 就以权限777创建
    fd = open("temp3.txt",O_RDONLY|O_CREAT,0777);
 }