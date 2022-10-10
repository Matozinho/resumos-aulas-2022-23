# Threads
  
  - Múltiplas linhas de execução
  - Compartilhado
    - dados
    - código
    - recursos
    - IO
    - arquivos
    - ...
  - Privado
    - Registradores (para manter o fluxo de execução)
    - Pilha (endereço de retorno de funções)
  
**Benefícios**
  - Compartilhamento de Recursos
  - Economia de recursos
  - Tempo de Resposta
    - Processamento em background de tasks
  - Desempenho em arquiteturas multiprocessadas

**Kernel Level Threads**
  - Suportado nativamente pelo sistema operacional
  - Pode escalonar as threads
  - PThreads (POSIX Threads) - windows tmb aceita

**User Level Threads**
  - Biblioteca de threads
  - SO enxerga a biblioteca e o APP como sendo um processo só
  - Green Threads (Java nativamente implementava o Green Threads para ter portabilidade - aceitava nativamente as threads)
  - Grande Vantagem: **Portabilidade**