/* 
    Name: ex4.c
    Author: Sreya Goswami
    Description: C Program to Open Files And Test O_EXCL flag
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	int fd = open("./existingFile",O_RDONLY);
	printf("File Descriptor: %d\n",fd);

	int fd2 = open("./otherExistingFile",O_EXCL|O_CREAT);
	printf("File Descriptor 2: %d\n",fd2);

	close(fd2);
	close(fd);
	return 0;
}
