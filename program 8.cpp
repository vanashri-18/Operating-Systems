#include <stdio.h>

struct Process {
    int pid;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
};

int main() {
    int n, tq, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (p[i].remaining > tq) {
                    time += tq;
                    p[i].remaining -= tq;
                } else {
                    time += p[i].remaining;
                    p[i].waiting = time - p[i].burst;
                    p[i].turnaround = time;
                    p[i].remaining = 0;
                    completed++;
                }
            }
        }
    }

    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].burst, p[i].waiting, p[i].turnaround);
    }

    return 0;
}

