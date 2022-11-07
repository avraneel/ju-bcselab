#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "monitor.h"
#include "monitor.c"
//pthread_mutex_t lock;

void *philosopher(void *i)
{
	while(1)
	{
		//variable representing philosopher 
		int self = *(int *) i;
		int j,k;
		j = rand();
		j = j % 11;
		printf("\nPhilosopher %d is thinking for %d secs",self,j);
		sleep(j);
		//philosopher take chopsticks
		take_chopsticks(self);
		k = rand();
		k = k % 4;
		printf("\nPhilosopher %d is eating for %d secs",self,k);
		sleep(k);
		//philosopher release chopsticks
		put_chopsticks(self);
	}

}

int main()
{
	int x;
	printf("Enter no. of philosophers(5/6/7) : " );
	scanf("%d", &x);
	
	int i, pos[x];
	//one thread corresponding to each philosopher
	pthread_t thread[x];
	pthread_attr_t attr;

	//initilize semaphore and other variables
	initialization();

	pthread_attr_init(&attr);

	for (i = 0; i < x; i++) 
	{
		pos[i] = i;
		//create thread corresponding to each philosopher
		pthread_create(&thread[i], NULL,philosopher, (int *) &pos[i]);
	}
	for (i = 0; i < x; i++)
	{
		pthread_join(thread[i], NULL);
	}

	return 0;
}
