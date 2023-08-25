#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
//#include<.h>

struct tk{
	int t;
};
int main(){
	struct tk n;
	int fd = open("ticket",O_RDWR);
	if(fd<0){printf("Can't open ticket file.\n");return 0;}

	int r = read(fd,&n,sizeof(struct tk));
	if(r<0){printf("Can't read file.\n");return 0;}

	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();

	printf("Applying write lock to ticket\n");

	fcntl(fd,F_SETLKW,&fl);
	printf("Lock applied. Updating ticket.\n");
	
	n.t++;
	
	printf("New Ticket Number:%d\n",n.t);

	lseek(fd,0,SEEK_SET);
	int w = write(fd,&n,sizeof(struct tk));
	if(w<0){printf("Could not overwrite file.\n");}

	fl.l_type = F_UNLCK;
	printf("Press any character to release lock.\n");
	getchar();

	fcntl(fd,F_SETLKW,&fl);

	close(fd);
	return 0;
}
