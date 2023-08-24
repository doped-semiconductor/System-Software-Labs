#include <sys/select.h>
#include <stdio.h>

int main(){
	struct timeval t;
	t.tv_sec = 10;
	t.tv_usec = 0;

	printf("Enter Input in 10 Secs:\n");
	if(select(0, NULL, NULL, NULL, &t)<0) printf("\nDid not receive input in 10secs\n");

	printf("Exiting.\n");

	return 0;
}
