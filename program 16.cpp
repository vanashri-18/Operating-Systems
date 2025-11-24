#include <stdio.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;

    fp = fopen("emp.dat", "wb+");

    struct Employee list[3] = {
        {1, "Arun", 35000},
        {2, "Priya", 42000},
        {3, "Kumar", 39000}
    };

    for (int i = 0; i < 3; i++)
        fwrite(&list[i], sizeof(e), 1, fp);

    int rec;
    printf("Enter record number to read (1-3): ");
    scanf("%d", &rec);

    fseek(fp, (rec - 1) * sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee ID: %d\nName: %s\nSalary: %.2f\n",
           e.id, e.name, e.salary);

    fclose(fp);
    return 0;
}

