/* 
    Name: ex16-write.c
    Author: Sreya Goswami
    Description: C Program to Apply Write Lock on File
*/  

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	printf("Opening file\n");
	int fd = open("test.txt",O_WRONLY);
	if(fd<0){printf("Unable to open file\n");return 0;}
	
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	
	printf("Setting write lock on file\n");
	fcntl(fd,F_SETLKW,&fl);
	printf("Write lock Set\n");


	printf("Enter anything to unlock\n");
	getchar();
	fl.l_type=F_UNLCK;
	printf("Unlocking file\n");
	fcntl(fd,F_SETLK,&fl);

	close(fd);


	return 0;
}
