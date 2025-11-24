/* bankers.c */
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int available[m];
    printf("Enter available resources (%d):\n", m);
    for(int i=0;i<m;i++) scanf("%d",&available[i]);

    int alloc[n][m], max[n][m], need[n][m];
    printf("Enter allocated matrix (n x m):\n");
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    printf("Enter max matrix (n x m):\n");
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&max[i][j]);

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        need[i][j] = max[i][j] - alloc[i][j];

    bool finish[n];
    for(int i=0;i<n;i++) finish[i]=false;
    int safeSeq[n], idx=0;
    int work[m];
    for(int i=0;i<m;i++) work[i]=available[i];

    for(int count=0; count<n; count++) {
      bool found=false;
      for(int p=0;p<n;p++) {
        if(finish[p]) continue;
        bool ok=true;
        for(int j=0;j<m;j++)
          if(need[p][j] > work[j]) { ok=false; break; }
        if(ok) {
          for(int j=0;j<m;j++) work[j]+=alloc[p][j];
          safeSeq[idx++]=p;
          finish[p]=true;
          found=true;
        }
      }
      if(!found) break;
    }

    bool safe=true;
    for(int i=0;i<n;i++) if(!finish[i]) safe=false;

    if(safe) {
      printf("System is in SAFE state.\nSafe sequence: ");
      for(int i=0;i<n;i++) printf("P%d ", safeSeq[i]);
      printf("\n");
    } else {
      printf("System is NOT in safe state. Deadlock possible.\n");
    }
    return 0;
}

