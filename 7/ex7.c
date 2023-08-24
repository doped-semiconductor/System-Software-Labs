#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc!=3) {printf("\nWrong parameters\n");return 0;}

	int fd_read = open(argv[1], O_RDONLY);
	int fd_write = open(argv[2], O_WRONLY|O_CREAT, 666);

	if(fd_read==-1 || fd_write==-1) printf("Wrong");

	while(1){
		char buf;
		int char_read = read(fd_read, &buf, 1);
		if(char_read==0) break;
		int char_write = write(fd_write,&buf,1);
	}
	int fdr_close = close(fd_read);
	int fdw_close = close(fd_write);

	
	if(fdr_close==-1 || fdw_close==-1) printf("Wrong");

	return 0;
}
