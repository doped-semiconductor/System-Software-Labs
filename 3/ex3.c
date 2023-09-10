/* 
    Name: ex3.c
    Author: Sreya Goswami
    Description: C Program to create file with creat() 
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

	int fd = creat("./testFile",O_CREAT);
	printf("File Descriptor: %d\n",fd);
	return 0;
}
