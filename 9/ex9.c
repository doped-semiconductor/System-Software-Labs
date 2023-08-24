#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Please enter 1 filename as parameter.\n");
		return 0;
	}
	struct stat x;
	if (stat(argv[1],&x)==0){
		printf("Inode:\n");
		printf("%ld\n",x.st_ino);

		printf("\nNumber of Hard Links:\n");
		printf("%ld\n",x.st_nlink);
		
		printf("\nUID:\n");
		printf("%d\n",x.st_uid);

		printf("\nGID:\n");
		printf("%d\n",x.st_gid);


		printf("\nSize:\n");
		printf("%ld\n",x.st_size);
		
		printf("\nBlock Size:\n");
		printf("%ld\n",x.st_blksize);
		
		printf("\nNumber of Blocks:\n");
		printf("%ld\n",x.st_blocks);

		struct tm dt;
		printf("\nTime of Last Access:\n");
		dt = *(gmtime(&x.st_atime));
		printf("%d-%d-%d %d:%d:%d\n",dt.tm_mday, dt.tm_mon, (dt.tm_year+1900), dt.tm_hour, dt.tm_min,dt.tm_sec);
		printf("\nTime of Last Modification:\n");
		dt = *(gmtime(&x.st_mtime));
		printf("%d-%d-%d %d:%d:%d\n",dt.tm_mday, dt.tm_mon, (dt.tm_year+1900), dt.tm_hour, dt.tm_min,dt.tm_sec);
		
		printf("\nTime of Last Change:\n");
		dt = *(gmtime(&x.st_ctime));
		printf("%d-%d-%d %d:%d:%d\n",dt.tm_mday, dt.tm_mon, (dt.tm_year+1900), dt.tm_hour, dt.tm_min,dt.tm_sec);
	}
	else printf("Unable to process file\n");	
	return 0;

}
