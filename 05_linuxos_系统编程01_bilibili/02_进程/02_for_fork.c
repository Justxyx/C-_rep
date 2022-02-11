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

/**
 * @brief 
 *      for 循环生成多线程
 */


int main(){
    int i;
    for ( i = 0; i < 5; i++)
    {
        if (fork() == 0)
        {
            //子进程
            break;
        }   
    }
    
    printf(" I am %d process\n",i);
    return 0;

}