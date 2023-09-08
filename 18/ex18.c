/**
 * 
 * Name: ex18.c
 * Author: Sreya Goswami
 * Description: Menu Driven Program to Implement Read/Write Lock for Records
 * 
 * */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct student{
	int id;
	char name[20];
};

int main(){
	int m;
	char menu[100];
	struct student s;
	struct flock fl;
	int fd;
	int r,w,n = sizeof(struct student);
	strcpy(menu,"\n---------------\n[MENU]\n\t1. Initialize\n\t2. Read\n\t3. Write\n\t4. Exit\n");

	while(!0){
		printf("%s",menu);
		scanf("%d[^\n]",&m);
		if(m==1){
			fd = open("records",O_EXCL|O_CREAT,0777);

			if(fd<0){
				perror("Can't Initialize");
				continue;
			}

			//1
			s.id=1;strcpy(s.name,"Icy");
			w = write(fd, &s, sizeof(s));
			if(w<0) perror("Can't write\n");

			//2
			s.id=2;strcpy(s.name,"Blume");
			w = write(fd, &s, sizeof(s));
			if(w<0) perror("Can't write\n");

			//3
			s.id=3;strcpy(s.name,"Stormie");
			w = write(fd, &s, sizeof(s));
			if(w<0) perror("Can't write\n");

			close(fd);
		}
		else if(m==2){
			fd = open("records",O_RDONLY,0777);
			if(fd<0){
				perror("Can't open records\n");
				return -1;
			}
			int id;
			printf("Enter ID: \n"); scanf("%d[^\n]",&id);

			fl.l_type = F_RDLCK;
			fl.l_whence = SEEK_SET;
			fl.l_start = n*(id-1);
			fl.l_len = n;
			fl.l_pid = getpid();

			printf("Requesting read lock\n");
			fcntl(fd, F_SETLKW,&fl);
			printf("Acquired read lock\n");

			lseek(fd, n*(id-1), SEEK_SET);
			read(fd, &s, n);
			printf("ID: %d Name: %s\n",s.id,s.name);

			fl.l_type = F_UNLCK;
			printf("Enter to release lock...\n");
			getchar();getchar();

			fcntl(fd, F_SETLKW,&fl);
			printf("Released lock\n");

			close(fd);
		}
		else if(m==3){
			fd = open("records",O_WRONLY,0777);
			if(fd<0){
				perror("Can't open records\n");
				return -1;
			}

			int id; char nameBuffer[20];
			printf("Enter ID: \n"); scanf("%d[^\n]",&id);
			printf("Enter Name: \n"); scanf("%s[^\n]",nameBuffer);

			s.id = id; strcpy(s.name,nameBuffer);

			fl.l_type = F_WRLCK;
			fl.l_whence = SEEK_SET;
			fl.l_start = n*(id-1);
			fl.l_len = n;
			fl.l_pid = getpid();

			printf("Requesting write lock\n");
			fcntl(fd, F_SETLKW,&fl);
			printf("Acquired write lock\n");

			lseek(fd, n*(id-1), SEEK_SET);
			w = write(fd, &s, n);
			if(w<0){
				perror("Can't write\n");
				return -1;
			}
			printf("Write Operation Completed\n");

			fl.l_type = F_UNLCK;
			printf("Enter to release lock...\n");
			getchar();getchar();

			fcntl(fd, F_SETLKW,&fl);
			printf("Released lock\n");

			close(fd);
		}
		else break;
	}	

	return 0;
}