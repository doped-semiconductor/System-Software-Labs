/* 
    Name: ex23.c
    Author: Sreya Goswami
    Description: C Program to Create Zombie Process
*/  

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