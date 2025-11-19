#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE pipe;
    char message[] = "Hello from Windows IPC!";
    DWORD bytesWritten;
    pipe = CreateNamedPipe(
        TEXT("\\\\.\\pipe\\MyPipe"),
        PIPE_ACCESS_OUTBOUND,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1, 
        1024, 
        1024, 
        0,
        NULL
    );
    if (pipe == INVALID_HANDLE_VALUE) {
        printf("Error creating pipe (%d)\n", GetLastError());
        return 1;
    }
    printf("Waiting for client to connect...\n");
    ConnectNamedPipe(pipe, NULL);
    WriteFile(pipe, message, sizeof(message), &bytesWritten, NULL);
    printf("Message sent: %s\n", message);

    CloseHandle(pipe);
    return 0;
}

