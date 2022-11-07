#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {

    int a[5];
    int l;

    int fd = open("fifo3b", O_RDONLY);
        
     for(int i = 0; i< 5; i++) {
        read(fd, &a[i], sizeof(int));
        printf("Received %d.\n", a[i]);
    }
    
    printf("Closing receiver.\n");
    close(fd);
    return 0;
}