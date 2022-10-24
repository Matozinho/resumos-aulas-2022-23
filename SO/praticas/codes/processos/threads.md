# Pthreads X JavaThreads

## a) Onde inicia a execução da thread?
No Pthreads, a thread inicia na função que foi passada como parâmetro na chamada do *pthread_create*, enquanto no JavaThreads, a thread inicia na função *run* da classe que implementa a interface *Runnable*.
No Pthreads a thread executa imediatamente após o *pthread_create*, enquanto no JavaThreads, inicia após o thread.start();

## b) Como é realizado o compartilhamento de dados entre threads?
Para o Pthreads, o compartilhamento de dados é realizado através de variáveis globais, enquanto no JavaThreads, é necessário uma classe com os dados que serão compartilhados, para que a mesma instância seja passada como parâmetro para as instâncias das threads.

## c) O que acontece quando uma thread principal finaliza, caso existam outras threads em execuçao?
No Pthreads as threads secundárias são finalizadas junto com a thread principal, enquanto no JavaThreads, as threads secundárias finalizam sua execução.