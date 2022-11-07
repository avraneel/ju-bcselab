#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]) {

    mkfifo("fifo3b", 0777);

    int fd = open("fifo3b", O_WRONLY);
    srand(time(NULL));

    int a[5];

    for(int i = 0; i< 5; i++) {
        a[i] = rand() % 100;
    }

    for(int i = 0; i< 5; i++) {
        write(fd, &a[i], sizeof(int));
        printf("Wrote %d.\n", a[i]);
    }
    
    printf("Closing sender.\n");
    close(fd);
    return 0;
}