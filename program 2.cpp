#include <stdio.h>
#include <fcntl.h>     
#include <unistd.h>     
#include <stdlib.h>

int main() {
    int source, dest;
    char buffer[1024];
    ssize_t bytes;

    source = open("input.txt", O_RDONLY);
    if (source < 0) {
        perror("open source");
        return 1;
    }

    dest = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("open dest");
        close(source);
        return 1;
    }

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        ssize_t written = 0;
        while (written < bytes) {
            ssize_t w = write(dest, buffer + written, bytes - written);
            if (w < 0) {
                perror("write");
                close(source);
                close(dest);
                return 1;
            }
            written += w;
        }
    }
    if (bytes < 0) perror("read");

    close(source);
    close(dest);

    printf("File copied successfully using system calls.\n");
    return 0;
}

