#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){
	printf("Start\n");
	pid_t pid;
	pid = fork();

	if(pid == -1)
		return -1;
	else if(pid!=0){
		printf("Kill PArent\n");
		exit(EXIT_SUCCESS);
	}

	printf("Child\n");

	if(setsid()==-1)
		return -1;

	printf("sid set\n");

	if(chdir("/")==-1)
		return -1;

	printf("dir changed\n");

	umask(0);

	for(int i=0;i<3;i++) 
		close(i);

	int f = open("/dev/null",O_RDWR);
	dup(0);
	dup(0);

	sleep(100);
	return 0;


}