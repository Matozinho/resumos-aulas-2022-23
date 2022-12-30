#include <pthread.h>
#include <stdio.h>
#include <threads.h>

#define N 5
int buffer[N];
int amount = 1000;
volatile int count;

void *produtor()
{
  int in = 0;
  for (int i = 0; i < amount; i++)
  {
    while (count == N)
      ;
    buffer[in] = i;
    in = (in + 1) % N;
    // printf("Produziu %d\n", i);
    count++;
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
    // printf("Consumiu %d\n", d_out);
    count--;
  }
}

int main()
{
  pthread_t t1, t2;
  pthread_create(&t1, NULL, &produtor, NULL);
  pthread_create(&t2, NULL, &consumidor, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("fim do produtor consumidor\n");
}