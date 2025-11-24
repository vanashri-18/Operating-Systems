/* contiguous_alloc.c */
#include <stdio.h>
#include <string.h>

int main(){
    int diskSize=1000; char disk[1000];
    // Simulate files as continuous blocks by storing start index and length
    typedef struct { char name[20]; int start, len; } File;
    File files[10];
    int fileCount=0;
    // Create a file
    strcpy(files[fileCount].name, "file1");
    files[fileCount].start = 0;
    files[fileCount].len = 5; // 5 records
    fileCount++;
    // Access record i (1-based)
    int rec = 4;
    printf("To access record %d of file1, must read %d preceding records then record %d\n", rec, rec-1, rec);
    printf("Simulated operation: reading records 1..%d\n", rec);
    return 0;
}

