#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/select.h>

struct student{
	int id;
	int marks;
};

int openFile(){
	char *msg; int msgLen;
	int fd = open("records.txt",O_RDWR|O_CREAT,0777);
	if(fd<0){
		perror("\nCan't open records.\n");
		exit(0);
	}
	return fd;	
}

void setFlock(struct flock *fl, int type,int start){
	//lock record
	if(type==0) fl->l_type=F_WRLCK;
	if(type==1) fl->l_type=F_RDLCK;
	
	//unlock record
	else fl->l_type=F_UNLCK;

	fl->l_whence=SEEK_SET;
	fl->l_start=start;
	fl->l_len=sizeof(struct student);
	fl->l_pid = getpid();
}


int setLock(int fd, struct flock *fl, int type){
	//type: 0->read 1->write 2->unlock
	char *msg;

	if(type==1) msg = "\nRequesting write lock for record";
	else if(type==0) msg = "\nRequesting read lock for record";
	else msg = "\nUnlocking file";

	printf("%s\n",msg);
	fcntl(fd,F_SETLKW,fl);

	if(type<2) msg = "Acquired file lock";
	else msg = "\nFile Unlocked\n";
	printf("%s\n",msg);
}


int main(){
	int menu = -1;

	struct student stud;

	char *msg = "\nChoose an option:\n\t1. Read record by Student ID\n\t2. Write new record for Student\n\t3. Exit\n";
	char *msg2 = "\nEnter student ID: \n";
	char *msg3 = "\nEnter student marks: \n";
	char *msg4 = "\nID: \t";
	char *msg5 = "Marks: \t";
	char *msg6 = "\nDone. Press any key to unlock file...";

	int id, marks;

	while(menu!=0){
		printf("%s",msg);
		scanf("%d",&menu);
		if(menu==1){
			//read
			printf("%s",msg2);
			scanf("%d",&id);
			
			int fd = openFile();
			int start = sizeof(struct student)*(id-1);

			struct flock fl;
			setFlock(&fl,1,start);
			setLock(fd, &fl, 0);

			lseek(fd,start,SEEK_SET);
			read(fd,&stud,sizeof(stud));
			printf("%s",msg4);
			printf("%d\n",stud.id);

			printf("%s",msg5);
			printf("%d\n",stud.marks);

			printf("%s",msg6);
			getchar(); getchar();

			fl.l_type=F_UNLCK;
			setLock(fd, &fl, 2);

			close(fd);

		}
		else if(menu==2){
			printf("%s",msg2); scanf("%d",&id);
			printf("%s",msg3); scanf("%d",&marks);

			stud.id=id; stud.marks=marks;

			int fd = openFile();
			int start = sizeof(struct student)*(id-1);
			lseek(fd,start,SEEK_SET);

			struct flock fl;
			setFlock(&fl,0,start);
			setLock(fd,&fl,1);

			write(fd,&stud,sizeof(stud));

			printf("%s",msg6);
			getchar(); getchar();

			fl.l_type=F_UNLCK;
			setLock(fd, &fl, 2);

			close(fd);


			
		}
		else break;
	}
	return 0;
}
