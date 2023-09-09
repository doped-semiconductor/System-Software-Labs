/* 
    Name: ex22.c
    Author: Sreya Goswami
    Description: C Program to Create Child and Parent Process with fork() and Write to Same File
*/  

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main(){

	int fd = open("testFile.txt",O_RDWR|O_CREAT,0777);
	if(fd<0){
		printf("Can't open file :(");
		return 0;
	}

	char *a; int n;

	if(!fork()){
		a = "Parent Bottle Bag Kite\n";
		n = strlen(a);
		int w = write(fd,a,n);
		if(w<0){
			printf("Could not write to file\n");
		}

	}
	else{
		a = "Child Drink Cat Bolt\n";
		n = strlen(a);
		int w = write(fd,a,n);
		if(w<0){
			printf("Could not write to file\n");
		}

	}

}