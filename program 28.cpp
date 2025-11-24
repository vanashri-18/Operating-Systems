/* mygrep.c */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc<3){ printf("Usage: %s pattern file\n", argv[0]); return 1; }
    char *pattern = argv[1];
    FILE *f = fopen(argv[2],"r");
    char line[1024]; int ln=1;
    while(fgets(line,sizeof(line),f)){
        if(strstr(line, pattern)) printf("%d: %s", ln, line);
        ln++;
    }
    fclose(f);
    return 0;
}

