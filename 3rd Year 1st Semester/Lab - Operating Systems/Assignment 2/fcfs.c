#include <stdlib.h>
#include <stdio.h>
#include "jobdef.h"

Job *job_arr;

int count_jobs(FILE *fp)
{
    int c = 0;
    int d = 0;
    while(!feof(fp))
    {
        fscanf(fp, "%d", &d);
        if(d == -1) 
        {
            c++;
        }
    }
    return(c);
}

int extract(FILE *fp)
{
    int n = count_jobs(fp);
    Job arr_job[n];
    
}

int main(int argc, char argv[]) 
{
    FILE *fp;
    fp=fopen("files/profile.txt","r");
    int n = count_jobs(fp);
    fclose(fp);
    printf("Number of jobs: %d\n", n);
    return(0);
}