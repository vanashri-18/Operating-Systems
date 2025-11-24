/* lru_paging.c */
#include <stdio.h>

int main(){
    int n; printf("Frames: "); scanf("%d",&n);
    int pages[100], len=0;
    printf("Enter page sequence -1 to end:\n");
    while(1){ int x; scanf("%d",&x); if(x==-1) break; pages[len++]=x; }

    int frames[n]; for(int i=0;i<n;i++) frames[i]=-1;
    int faults=0;
    for(int i=0;i<len;i++){
        int found=0;
        for(int j=0;j<n;j++) if(frames[j]==pages[i]){ found=1; break; }
        if(!found){
            faults++;
            // find LRU index
            int used[n]; for(int k=0;k<n;k++){ used[k]= -1; for(int t=i-1;t>=0;t--) if(frames[k]==pages[t]){ used[k]=i-t; break;} }
            int maxIdx=0, maxVal=-1;
            for(int k=0;k<n;k++){
                if(frames[k]==-1){ maxIdx=k; maxVal=1<<30; break; }
                if(used[k] > maxVal){ maxVal = used[k]; maxIdx = k; }
            }
            frames[maxIdx]=pages[i];
        }
    }
    printf("Page faults = %d\n", faults);
    return 0;
}

