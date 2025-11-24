/* scan_disk.c */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, start, diskSize, dir;
    printf("Number of requests: "); scanf("%d",&n);
    int r[n]; for(int i=0;i<n;i++) scanf("%d",&r[i]);
    printf("Start head: "); scanf("%d",&start);
    printf("Disk size (max track number): "); scanf("%d",&diskSize);
    printf("Direction (0=left,1=right): "); scanf("%d",&dir);

    int left[n], right[n], l=0, rt=0;
    for(int i=0;i<n;i++){
        if(r[i] < start) left[l++]=r[i]; else right[rt++]=r[i];
    }
    // sort left descending, right ascending
    for(int i=0;i<l;i++) for(int j=i+1;j<l;j++) if(left[i]<left[j]) { int t=left[i]; left[i]=left[j]; left[j]=t; }
    for(int i=0;i<rt;i++) for(int j=i+1;j<rt;j++) if(right[i]>right[j]) { int t=right[i]; right[i]=right[j]; right[j]=t; }

    int total=0, cur=start;
    if(dir==1){
        for(int i=0;i<rt;i++){ total+=abs(right[i]-cur); cur=right[i]; }
        total += abs(diskSize-1 - cur); cur = diskSize-1;
        for(int i=0;i<l;i++){ total += abs(cur-left[i]); cur = left[i]; }
    } else {
        for(int i=0;i<l;i++){ total+=abs(cur-left[i]); cur=left[i]; }
        total += abs(cur - 0); cur = 0;
        for(int i=0;i<rt;i++){ total += abs(right[i]-cur); cur=right[i]; }
    }
    printf("Total head movement = %d\n", total);
    return 0;
}

