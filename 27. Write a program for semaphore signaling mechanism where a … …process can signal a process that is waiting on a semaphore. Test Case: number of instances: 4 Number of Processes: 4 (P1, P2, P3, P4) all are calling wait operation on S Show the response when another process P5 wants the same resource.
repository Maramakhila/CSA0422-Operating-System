#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
sem_t sem;
void *process_A(void *arg)
{
    sem_post(&sem);
    printf("Process A signaled semaphore\n");
    return NULL;
}
void *process_B(void *arg)
{
    sem_wait(&sem);
    printf("Process B received signal from semaphore\n");
    return NULL;
}
int main(void)
{
    sem_init(&sem, 0, 0);
    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, process_A, NULL);
    pthread_create(&threadB, NULL, process_B, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    sem_destroy(&sem);
    return 0;
}
