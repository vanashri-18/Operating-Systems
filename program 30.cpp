/* thread_demo.c */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* fn(void* arg){
    printf("Thread running id: %lu\n", pthread_self());
    pthread_exit((void*)0);
}

int main(){
    pthread_t t;
    pthread_create(&t,NULL,fn,NULL);
    void *res;
    pthread_join(t, &res);
    printf("Main thread id: %lu\n", pthread_self());
    if(pthread_equal(t, pthread_self())) printf("Equal\n"); else printf("Not equal\n");
    return 0;
}

