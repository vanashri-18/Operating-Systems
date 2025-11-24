/* unix_file_calls.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    if(fd<0){ perror("open"); return 1; }
    char *text = "Hello from system calls.\n";
    write(fd, text, strlen(text));
    lseek(fd, 0, SEEK_SET);
    char buf[128];
    int n = read(fd, buf, sizeof(buf)-1);
    buf[n]=0;
    printf("Read: %s", buf);
    close(fd);
    // remove file
    unlink("sample.txt");
    printf("sample.txt removed\n");
    return 0;
}

