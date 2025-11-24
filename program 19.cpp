/* mutex_sync.c */
#include <stdio.h>
#include <pthread.h>

#define THREADS 4
#define ITER 100000

long counter = 0;
pthread_mutex_t lock;

void* inc(void* arg) {
    for(int i=0;i<ITER;i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t[THREADS];
    pthread_mutex_init(&lock,NULL);
    for(int i=0;i<THREADS;i++) pthread_create(&t[i],NULL,inc,NULL);
    for(int i=0;i<THREADS;i++) pthread_join(t[i],NULL);
    pthread_mutex_destroy(&lock);
    printf("Final counter: %ld (expected %d)\n", counter, THREADS*ITER);
    return 0;
}

