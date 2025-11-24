/* best_fit.c */
#include <stdio.h>
int main(){
    int m,n; printf("Blocks: "); scanf("%d",&m);
    int blocks[m]; for(int i=0;i<m;i++) scanf("%d",&blocks[i]);
    printf("Processes: "); scanf("%d",&n);
    int proc[n]; for(int i=0;i<n;i++) scanf("%d",&proc[i]);
    int alloc[n]; for(int i=0;i<n;i++) alloc[i]=-1;

    for(int i=0;i<n;i++){
        int bestIdx=-1, bestSize=1<<30;
        for(int j=0;j<m;j++){
            if(blocks[j] >= proc[i] && blocks[j] < bestSize){
                bestSize = blocks[j]; bestIdx = j;
            }
        }
        if(bestIdx!=-1){ alloc[i]=bestIdx; blocks[bestIdx]-=proc[i]; }
    }

    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++) printf("%d\t%d\t%s\n", i+1, proc[i], (alloc[i]==-1)?"Not Allocated":(char[]){0});
    for(int i=0;i<n;i++){
        if(alloc[i]==-1) printf("%d\t%d\tNot Allocated\n", i+1, proc[i]);
        else printf("%d\t%d\t%d\n", i+1, proc[i], alloc[i]+1);
    }
    return 0;
}

