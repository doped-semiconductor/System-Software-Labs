/* 
    Name: ex12.c
    Author: Sreya Goswami
    Description: C Program to Print Mode in Which File is Opened
*/  

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd = open("test.txt",O_WRONLY|O_APPEND);
	int rval = fcntl(fd,F_GETFL);
	int flag = rval & O_ACCMODE;

	if(flag==O_RDONLY) printf("File is Read Only.\n");
	else if(flag==O_WRONLY) printf("File is Write Only.\n");
	else if(flag==O_RDWR) printf("File is Read and Write.\n");
	else printf("Others.\n");

	close(fd);
	return 0;
}
