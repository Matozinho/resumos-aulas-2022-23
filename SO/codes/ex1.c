#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t f1, f2, f3;

  printf("Processo pai %d\n", getpid());
  f1 = fork();

  // caso processo filho
  if (!f1)
  {
    printf("Processo filho - pid: %d | pai: %d\n", getpid(), getppid());
    f2 = fork();

    if (!f2)
    {
      printf("Processo filho - pid: %d | pai: %d\n", getpid(), getppid());
      f3 = fork();

      if (!f3)
      {
        printf("Processo filho - pid: %d | pai: %d\n", getpid(), getppid());
      }
    }
    return 0;
  }

  sleep(10);
  printf("Final da execução\n");

  return 0;
}