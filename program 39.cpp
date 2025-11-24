#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, i, j, disk_size;
    int left[20], right[20], l = 0, r = 0;
    int total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    for(i = 0; i < n; i++) {
        if(req[i] >= head) 
            right[r++] = req[i];
        else 
            left[l++] = req[i];
    }

    // Sort left[] and right[]
    for(i = 0; i < r-1; i++)
        for(j = i+1; j < r; j++)
            if(right[i] > right[j]) {
                int temp = right[i]; 
                right[i] = right[j]; 
                right[j] = temp;
            }

    for(i = 0; i < l-1; i++)
        for(j = i+1; j < l; j++)
            if(left[i] > left[j]) {
                int temp = left[i]; 
                left[i] = left[j]; 
                left[j] = temp;
            }

    printf("\nOrder of service (C-SCAN):\n");

    // First serve right[]
    for(i = 0; i < r; i++) {
        total += abs(head - right[i]);
        head = right[i];
        printf("%d ", head);
    }

    // Move to end and jump to 0
    total += abs(head - (disk_size - 1));
    head = 0;
    total += disk_size - 1;    

    // Serve left[]
    for(i = 0; i < l; i++) {
        total += abs(head - left[i]);
        head = left[i];
        printf("%d ", head);
    }

    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}

