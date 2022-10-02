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

    char str[100];
    int l;

    int fd = open("fifo3b", O_RDONLY);

    while(1) {
        
        if(read(fd, str, sizeof(char)*100) == -1)
            return 1;

        if(strcmp(str, "q\n") == 0)
            break;
        printf("Received message: %s", str);
    }
    
    printf("Closing receiver.\n");
    close(fd);
    return 0;
}