#include <pthread.h>
#include <stdio.h>
#include <linux/unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

int i = 0;

void *thread_function(void *forAmount)
{
  int tid;
  // int amount = *((int *)forAmount);
  int amount = 100;

  tid = syscall(SYS_gettid);

  for (; i < amount; i++)
  {
    printf("[%d]: %d\n", tid, i);
    // printf("%d\n", i);
    fflush(stdout);
    // usleep(10);
  }
  return NULL;
}

int main()
{
  int tid;
  pthread_t p1, p2;
  pthread_create(&p1, NULL, &thread_function, ((void *)5));
  pthread_create(&p2, NULL, &thread_function, ((void *)10));

  tid = syscall(SYS_gettid);
  printf("[%d | %ld]\n", tid, syscall(SYS_getpid));
  fflush(stdout);

  // pthread_join(p1, NULL);
  // pthread_join(p2, NULL);
  return 0;
}