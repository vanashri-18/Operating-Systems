/* reader_writer.c */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int data = 0;
int readcount = 0;

sem_t mutex, rw;

void* reader(void* arg) {
    int id = *(int*)arg;
    sem_wait(&mutex);
    readcount++;
    if(readcount==1) sem_wait(&rw);
    sem_post(&mutex);

    printf("Reader %d reading data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if(readcount==0) sem_post(&rw);
    sem_post(&mutex);
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    sem_wait(&rw);
    data += 10;
    printf("Writer %d wrote data = %d\n", id, data);
    sleep(2);
    sem_post(&rw);
    return NULL;
}

int main() {
    pthread_t r[3], w[2];
    int idsR[3] = {1,2,3}, idsW[2] = {1,2};
    sem_init(&mutex,0,1);
    sem_init(&rw,0,1);

    pthread_create(&r[0],NULL,reader,&idsR[0]);
    pthread_create(&w[0],NULL,writer,&idsW[0]);
    pthread_create(&r[1],NULL,reader,&idsR[1]);
    pthread_create(&w[1],NULL,writer,&idsW[1]);
    pthread_create(&r[2],NULL,reader,&idsR[2]);

    for(int i=0;i<3;i++) pthread_join(r[i],NULL);
    for(int i=0;i<2;i++) pthread_join(w[i],NULL);

    sem_destroy(&mutex);
    sem_destroy(&rw);
    return 0;
}

