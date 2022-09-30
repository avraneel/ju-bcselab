#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#define LISTENER_NO 4

int main(int argc, char* argv[]) {
    int x = 23;
    int fd = open("files/fifo", O_WRONLY); 
    if(fd == -1) {
        return 1;
    }
    printf("Opened fifo by writer.\n");
    if(write(fd, &x, sizeof(int)) == -1) {
        return 2;
    }
    printf("Writing completed.\n");
    close(fd);
    printf("Closed writer.\n");
    return 0;
}