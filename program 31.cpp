/* fifo_paging.c */
#include <stdio.h>

int main(){
    int n;
    printf("Frames: "); scanf("%d",&n);
    int pages[100], len=0;
    printf("Enter page reference sequence, -1 to end:\n");
    while(1){ int x; scanf("%d",&x); if(x==-1) break; pages[len++]=x; }

    int frames[n]; for(int i=0;i<n;i++) frames[i]=-1;
    int front=0, faults=0;
    for(int i=0;i<len;i++){
        int found=0;
        for(int j=0;j<n;j++) if(frames[j]==pages[i]) { found=1; break; }
        if(!found){ frames[front]=pages[i]; front=(front+1)%n; faults++; }
    }
    printf("Page faults = %d\n", faults);
    return 0;
}

