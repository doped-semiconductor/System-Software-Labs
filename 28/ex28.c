/* 
	Name: ex28.c
	Author: Sreya Goswami
	Description: C Program to Display Min and Max Priority
*/  

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>


int main(){

	int a, b;

	a = sched_get_priority_max(SCHED_FIFO);
    b = sched_get_priority_min(SCHED_FIFO);

    printf("Policy: FIFO\tMax: %d\tMin: %d\n",a,b);

    a = sched_get_priority_max(SCHED_RR);
    b = sched_get_priority_min(SCHED_RR);

    printf("Policy: RR\tMax: %d\tMin: %d\n",a,b);

    a = sched_get_priority_max(SCHED_OTHER);
    b = sched_get_priority_min(SCHED_OTHER);

    printf("Policy: Other\tMax: %d\tMin: %d\n",a,b);

	return 0;
}