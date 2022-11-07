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

// main: pidx != 0, pidy != 0 
// Child X: pidx == 0
// Child Y: pidx != 0, pidy == 0

sem_t *S;
sem_t *Q;

int main(int argc, char* argv[]) {

    int pidx, pidy;
    srand(time(NULL));
    
    S = sem_open("mysem", O_CREAT | O_EXCL, 0644, 1);
    Q = sem_open("mysem2", O_CREAT | O_EXCL, 0644, 0);

    pidx = fork();   		// creating child process X
    if(pidx != 0) {
        pidy = fork();  	// creating child y
    }
    if(pidx == 0) {				// Child X
        for(int i = 0; i < 10; i++) {
            sem_wait(S);
            printf("Child X. Iteration no.: %d\n", i+1);
            sleep(rand() % 2);
            sem_post(Q);
        }
    }
    if(pidx != 0 && pidy == 0) {		// Child Y
        for(int i = 0; i < 10; i++) {
            sem_wait(Q);
            printf("Child Y. Iteration no.: %d\n", i+1);
            sleep(rand() % 2);
            sem_post(S);
        }
    }
    if( pidx != 0 && pidy != 0) {		// Main process
        wait(NULL);
    }
    sem_unlink("mysem");
    sem_close(S);
    sem_unlink("mysem2");
    sem_close(Q);
    return 0;
}
