/* myls.c */
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    while((e=readdir(d))!=NULL){
        struct stat st;
        stat(e->d_name, &st);
        printf("%10ld %s\n", st.st_size, e->d_name);
    }
    closedir(d);
    return 0;
}

