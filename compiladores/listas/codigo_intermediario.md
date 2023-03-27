# Geração de código intermediário

1) O código intermediário é uma linguagem de máquina abstrata que previne com que cada linguagem tenha que mapear seu código para cada arquitetura existente. Usando isso, uma linguagem pode fazer seu front end e gerar um código intermediário já existente, que então será traduzido para a arquitetura desejada (como o LLVM).

2) a)

|            |                         |
|------------|-------------------------|
| :Fibonacci | anterior = 0            |
|            | proximo = 1             |
|            | aux = 0                 |
|            | i = 0                   |
|            | n = 0                   |
|            | READ n                  |
|            | if n == 1 goto L1       |
|            | goto PROX_1             |
| :L1        | PRINT 0                 |
| :PROX_1    | if n == 2 goto L2       |
|            | goto PROX_2             |
| :L2        | PRINT 1                 |
| :PROX_2    | i = 3                   |
| :FOR_BEGIN | if i > n goto FOR_END   |
|            | aux = proximo           |
|            | t1 = anterior + proximo |
|            | proximo = t1            |
|            | anterior = aux          |
|            | t2 = i+1                |
|            | i = t2                  |
|            | goto FOR_BEGIN          |
| :FOR_END   | PRINT proximo           |

b)

|                 |                                |
|-----------------|--------------------------------|
| :PRIMO          | n=0                            |
|                 | nMax=0                         |
|                 | i=0                            |
|                 | j=0                            |
|                 | totalDivisores=0               |
|                 | READ nMax                      |
|                 | i=0                            |
| :FOR_BEGIN1     | if i > nMax goto FOR_END1      |
|                 | totalDivisores = 0             |
|                 | j=1                            |
| :FOR_BEGIN2     | if j > i goto FOR_END2         |
|                 | t1 = MOD i j                   |
|                 | if t1 == 0 goto L1             |
| :INCREMENT_FOR2 | t2 = j+1                       |
|                 | j = t2                         |
|                 | goto FOR_BEGIN2                |
| :L1             | t3 = totalDivisores+1          |
|                 | totalDivisores = t3            |
|                 | goto INCREMENT_FOR2            |
| :FOR_END2       | if totalDivisores == 2 goto L2 |
|                 | goto INCREMENT_FOR1            |
| :L2             | PRINT i                        |
| :INCREMENT_FOR1 | t4 = i + 1                     |
|                 | i = t4                         |
|                 | goto FOR_BEGIN1                |
| :FOR_END1       |                                |
