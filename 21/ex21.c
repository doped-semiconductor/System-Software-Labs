/* 
    Name: ex21.c
    Author: Sreya Goswami
    Description: C Program to Create Child and Parent Process with fork() and Display PIDs
*/  

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