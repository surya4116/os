#include <stdio.h>
#include <pthread.h>
#define MAX 5
pthread_mutex_t mutex;
int buffer[MAX], count = 0;
void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        if (count < MAX) {
            buffer[count++] = i;
            printf("Produced: %d\n", i);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        if (count > 0) {
            printf("Consumed: %d\n", buffer[--count]);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main() {
    pthread_t prod, cons;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
