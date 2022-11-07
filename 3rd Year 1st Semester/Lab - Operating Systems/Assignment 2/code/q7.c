#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int n;          // no. of processes
    int m;          // no. of resource types

    int flag, p, count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int available[m];
    int max[n][m];
    int allocation[n][m];
    int need[n][m];
    int request[m];

    bool finish[n];

    printf("Enter the max matrix:");
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the available matrix:");
    for(int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the request matrix: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &request[i]);
    }
     
    for(int i = 0; i < n; i++) {
        finish[i] = false;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j< m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    do {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == false) {
                p = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        p = 1;
                        break;
                    }
                }
                if (p == 0){
                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    flag = 1;
                }
            }
        }
        count++;
    } while (flag != 0 && count < n);
    if (count < n){
        printf("The system is in safe state.\n");
    }
    else {  // Traversed through all processes
        printf("The system is in unsafe state.\n");
    }
}