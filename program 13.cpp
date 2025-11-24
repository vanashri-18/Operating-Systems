#include <stdio.h>

void allocate(int block[], int m, int process[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }

    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%s\n", i + 1, process[i],
               allocation[i] == -1 ? "Not Allocated" : "Allocated");
}

int main() {
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};

    allocate(block, 5, process, 4);
    return 0;
}

