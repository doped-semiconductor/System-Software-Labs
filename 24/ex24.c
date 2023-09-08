#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
	if(!fork()){
		int pid = getpid();
		printf("Child Process ID: %d\n", pid);
		printf("Parent Process ID: %d\n", getppid());
		sleep(50);
		printf("Sleep over. %d\n",getppid());
	}
	else{
		int pid = getpid();
		printf("From parent\n");
	}
}