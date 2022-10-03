# Analise Assintotica de Algoritmos Iterativos

 - É necessário analisar seu código (ou pseudocódigo) e construir sua função de complexidade
   - Determina a complexidade assintótica do algoritmo
 - Pode ser iterativo ou recursivo

## Pior, Melhor e Caso Médio

  **Encontrar determinado valor em um vetor**
  - Melhor caso
    - $\Omega(1)$
  - Caso Médio
    - é uma PA
    - Complexidade do caso médio é $\Omicron(n)$
    - $\frac{custo\_todos}{n\_posicoes}$
  - Pior caso
    - $\Omicron(n)$
  - Para generalizar, coloca todos os parâmetros em função de *n*
  - Sempre que se for analisar um algoritmo, foca-se no pior caso

## Princípios da Análise de Algoritmos

  - O tempo de execução de operações básicas
  - O tempo de uma sequência de comandos é o maior tempo de execução de qualquer comando da sequência
  - Soma das complexidades assintóticas $\Omicron(n *log * n) + \Omicron(n^2) + \Omicron(n)$
  - Escolhe-se a com maior tempo, logo $\Omicron(n^2)$
  - Quando há uma sequência dentro da outra
    - Multiplica-se os trechos
    - $\Omicron(n) * \Omicron(n2) = \Omicron(n^3)$

  **Como obter o cusro de cada trecho de código?**
  - Contando o número de operações básicas executadas em cada trecho
  - com condicionais
    - paga-se o teste lógico, opta-se pela pior opção dentre as opções do teste lógico
    - superestima o custo para criar o teto
  - Funções puras (para análise de complexidade)
    - complexidade fixa
    - determinística
    - Independete da entrada, a complexidade assintótica é sempre a mesma
    - exemplos: 
      - raiz(n)
      - potência(base, expoente)
      - maior(A,B)
  - Comando de repetição
    - Contar o custo de todas as linhas internas do comando de repetição
    - As operações básicas do controle do laço de repetição (teste lógico, incremento, etc)
    - $2n + 2 => \Omicron(n)$
      - Atribuição inicial+ teste lógico de saída + n teste lógico e incremento
    - Multiplica o bloco interno do laço por n
  - Laço repetição aninhado
    - $2n^2 + 2n + 2 => \Omicron(n^2)$
  - Laços dependentes
    - O laço aninhado que depende do primeiro
    ```c
      A = 0
      for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
          A++
        }
      }
    ```
    - A cada execução do *for* mai externo, o *for* mais interno executa uma vez a menos

## Exercícios

  1) b
  2) c
     1) ```c
        K=0
        for(i=1; i <= n; i++) // executa n vzs
          for(j=i; j <= n; j++) // executa (n²+n)/2 (simlua uma PA, onde ele executará uma vez a menos para cada novo i avançado no for externo)
            K++;
         ``` 
         
  3) Defina:
     1) $f(x) = \Omicron(g(x))$ and $g(x) = \Omega(f(x))$
     2) $$
        f(x) = g(x) \\
        38x + 17 = 3x^2 -10x + 12\\
        -3x^2+10x-12+38x+17 = 0\\
        -3x^2+48x+5 = 0 (-1)\\
        3x^2-48x-5 = 0\\
        x' = 8 - \sqrt{\frac{197}{3}}\\
        x'' = 8 + \sqrt{\frac{197}{3}}\\
        $$
        $g(x)$ é dominante em relação a $f(x)$ para $x > 8 - \sqrt{\frac{197}{3}}$ e $x < 8 + \sqrt{\frac{197}{3}}$
     3) qualquer valor entre $8 - \sqrt{\frac{197}{3}}$ e $8 + \sqrt{\frac{197}{3}}$
  4) Caso médio é $\frac{custo_total}{n_elementos}$
     Somar os custos = soma dos termos de uma PA, logo $\frac{\frac{n^2+n}{2}}{n}$, tendo assim $\frac{n+1}{2}$
     letra **d**
  5) $T1(n)=\Omicron(n)$ | $T2(n) = \Omicron(n^2)$ | $T3(n) = \Omicron(n^3)\\$
  letra **a**
  6) 
      ```c
        k=0 // 1
        for(i=0; i < n; i++) // 2n + 2
          for(j=0; j < n; j++) // (2n + 2) * n = 2n² + 2n
            k=a+1; // 2 * n * n = 2n²
      ```
      $f(n) = 1 + 2n+2 + 2n^2 + 2n + 2n² = 4n²+4n+3\\$
      $\Omicron(n^2)$

      ```c
        k=0 //1
        for(i=0; i < n; i++) // 2n + 2
          for(j=i; j < n; j++) // 1atrb*n + (1tlog + 1incr)*(n²+n)/2 + 1tlog*n = n²+3n
              k=a+1; // 2 * ((n²+n)/2) = n²+n
      ```
      $f(n) = 1 + 2n+2 + n^2+3n + n²+n =2n^2+6n+3  \\$
      $\Omicron(n^2)$