/* unix_calls_demo.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
    // stat
    struct stat st;
    if(stat(".", &st)==0) printf("Current dir inode: %ld\n", st.st_ino);

    // open & fcntl
    int fd = open("demo.txt", O_CREAT|O_WRONLY, 0644);
    if(fd<0){ perror("open"); return 1; }
    fcntl(fd, F_SETFD, FD_CLOEXEC);
    write(fd, "demo\n", 5);
    close(fd);

    // lseek
    fd = open("demo.txt", O_RDONLY);
    lseek(fd, 0, SEEK_END);
    off_t size = lseek(fd, 0, SEEK_CUR);
    printf("demo.txt size: %ld\n", (long)size);
    close(fd);

    // opendir & readdir
    DIR *d = opendir(".");
    struct dirent *entry;
    printf("Directory listing:\n");
    while((entry = readdir(d))!=NULL) printf(" %s\n", entry->d_name);
    closedir(d);

    unlink("demo.txt");
    return 0;
}

