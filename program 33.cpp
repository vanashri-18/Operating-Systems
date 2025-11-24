/* optimal_paging.c */
#include <stdio.h>

int findOptimal(int frames[], int fcount, int pages[], int len, int idx){
    int res = -1, farthest = idx;
    for(int i=0;i<fcount;i++){
        int j;
        for(j=idx;j<len;j++) if(frames[i]==pages[j]) break;
        if(j==len) return i;
        if(j>farthest){ farthest=j; res=i; }
    }
    return res==-1?0:res;
}

int main(){
    int f; printf("Frames: "); scanf("%d",&f);
    int pages[100], len=0;
    printf("Enter pages -1 to end:\n");
    while(1){ int x; scanf("%d",&x); if(x==-1) break; pages[len++]=x; }
    int frames[f]; for(int i=0;i<f;i++) frames[i]=-1;
    int faults=0;
    for(int i=0;i<len;i++){
        int found=0;
        for(int j=0;j<f;j++) if(frames[j]==pages[i]){ found=1; break; }
        if(!found){
            faults++;
            int placed=0;
            for(int j=0;j<f;j++) if(frames[j]==-1){ frames[j]=pages[i]; placed=1; break;}
            if(!placed){
                int idx = findOptimal(frames,f,pages,len,i+1);
                frames[idx]=pages[i];
            }
        }
    }
    printf("Page faults = %d\n", faults);
    return 0;
}

