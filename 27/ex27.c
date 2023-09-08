#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

	char* arr[] = {"ls","-ri", NULL};

	execl("/usr/bin/ls","ls","-ri", (char*)NULL);

	execlp("/usr/bin/ls","ls","-ri", (char*)NULL);

	execle("/usr/bin/ls","ls","-ri", (char*)NULL, NULL);

	execv("/usr/bin/ls",arr);

	execvp("/usr/bin/ls",arr);

	return 0;
}