/* dining.c */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
sem_t forks[N];

void* philosopher(void* arg){
    int id = *(int*)arg;
    while(1){
        // thinking
        printf("Philosopher %d thinking\n", id);
        sleep(1);
        // pick forks (odd take left first, even take right first) to avoid deadlock
        if(id%2==0){ sem_wait(&forks[id]); sem_wait(&forks[(id+1)%N]); }
        else { sem_wait(&forks[(id+1)%N]); sem_wait(&forks[id]); }

        printf("Philosopher %d eating\n", id);
        sleep(1);

        sem_post(&forks[id]); sem_post(&forks[(id+1)%N]);
    }
    return NULL;
}

int main(){
    pthread_t t[N];
    int ids[N];
    for(int i=0;i<N;i++) sem_init(&forks[i],0,1);
    for(int i=0;i<N;i++){ ids[i]=i; pthread_create(&t[i],NULL,philosopher,&ids[i]); }
    for(int i=0;i<N;i++) pthread_join(t[i],NULL);
    return 0;
}

