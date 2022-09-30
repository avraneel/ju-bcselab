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

// main: pidx != 0, pidy != 0, pidz != 0 
// Child X: pidx == 0
// Child Y: pidx != 0, pidy == 0
// Child Z: pidx != 0, pidy != 0, pidz == 0

sem_t *S;
sem_t *Q;
sem_t *T;

int main(int argc, char* argv[]) {

    int pidx, pidy, pidz;
    
    S = sem_open("mysem", O_CREAT | O_EXCL, 0644, 1);
    Q = sem_open("mysem2", O_CREAT | O_EXCL, 0644, 0);
    T = sem_open("mysem3", O_CREAT | O_EXCL, 0644, 0);
    
    printf("Child X created.\n");
    pidx = fork();   		// creating child process X
    if(pidx != 0) {
    	printf("Child Y created.\n");
        pidy = fork();  	// creating child y
    }
    if(pidx != 0 && pidy != 0) {
    	printf("Child Z created.\n");
    	pidz = fork();		// creating child y
    }
    if(pidx == 0) {				// Child X
        for(int i = 0; i < 10; i++) {
            sem_wait(S);
            printf("Child X. Iteration no.: %d\n", i+1);
            srand(time(NULL)^getpid());
            sleep(rand() % 5);
            sem_post(Q);
        }
    }
    if(pidx != 0 && pidy == 0) {		// Child Y
        for(int i = 0; i < 10; i++) {
            sem_wait(Q);
            printf("Child Y. Iteration no.: %d\n", i+1);
            srand(time(NULL)^getpid());
            sleep(rand() % 5);
            sem_post(T);
        }
    }
    if(pidx != 0 && pidy != 0 && pidz == 0) {		// Child Z
        for(int i = 0; i < 10; i++) {
            sem_wait(T);
            printf("Child Z. Iteration no.: %d\n", i+1);
            srand(time(NULL)^getpid());
            sleep(rand() % 5);
            sem_post(S);
        }
    }
    if( pidx != 0 && pidy != 0 && pidz != 0) {		// Main process
        wait(NULL);
    }
    sem_unlink("mysem");
    sem_close(S);
    sem_unlink("mysem2");
    sem_close(Q);
    sem_unlink("mysem3");
    sem_close(T);
    return 0;
}
