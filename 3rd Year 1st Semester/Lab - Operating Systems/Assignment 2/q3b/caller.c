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

    mkfifo("fifo3b", 0777);

    int fd = open("fifo3b", O_WRONLY);

    char str[100];

    while(1) {

        printf("Input a string. Enter q to quit: ");
        fgets(str, 100, stdin);
        
        if(write(fd, str, sizeof(char)*100) == -1)
            return 1;
        
        if(strcmp(str, "q\n") == 0)
            break;
        printf("Sent to reciever.\n");
    }
    
    printf("Closing sender.\n");
    close(fd);
    return 0;
}