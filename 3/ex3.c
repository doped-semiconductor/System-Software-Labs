#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

	int fd = creat("./testFile",O_CREAT);
	printf("File Descriptor: %d\n",fd);
	return 0;
}
