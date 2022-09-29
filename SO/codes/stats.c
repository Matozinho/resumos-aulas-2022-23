#include <unistd.h>
#include <stdio.h>
#include <syscall.h>

int main()
{
  printf("PID: %d parent: %d\n", getpid(), getppid());
  fflush(stdout);

  char s;

  scanf("%c", &s);

  return 0;
}