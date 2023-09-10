/* 
    Name: ex30.c
    Author: Sreya Goswami
    Description: C Program to Create a Daemon
*/  

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){
	pid_t pid;
	pid = fork();

	if(pid == -1)
		return -1;
	else if(pid!=0){
		exit(EXIT_SUCCESS);
	}

	if(setsid()==-1)
		return -1;

	if(chdir("/")==-1)
		return -1;

	umask(0);

	for(int i=0;i<3;i++) 
		close(i);

	int f = open("/dev/null",O_RDWR);
	dup(0);
	dup(0);

	int fd = open("daemonlog.txt",O_RDWR|O_CREAT,0777);
	char *a = "1 2 3\n";
	int n = sizeof(a);

	while(!0){
		write(fd,a,n);
		sleep(10);
	}
	
	return 0;


}