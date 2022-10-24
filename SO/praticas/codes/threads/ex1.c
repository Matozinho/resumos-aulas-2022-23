#include <pthread.h>
#include <stdio.h>
#include <linux/unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

void *thread_function(void *forAmount)
{
  int i, tid;
  // int amount = *((int *)forAmount);
  int amount = 20;

  tid = syscall(SYS_gettid);

  for (i = 0; i < amount; i++)
  {
    printf("[%d | %ld]: %d\n", tid, syscall(SYS_getpid), i);
    // usleep(10);
  }
  return NULL;
}

int main()
{
  int tid;
  pthread_t p1, p2;
  pthread_create(&p1, NULL, &thread_function, (void *)5);
  pthread_create(&p2, NULL, &thread_function, (void *)10);

  tid = syscall(SYS_gettid);
  printf("[%d | %ld]:\n", tid, syscall(SYS_getpid));

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  return 0;
}