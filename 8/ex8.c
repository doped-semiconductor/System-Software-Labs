#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char* argv[]){
	if(argc!=2){printf("Wrong parameters\n");return 0;}
	int fd = open(argv[1],O_RDONLY);
	int i=1;
	while(1){
		char c;
		int k = read(fd,&c,1);
		char *line = "Line:";
		write(1,line,5);
		while(k!=0 && c!='\n'){			
			write(1,&c,1);
			//char cc = 't';write(1,&cc,1);
			k = read(fd,&c,1);
		}
		if(k==0) break;
		if(c=='\n'){
			i++;
			char x = '\n';
			write(1,&x,1);	
		}

	}

	close(fd);
	return 0;
}
