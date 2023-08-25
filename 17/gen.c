#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

struct tk{
	int t;
};

int main(){
	struct tk n;
	printf("Enter number\n");
	int x;
	scanf("%d",&x);
	n.t = x;

	int fd = open("ticket",O_WRONLY);
	if(fd<0){printf("Can't open ticket file.\n");return 0;}

	int w = write(fd,&n,sizeof(struct tk));
	if(w<0){printf("Could not write to file.\n");return 0;}

	printf("Done.\n");

	return 0;
}

