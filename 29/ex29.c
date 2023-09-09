/* 
    Name: ex29.c
    Author: Sreya Goswami
    Description: C Program to Display Min and Max Priority
*/  

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>


int main(){

    int a, b;

    a = sched_getscheduler(getpid());
    printf("First Scheduling Priority: %d \n",a);

    struct sched_param p;
    p.sched_priority = 5;

    b = sched_setscheduler(getpid(), SCHED_RR, &p);
    if(b<0){
    	perror("Can't update scheduling policy");
    	exit(1);
    }

    a = sched_getscheduler(getpid());
    printf("Second Scheduling Priority: %d\n",a);
    
	return 0;
}