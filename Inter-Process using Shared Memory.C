#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    key_t key = ftok("progfile", 65);   
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 
    char *str = (char*) shmat(shmid, NULL, 0); 
    if (fork() == 0) { 
        sleep(2);  
        printf("Consumer received: %s\n", str);  
        shmdt(str); 
    } else { 
        strcpy(str, "Hello from producer!");  
        printf("Producer wrote: %s\n", str);
        wait(NULL);  
        shmctl(shmid, IPC_RMID, NULL);  
    }
    return 0;
}
