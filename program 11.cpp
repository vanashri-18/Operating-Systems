#include <windows.h>
#include <stdio.h>

DWORD WINAPI threadFunc(LPVOID arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 5; i++)
        printf("Thread %d running...\n", id);
    return 0;
}

int main() {
    HANDLE t1, t2;
    int a = 1, b = 2;

    t1 = CreateThread(NULL, 0, threadFunc, &a, 0, NULL);
    t2 = CreateThread(NULL, 0, threadFunc, &b, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    return 0;
}

