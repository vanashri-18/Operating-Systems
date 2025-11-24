/* fcfs_disk.c */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, start;
    printf("Number of requests: "); scanf("%d",&n);
    int req[n];
    printf("Requests:\n"); for(int i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Start head: "); scanf("%d",&start);
    int cur = start, total=0;
    for(int i=0;i<n;i++){ total += abs(req[i]-cur); cur = req[i]; }
    printf("Total head movement = %d\n", total);
    return 0;
}

