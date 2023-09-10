/* 
    Name: ex11.c
    Author: Sreya Goswami
    Description: C Program to Open Files using dup, dup2, fcntl
*/  

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd = open("test.txt",O_WRONLY|O_APPEND);
	int fd2 = dup(fd);

	write(fd, "Test Line 1\n",12);
	write(fd2, "Test Line 2\n",12);

	int fd3 = dup2(fd,7);
	write(fd3, "Test Line 3\n",12);

	int fd4 = fcntl(fd,F_DUPFD);
	write(fd4, "Test Line 4\n",12);

	printf("\nFile Desciptors: %d, %d, %d, %d\n",fd,fd2,fd3,fd4);
	
	
	return 0;
}
