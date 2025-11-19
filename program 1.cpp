#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        printf("\n--- CHILD PROCESS ---\n");
        printf("Child PID      : %d\n", getpid());
        printf("Parent PID     : %d\n", getppid());
    }
    else {
        printf("\n--- PARENT PROCESS ---\n");
        printf("Parent PID     : %d\n", getpid());
        printf("Child PID      : %d\n", pid);
    }
    return 0;
}

