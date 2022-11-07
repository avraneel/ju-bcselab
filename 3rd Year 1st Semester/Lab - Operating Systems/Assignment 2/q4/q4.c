#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>
#include <sys/mman.h>
#include <time.h>
#include <stdbool.h>

// all producers will have pid == 0
// all consumers will have cid == 0

sem_t *prod_lock;
sem_t *con_lock;
sem_t *buffer_lock_empty;
sem_t *buffer_lock_full;

int main(int argc, char* argv[]) {
	
	int p, c;
	int pid, cid;
	
	prod_lock = sem_open("producer", O_CREAT | O_EXCL, 0644, 1);
	con_lock = sem_open("consumer", O_CREAT | O_EXCL, 0644, 1);
	buffer_lock_empty = sem_open("bufferempty", O_CREAT | O_EXCL, 0644, 0); 
	buffer_lock_full = sem_open("bufferfull", O_CREAT | O_EXCL, 0644, 0);	
	
	// Stores the sum
	int* TOTAL = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*TOTAL = 0;
	
	// Front pointer
	int *FRONT = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*FRONT = -1;
	
	// Rear pointer
	int *REAR = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*REAR = -1;
	
	// Shared Circular buffer
	int* BUFFER = mmap(NULL, 25*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	for(int i = 0; i < 25; i++) {
		BUFFER[i]  = 0;
	}
	
	bool* HASREAD = mmap(NULL, 25*sizeof(bool), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	printf("Enter number of producers: ");
	scanf("%d", &p);
	printf("Enter number of consumers: ");
	scanf("%d", &c);
	
	int prod[p];
	int con[c];
	
	// Forking into parent producer process
	pid = fork();
	
	
	// Forking into parent consumer process
	if(pid != 0) {
		cid = fork();
	}
	
	if(pid == 0) {	
		// Producers
		for(int i = 0; i < p; i++) {
			prod[i] = fork();
			if(prod[i] == 0) {
				// Child producer process
				printf("Producer %d created.\n", i+1);
				srand(time(NULL) + getpid());
				int item = (rand() % 80) + 1;
				if(*FRONT == -1 && *REAR == -1) {
					// first element to be inserted
					*FRONT = 0;
					*REAR = 0;
					BUFFER[*REAR] = item;
					sem_post(buffer_lock_empty);
				}
				else if(((*REAR + 1) % 25) == *FRONT) {
					// Buffer full
					sem_wait(buffer_lock_full);
				}
				else {
					*REAR = ((*REAR) + 1) % 25;
					BUFFER[*REAR] = item;
				}
				printf("[[PRODUCER %d]] Item produced: [[%d]]\n", i+1, item);
				sem_post(prod_lock);
				exit(0);
			}
		}		
	}
	
	if(pid != 0 && cid == 0) {
		// Consumers 
		for(int i = 0; i < c; i++) {
			con[i] = fork();
			if(con[i] == 0) {
				// Child consumer process
				printf("Consumer %d created.\n", i+1);
				sem_wait(con_lock);
				int x;
				if(*FRONT == -1 && *REAR == -1) {
					// Buffer empty
					sem_wait(buffer_lock_empty);
				}
				else if(*FRONT == *REAR) {
					// only one element
					x = BUFFER[*FRONT];
					*FRONT = -1;
					*REAR = -1;
					//printf("Front: %d\n", *FRONT);
					//printf("Rear: %d\n", *REAR);
				}
				else {
					if(((*REAR + 1) % 25) == *FRONT) {
						// consuming from full buffer
						sem_post(buffer_lock_full);
					}
					x = BUFFER[*FRONT];
					*FRONT = ((*FRONT + 1) % 25);
					HASREAD[*FRONT] = true;
				}
				*TOTAL += x;
				printf("[[CONSUMER %d]] Item consumed: [[%d]]\n", i+1, x);
				//printf("Front: %d\n", *FRONT);
				//printf("Rear: %d\n", *REAR);
				sem_post(con_lock);
				break;
			}
		}		
	}
	
	sem_unlink("producer");
	sem_close(prod_lock);
	sem_unlink("consumer");
	sem_close(con_lock);
	sem_unlink("bufferempty");
	sem_close(buffer_lock_empty);
	sem_unlink("bufferfull");
	sem_close(buffer_lock_full);
	
	if(pid != 0 && cid != 0) {
		// Main process
		for(int i = 0; i <= p*c; i++)
			wait(NULL);
		printf("\nTotal is: %d\n", *TOTAL);
	}
	
	
	return 0;
}
