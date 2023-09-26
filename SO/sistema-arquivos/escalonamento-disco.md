# Escalonamento de Disco

- FIFO
- FCFS (First come, first served)
- Menor tempo de busca primeiro
- SCAN (algoritmo do elevador) - utilizado pelo linux
  - lookahead - não precisa ir até o final do disco
  - circular: atender sempre em uma única direção

# E/S

Um driver para cada dispositivo

## Espera ativa - Polling

Fica perguntando se o dispositivo está pronto

## Interrupção

Manipulador de interrupção
