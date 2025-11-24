/* worst_fit.c */
#include <stdio.h>

int main(){
    int m, n;
    printf("Number of memory blocks: ");
    scanf("%d",&m);
    int blocks[m];
    printf("Enter block sizes:\n"); for(int i=0;i<m;i++) scanf("%d",&blocks[i]);

    printf("Number of processes: ");
    scanf("%d",&n);
    int proc[n]; for(int i=0;i<n;i++) { printf("Process %d size: ", i+1); scanf("%d",&proc[i]); }

    int alloc[n]; for(int i=0;i<n;i++) alloc[i] = -1;

    for(int i=0;i<n;i++){
        int idx = -1; int worst = -1;
        for(int j=0;j<m;j++){
            if(blocks[j] >= proc[i] && blocks[j] > worst){
                worst = blocks[j]; idx = j;
            }
        }
        if(idx != -1){
            alloc[i] = idx;
            blocks[idx] -= proc[i];
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t", i+1, proc[i]);
        if(alloc[i]!=-1) printf("%d\n", alloc[i]+1); else printf("Not Allocated\n");
    }
    return 0;
}

