#include <stdio.h>
#include <windows.h>

#define N 5
HANDLE forks[N];

DWORD WINAPI philosopher(void *num) {
    int id = (int)(DWORD_PTR)num;

    WaitForSingleObject(forks[id], INFINITE);
    WaitForSingleObject(forks[(id + 1) % N], INFINITE);

    printf("Philosopher %d is eating.\n", id);

    ReleaseMutex(forks[id]);
    ReleaseMutex(forks[(id + 1) % N]);

    printf("Philosopher %d finished eating.\n", id);

    return 0;
}

int main() {
    HANDLE ph[N];

    for (int i = 0; i < N; i++)
        forks[i] = CreateMutex(NULL, FALSE, NULL);

    for (int i = 0; i < N; i++)
        ph[i] = CreateThread(NULL, 0, philosopher, (LPVOID)(DWORD_PTR)i, 0, NULL);

    WaitForMultipleObjects(N, ph, TRUE, INFINITE);

    printf("All philosophers finished.\n");
    return 0;
}

