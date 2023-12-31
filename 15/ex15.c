/* 
    Name: ex15.c
    Author: Sreya Goswami
    Description: C Program to List Environment Variables Related To The User
*/  

#include<stdio.h>
#include<string.h>

extern char **environ;

int prefixMatch(const char *pre, const char *str){
	return strncmp(pre,str,strlen(pre))==0;
}

int main(){
	char **env = environ;
	while(*env!=NULL){
		if(prefixMatch("USER",*env)) printf("%s\n",*env);
		env++;
	}
	return 0;
}
