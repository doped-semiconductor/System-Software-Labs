/* 
    Name: ex2.c
    Author: Sreya Goswami
    Description: C Program to create program that can run infinitely in background
*/

#include <stdio.h>

int main(){
	printf("Infinite background loop\n");
	int x = getchar();
	printf("%d",x);
}
