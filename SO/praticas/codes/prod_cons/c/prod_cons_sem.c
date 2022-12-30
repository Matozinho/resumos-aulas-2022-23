#include <pthread.h>
#include <stdio.h>
#include <threads.h>
#include <semaphore.h>

#define synchronized(x, things)  \
  do                             \
  {                              \
    pthread_mutex_t *_lp = &(x); \
    pthread_mutex_lock(_lp);     \
    (things);                    \
    pthread_mutex_unlock(_lp);   \
  } while (0)

#define N 5
int buffer[N];
int amount = 10000;
volatile int count;

sem_t semId;
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *produtor()
{
  int in = 0;
  for (int i = 0; i < amount; i++)
  {
    while (count == N)
      ;
    buffer[in] = i;
    in = (in + 1) % N;

    sem_wait(&semId);
    count++;
    sem_post(&semId);
    // synchronized(mutex, (count++));
  }
}

void *consumidor()
{
  int d_out;
  int out = 0;

  for (int i = 0; i < amount; i++)
  {
    while (count == 0)
      ;
    d_out = buffer[out];
    out = (out + 1) % N;
    
    sem_wait(&semId);
    count--;
    sem_post(&semId);
    // synchronized(mutex, (count--));
  }
}

int main()
{
  pthread_t t1, t2;

  sem_init(&semId, 0, 1);
  pthread_create(&t1, NULL, &produtor, NULL);
  pthread_create(&t2, NULL, &consumidor, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  sem_destroy(&semId);

  printf("fim do produtor consumidor\n");
}