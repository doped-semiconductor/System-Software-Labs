#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("test.txt",O_RDWR,0777);
	char *a = "Writing a sentence to send to file.";
	write(fd,a,10);
	int l = lseek(fd,10,SEEK_CUR);
	printf("lseek:%d",l);
	write(fd,a,10);
	//od -b test.txt -> to see result
	return 0;
}
