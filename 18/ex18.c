#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

// Program to add 3 initial values of student entity

struct Student{
	int id;
	int marks;
};

int main(){

	struct Student s1, s2, s3;
	s1.id=1; s1.marks=97; 
	s2.id=2; s2.marks=93; 
	s3.id=3; s3.marks=67; 

	int fd = open("records.txt",O_RDWR|O_CREAT,0777);
	if(fd<0) perror("Could not open records");

	//since we are initializing
	lseek(fd,0,SEEK_SET);

	int w1 = write(fd,&s1,sizeof(struct Student));
	if(w1<0) perror("Could not write to records");

	write(fd,&s2,sizeof(struct Student));
	write(fd,&s3,sizeof(struct Student));

	close(fd);


	return 0;
}