#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

// Hierarchy tree will be of 1 level only. 
// No grandchildren. All Children from same parent

int main(void) {

    char s[] = "Today the temperature is 32 C.";
    int l = strlen(s);

    int pid1, pid2;
    int fd1[2]; //fd1[0] = read from main, fd[1] = write to child1
    int fd2[2]; //fd1[0] = read from main, fd[1] = write to child2
    pipe(fd1);
    pid1 = fork();      // creating child 1
    if(pid1 != 0) {
        // Main process, excludes child1
        pipe(fd2);
        pid2 = fork();  // creating child 2
    }
    if(pid1 != 0 && pid2 != 0) {
        //Main process
        close(fd1[0]);
        close(fd2[0]);
        write(fd1[1], s, l);    //writing to child1
        write(fd2[1], s, l);    //writing to child2
        close(fd1[1]);
        close(fd2[1]);
    }
    if(pid1 == 0) {
        // child1 
        char x[l];
        close(fd1[1]);
        read(fd1[0], x, l);
        printf("I am child 1.\nChild 1: Today's forecast is: %s\n", x);
        close(fd1[0]);
    }
    if(pid2 == 0 && pid1 != 0) {
        //child2
        char y[l];
        close(fd2[1]);
        read(fd2[0], y, l);
        printf("I am child 2.\nChild 2: Today's forecast is: %s\n", y);
        close(fd2[0]);
    }
    return 0;
}
