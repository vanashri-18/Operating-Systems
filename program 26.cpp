/* file_manager.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    char name[64]; int choice;
    while(1){
        printf("\n1.Create/Write 2.Read 3.Append 4.Delete 5.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==5) break;
        printf("Filename: "); scanf("%s", name);
        if(choice==1){
            int fd = open(name, O_CREAT|O_WRONLY|O_TRUNC, 0644);
            char buf[256]; printf("Text: "); getchar(); fgets(buf,256,stdin);
            write(fd, buf, strlen(buf));
            close(fd);
        } else if(choice==2){
            int fd = open(name, O_RDONLY); char buf[512];
            int n = read(fd, buf, sizeof(buf)-1); buf[n]=0; printf("Content:\n%s\n", buf); close(fd);
        } else if(choice==3){
            int fd = open(name, O_WRONLY|O_APPEND);
            char buf[256]; printf("Text: "); getchar(); fgets(buf,256,stdin);
            write(fd, buf, strlen(buf)); close(fd);
        } else if(choice==4){
            unlink(name); printf("Deleted %s\n", name);
        }
    }
    return 0;
}

