#include <stdio.h>
#include <string.h>

int main() {
    char dir[10][20];
    int n = 0, choice;
    char fname[20];

    while (1) {
        printf("\n1.Add File\n2.Search File\n3.Display\n4.Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter filename: ");
            scanf("%s", dir[n++]);
        }
        else if (choice == 2) {
            printf("Enter file to search: ");
            scanf("%s", fname);
            int found = 0;
            for (int i = 0; i < n; i++)
                if (!strcmp(dir[i], fname)) { found = 1; break; }
            printf(found ? "File Found\n" : "Not Found\n");
        }
        else if (choice == 3) {
            printf("Files:\n");
            for (int i = 0; i < n; i++) printf("%s\n", dir[i]);
        }
        else break;
    }
}

