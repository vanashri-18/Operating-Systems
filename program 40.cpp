#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void print_permissions(mode_t mode) {

    printf("File Type: ");
    if (S_ISREG(mode)) printf("Regular File\n");
    else if (S_ISDIR(mode)) printf("Directory\n");
    else printf("Other\n");

    printf("\nPermissions:\n");

    // Owner permissions
    printf("Owner: ");
    printf( (mode & S_IRUSR) ? "r" : "-");
    printf( (mode & S_IWUSR) ? "w" : "-");
    printf( (mode & S_IXUSR) ? "x" : "-");
    printf("\n");

    // Group permissions
    printf("Group: ");
    printf( (mode & S_IRGRP) ? "r" : "-");
    printf( (mode & S_IWGRP) ? "w" : "-");
    printf( (mode & S_IXGRP) ? "x" : "-");
    printf("\n");

    // Others permissions
    printf("Others: ");
    printf( (mode & S_IROTH) ? "r" : "-");
    printf( (mode & S_IWOTH) ? "w" : "-");
    printf( (mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main() {
    char filename[100];
    struct stat fileStat;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) < 0) {
        printf("Error: File not found!\n");
        return 1;
    }

    printf("\n=== FILE ACCESS DETAILS ===\n");

    printf("Owner UID: %d\n", fileStat.st_uid);
    printf("Group GID: %d\n\n", fileStat.st_gid);

    print_permissions(fileStat.st_mode);

    return 0;
}

