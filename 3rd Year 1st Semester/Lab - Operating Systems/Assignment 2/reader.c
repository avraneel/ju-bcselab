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
    int x;
    int fd = open("files/fifo", O_RDONLY); 
    if(fd == -1) {
        return 1;
    }
    printf("Opened fifo by reader./n");
    if(read(fd, &x, sizeof(int)) == -1) {
        return 2;
    }
    printf("Received %d.\n", x);
    close(fd);
    printf("Closed.\n");
    return 0;
}