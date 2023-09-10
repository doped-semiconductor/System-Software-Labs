/* 
    Name: ex6.c
    Author: Sreya Goswami
    Description: C Program to read from one STDIN and write to STDOUT
*/

#include <unistd.h>

int main(){
	write(1,"writing hello with write sys call\nEnter a value to read with sys call",40);
	char a[100];

	read(0,a,100);
	write(1,a,100);

	return 0;
}
