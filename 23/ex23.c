#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
	if(!fork()){
		int pid = getpid();
		printf("Child Process ID: %d\n", pid);
		exit(0);
	}
	else{
		int pid = getpid();
		printf("Parent Process ID: %d\n", pid);
		sleep(100);
	}
}