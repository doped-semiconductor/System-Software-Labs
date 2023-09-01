#include <stdio.h>
#include <unistd.h>

int main(){

	if(!fork()){
		int x = getpid();
		printf("Parent PID: %d\n",x);
	}
	else{
		int y = getpid();
		printf("Child PID: %d\n",y);

	}

}