#include <pthread.h>
#include <stdio.h>
#include <linux/unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
  char *message;
  int amount;
} ThreadsParams;

typedef struct
{
  int amount;
} ThreadsReturn;

void *thread_function1(void *arguments)
{
  ThreadsParams *params = (ThreadsParams *)arguments;
  int tid;
  int *i = (int *)malloc(sizeof(int));

  tid = syscall(SYS_gettid);

  for (*i = 0; *i < params->amount; *i++)
  {
    printf("%s [%d]: %d\n", params->message, tid, *i);
    fflush(stdout);
  }

  return (void *)i;
}

void *thread_function2(void *arguments)
{
  ThreadsParams *params = (ThreadsParams *)arguments;
  int tid;
  int *i = (int *)malloc(sizeof(int));

  tid = syscall(SYS_gettid);

  for (*i = 0; *i < params->amount; i++)
  {
    printf("%s [%d]: %d\n", params->message, tid, *i);
    fflush(stdout);
  }

  return ((void *)i);
}

int main()
{
  int tid;
  pthread_t p1, p2;
  ThreadsParams params1 = {"Thread 1", 10};
  ThreadsParams params2 = {"THread 2", 5};

  int *return1;
  int *return2;

  pthread_create(&p1, NULL, &thread_function1, (void *)&params1);
  pthread_create(&p2, NULL, &thread_function2, (void *)&params2);

  tid = syscall(SYS_gettid);
  printf("[%d | %ld]\n", tid, syscall(SYS_getpid));
  fflush(stdout);

  pthread_join(p1, (void *)return1);
  pthread_join(p2, (void *)return2);

  printf("Return 1: %d\n", *return1);
  printf("Return 2: %d\n", *return2);
  return 0;
}