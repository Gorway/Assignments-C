#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


void run_process(pid_t *process_priority, int* index) {

	pid_t pid; 
	
	if((pid = fork()) == 0) {

	int ret = getpriority(PRIO_PROCESS, 0);

	process_priority[*index++] = ret;
	
	exit(0);
    }
} 


int main() {
	
	int size = 5;
	pid_t process_priority[size];
	int index = 0;

	for(int i = 0; i < size ; i++) {
	
		run_process(process_priority, &i);


		printf("Process %d: Priority: %d\n", i, process_priority[i]);
    
	 }
 
}
		
		
	
