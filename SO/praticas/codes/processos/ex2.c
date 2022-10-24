#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t pid;
  int childs = 0;

  printf("Processo pai %d\n", getpid());

  while (childs < 2)
  {
    if (!fork())
      childs++;

    printf("process %d | parent: %d\n", getpid(), getppid());
  }

  sleep(50);
  printf("Final da execução\n");

  return 0;
}
