/* 
    Name: ex1.c
    Author: Sreya Goswami
    Description: C Program to Create 
    	1. Soft Link
    	2. Hard Link
    	3. FIFO
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

	int s1 = symlink("file1.txt", "slFile1FromC");
	if(s1<0) perror("Soft Link Fail");

	int s2 = link("file2.txt","hlFile2Fromc");
	if(s2<0) perror("Hard Link Fail");

	int s3 = mknod("myfifo",S_IFIFO,0);
	if(s3<0) perror("MKFIFO Fail");

	return 0;
}
