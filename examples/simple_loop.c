/*
 *
 * This is a simple C program which is used to demonstrate the working of the criu. 
 *
 */

#include <stdio.h>
#include <unistd.h>


int main(void){

	long long i=0;
	while(1){

		printf("%lld\n",++i);
		sleep(1);

	}
	return 0;
}
