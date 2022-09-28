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