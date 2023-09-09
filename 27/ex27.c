/* 
    Name: ex27.c
    Author: Sreya Goswami
    Description: C Program to Process ls -Rl through exec() family
*/  

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

	char* arr[] = {"ls","-Rl", NULL};

	execl("/usr/bin/ls","ls","-Rl", (char*)NULL);

	execlp("/usr/bin/ls","ls","-Rl", (char*)NULL);

	execle("/usr/bin/ls","ls","-Rl", (char*)NULL, NULL);

	execv("/usr/bin/ls",arr);

	execvp("/usr/bin/ls",arr);

	return 0;
}