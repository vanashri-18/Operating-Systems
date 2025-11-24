/* linked_alloc.c */
#include <stdio.h>

int main(){
    // simulate disk blocks with next pointers
    int next[100]; for(int i=0;i<100;i++) next[i] = -1;
    // file blocks chain: 7 -> 20 -> 45 -> -1
    next[7]=20; next[20]=45; next[45]=-1;
    int head = 7;
    printf("Traverse file blocks:\n");
    int cur = head;
    while(cur!=-1){
        printf("Block %d\n", cur);
        cur = next[cur];
    }
    return 0;
}

