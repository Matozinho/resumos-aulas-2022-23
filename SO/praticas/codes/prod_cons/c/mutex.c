#include <pthread.h>
#include <stdio.h>
#include <linux/unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *thread_function()
{
  int tid;
  int amount = 20;

  tid = syscall(SYS_gettid);

  pthread_mutex_lock(&mutex);
  for (int i = 0; i < amount; i++)
  {
    printf("[%d]: %d\n", tid, i);
    fflush(stdout);
    usleep(10);
  }
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main()
{
  int tid;
  pthread_t p1, p2;
  pthread_create(&p1, NULL, &thread_function, NULL);
  pthread_create(&p2, NULL, &thread_function, NULL);

  // tid = syscall(SYS_gettid);
  // printf("[%d | %ld]\n", tid, syscall(SYS_getpid));
  // fflush(stdout);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  return 0;
}