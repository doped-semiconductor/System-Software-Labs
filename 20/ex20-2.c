/* 
    Name: ex20.c
    Author: Sreya Goswami
    Description: C Program to Get and Set Priority of A Process 
*/  

#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	int pid = getpid();
	printf("PID: %d\n",pid);

	int priority = getpriority(PRIO_PROCESS, pid);
	printf("Current Priority: %d\n", priority);

	priority = setpriority(PRIO_PROCESS, pid, -5);
	priority = getpriority(PRIO_PROCESS, pid);
	printf("Updated Priority: %d\n", priority);

}
