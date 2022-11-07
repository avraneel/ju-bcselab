/*
 Write a program for the Reader-Writer process for the following situations: 
a) Multiple readers and one writer: writer gets to write whenever it is ready (reader/s wait) 
b) Multiple readers and multiple writers: any writer gets to write whenever it is ready, provided no other 
writer is currently writing (reader/s wait) 
*/

#include <stdio.h>
#include <pthread.h>
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

sem_t *rw_mutex;
sem_t *mutex;  

int main() {

    int pid, pid2, pid3;
    srand(time(NULL));

    // initializing semaphores
    rw_mutex = sem_open("rwmutex", O_CREAT | O_EXCL, 0644, 1);
    mutex = sem_open("mutex", O_CREAT | O_EXCL, 0644, 1);

    // declaring and initializing shared data
    int *data = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *data = 10;

    // counts how many readers are currently reading the data
    int *read_count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *read_count = 0;

    pid = fork();   // Writer process pid = 0
    if(pid != 0) {
        pid2 = fork();  // Reader 1
    }
    if(pid != 0 && pid2 == 0) {
        pid3 = fork();  // Reader 2
    }

    // Writer process
    if(pid == 0) {
        //do {
        
            int temp;
            sem_wait(rw_mutex);
            temp = (int)(rand() % 100);
            printf("[WRITER] Data input: %d\n", temp);
            *data = temp;
            sem_post(rw_mutex);
        //} while(true);
    }
    
    if(pid != 0 && pid2 == 0) {
        //do {
            sem_wait(mutex);
            (*read_count)++;
            //printf("[READER] rd count = %d", *read_count);
            if (*read_count == 1)
                sem_wait(rw_mutex);
            sem_post(mutex);
            int t = *data;
            printf("[READER] Data output = %d\n", t);
            sem_wait(mutex);
            (*read_count)--;
            if (*read_count == 0)
            sem_post(rw_mutex);
            sem_post(mutex);
        //} while (true);
    }

    if( pid != 0 && pid2 != 0 && pid3 != 0) {		// Main process
        wait(NULL);
    }

    sem_unlink("rwmutex");
    sem_close(rw_mutex);
    sem_unlink("mutex");
    sem_close(mutex);

}