#include <pthread.h>
#include <stdio.h>
#include <threads.h>
#include <semaphore.h>

#define N 5
int buffer[N];
int amount = 10000;

sem_t full;
sem_t empty;
sem_t mutex;

void *produtor()
{
  int in = 0;
  for (int i = 0; i < amount; i++)
  {
    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[in] = i;
    in = (in + 1) % N;

    sem_post(&mutex);
    sem_post(&full);
  }
}

void *consumidor()
{
  int d_out;
  int out = 0;

  for (int i = 0; i < amount; i++)
  {
    sem_wait(&full);
    sem_wait(&mutex);

    d_out = buffer[out];
    out = (out + 1) % N;

    sem_post(&mutex);
    sem_post(&empty);
  }
}

int main()
{
  pthread_t t1, t2;

  sem_init(&full, 0, 0);
  sem_init(&empty, 0, N);
  sem_init(&mutex, 0, 1);
  
  pthread_create(&t1, NULL, &produtor, NULL);
  pthread_create(&t2, NULL, &consumidor, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  sem_destroy(&full);
  sem_destroy(&empty);
  sem_destroy(&mutex);

  printf("fim do produtor consumidor\n");
}