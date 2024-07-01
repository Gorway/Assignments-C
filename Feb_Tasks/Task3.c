#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>


int main () {

	int ret = getpriority(PRIO_PROCESS, 0); 
	printf("Process priority before change: %d\n", ret );

    ret = setpriority(PRIO_PROCESS, 0, 10);
	
	printf("Process priority after change: %d\n", ret );


}
