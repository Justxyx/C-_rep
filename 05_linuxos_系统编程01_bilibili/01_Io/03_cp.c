#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>


int main(int argc,char *argv[]){
    char buf[1024];
    int  n = 0;
    int fd1 = open(argv[1],O_RDONLY);  // 只读
    if  ( fd1 == -1){
        perror("open argv1 error");   // perror 会根据全局的errno 自动生成错误提示信息 贼方便
        exit(1);
    }
    int fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);  // 读权限肯定有  如果没有就创建  如果有这个文件 trunc 重写为0
    if  ( fd2== -1){
        perror("open argv2 error");
        exit(1);
    }
    while ((n = read(fd1,buf,1024)) != 0)
    {
        if (n < 0)
        {
            /* code */
            perror(" read error");
            break;
        }
        
        write(fd2,buf,n);
    }

    close(fd1);
    close(fd2);
    

    return 0;
    
}
