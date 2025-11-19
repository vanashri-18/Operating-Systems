#include <stdio.h>

struct Process {
    int pid;
    int burst;
    int remaining;
    int priority;
    int arrival;
    int waiting;
    int turnaround;
    int completion;
};

int main() {
    int n, i, t = 0, completed = 0;
    float total_wait = 0, total_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time, Arrival Time & Priority of Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].burst, &p[i].arrival, &p[i].priority);
        p[i].remaining = p[i].burst;
    }

    while (completed < n) {
        int idx = -1, highest_priority = 9999;

        for (i = 0; i < n; i++) {
            if (p[i].arrival <= t && p[i].remaining > 0 && p[i].priority < highest_priority) {
                highest_priority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining--;

            if (p[idx].remaining == 0) {
                p[idx].completion = t + 1;
                completed++;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_wait += p[idx].waiting;
                total_tat += p[idx].turnaround;
            }
        }
        t++;
    }

    printf("\nPreemptive Priority Scheduling Result:\n");
    printf("PID\tAT\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority,
               p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

