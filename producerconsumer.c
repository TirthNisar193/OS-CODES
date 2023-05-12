#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 4
// buffer
int buffer[BUFFER_SIZE];
int buffer_index, block_p_index = -1, block_c_index = -1;
int block_p[1000], block_c[1000];
// semaphores
sem_t empty;
sem_t full;
sem_t mutex;
void insert_item(int item)
{
    buffer[buffer_index++] = item;
    printf("Producer produced item %d\n", item);
}
int remove_item()
{
    int item = buffer[--buffer_index];
    printf("Consumer consumed item %d\n", item);
    return item;
}
void *producer(void *param)
{
    int item;
    while (1)
    {
        item = rand() % 10;
        sem_wait(&empty); // decrement the empty semaphore
        while (block_p_index != -1)
        {
            sem_wait(&mutex);
            buffer[buffer_index++] = block_p[block_p_index];
            printf("Producer added item from blocked %d\n", block_p[block_p_index]); // add item to buffer
            block_p_index--;
            sem_post(&mutex);
        }
        sem_wait(&mutex);  // enter critical section
        insert_item(item); // add item to buffer
        sem_post(&mutex);  // exit critical section
        sem_post(&full);   // increment the full semaphore
        if (buffer_index == BUFFER_SIZE - 1)
        {
            printf("Buffer full.Process blocked\n");
            block_p_index++;
            block_p[block_p_index] = item;
        }
        // sleep for a random amount of time
        sleep(rand() % 4);
    }
}
void *consumer(void *param)
{
    int item;
    while (1)
    {
        sem_wait(&full); // decrement the full semaphore
        /*while(block_c_index!=-1)
        {
            if(buffer[buffer_index]==block_c[block_c_index])
            {
                sem_wait(&mutex);
                int item = buffer[--buffer_index];
                printf("Consumer consumed item from blocked %d\n", block_c[block_c_index]);// remove item from buffer
                block_c_index--;
                sem_post(&mutex);
            }

        }*/
        sem_wait(&mutex);     // enter critical section
        item = remove_item(); // remove item from buffer
        sem_post(&mutex);     // exit critical section
        sem_post(&empty);     // increment the empty semaphore
        /*if(buffer_index==0)
        {
            printf("Buffer empty.Process blocked\n");
            block_c_index++;
            block_c[block_c_index] = item;
        }*/
        // sleep for a random amount of time
        sleep(rand() % 4);
    }
}
int main(int argc, char *argv[])
{
    // initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    // initialize buffer
    buffer_index = 0;
    // create threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    // wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    // destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}