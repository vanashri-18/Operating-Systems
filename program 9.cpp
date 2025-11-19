#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMapFile;
    LPCTSTR shared_memory;

    // Create shared memory
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,   // use RAM
        NULL,                   
        PAGE_READWRITE,         
        0,                      
        1024,                  
        TEXT("MySharedMemory")  // name of shared memory
    );

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    // Map to memory
    shared_memory = (LPTSTR) MapViewOfFile(
        hMapFile,               
        FILE_MAP_ALL_ACCESS,    
        0,
        0,
        1024
    );

    if (shared_memory == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    // Parent process writes
    printf("Parent writing to shared memory...\n");
    CopyMemory((PVOID)shared_memory, "Hello from Shared Memory!", 26);

    // Create a child process to read the shared memory
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Launch another instance of this program with argument "child"
    if (!CreateProcess(
            NULL,
            "program.exe child",  // <-- change program.exe to your actual .exe filename
            NULL, NULL, FALSE,
            0, NULL, NULL,
            &si, &pi))
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
    } else {
        WaitForSingleObject(pi.hProcess, INFINITE);
    }

    // Close shared memory
    UnmapViewOfFile(shared_memory);
    CloseHandle(hMapFile);

    return 0;
}

