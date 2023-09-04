#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	int pid = getpid();//atoi(argv[1]);//
	printf("PID: %d\n",pid);

	int priority = getpriority(PRIO_PROCESS, pid);
	printf("Current Priority: %d\n", priority);

	priority = setpriority(PRIO_PROCESS, pid, -5);
	priority = getpriority(PRIO_PROCESS, pid);
	printf("Updated Priority: %d\n", priority);

}
