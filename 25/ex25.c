#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(){
	int i;
	//create 3 child process
	for(i=0;i<3;i++){
		switch(fork()){
			case(-1):
				printf("Issue with fork()\n");
			case(0):
				printf("Child #%d\t PID: %d\n",i+1,getpid());
				sleep(5);
				_exit(EXIT_SUCCESS);
			default:
				break;
		}
	}

	i=0;
	while(i<3){
		printf("Waiting for child #%d\n",i+1);
		int s;
		waitpid(0,&s,0);
		printf("Child %d finished. Status: %d\n",i+1,s);
		i++;
	}
}

