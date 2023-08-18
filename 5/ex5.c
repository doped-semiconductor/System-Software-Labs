#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//create 5 new files and go to inf loop
	char *a = "12345";
	for(int i=0;i<5;i++){
		char x[4] = "tmp0";
		x[3] = a[i];

		int fd = creat(x,O_CREAT);
		//printf("%d\n",fd);
		
	}
	while(1){int x=1;}
	return 0;
}
