#include <stdio.h>
#include <pthread.h>
void *print_message(void *arg) {
    printf("%s\n", (char *)arg);
    return NULL;
}
int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print_message, "Hello from Thread 1!");
    pthread_create(&thread2, NULL, print_message, "Hello from Thread 2!");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
