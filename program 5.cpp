#include <stdio.h>

struct Process {
    int pid;
    int priority;
    int burst; 
    int waiting;   
    int turnaround; 
};
int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    printf("\nEnter burst time and priority for each process\n");
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);

        printf("Process %d Priority: ", i + 1);
        scanf("%d", &p[i].priority);

        printf("\n");
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    p[0].waiting = 0;
    for(i = 1; i < n; i++) {
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
    }
    for(i = 0; i < n; i++) {
        p[i].turnaround = p[i].waiting + p[i].burst;
    }
    printf("\nPriority Scheduling Result:\n");
    printf("PID\tPriority\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].priority,
            p[i].burst,
            p[i].waiting,
            p[i].turnaround);
    }
    return 0;
}

