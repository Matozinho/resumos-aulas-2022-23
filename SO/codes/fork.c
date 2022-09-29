#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// eu não decido quem executa primeiro
// não necessariamente são em paralelo
// duplica toda a região de memória (todas as variáveis), não compartilha região de memória
int main()
{
  pid_t pid;
  // pra linha execução do pai, pid é o processo do filho
  // para a linha de execução do filho, pid é 0
  printf("Print antes do fork\n");
  pid = fork();

  // caso processo filho
  if (pid == 0)
    printf("Processo filho - pid: %d | ppid: %d\n", getpid(), getppid());
  else
    printf("Processo pai - pid: %d | pid filho: %d\n", getpid(), pid);

  printf("Final da execução\n");

  return 0;
}