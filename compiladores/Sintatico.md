# Analisado Sintático (ou parser)

  - Revebe os tokens do analisador léxico e gera uma árvore sintática
  - Relaciona as partes e subpartes de um programa
  - Verificar se todas as estruturas de um comando estão presentes
  - Não há como impor restrição de distribuição no código fonte
    - variável duplicada
    - variável usada antes de ser declarada
  - A parte de contexto é feito na proxima etapa
  - Se preocupa com a sequência, mas não com o contexto

## Derivações

  - Contruir uma árvore usando derivações
  - top-down 
  - Tratar ambiguidade
  - 
    - Reesscrever a gramática
    - Definir orden de prioridade durante a derivação
  - Bottom-up
    - Redução (contrário da derivação)
    - Constrói a árvore a partir das folhas
  
## Analisadores Top Down
### Análise Recursiva com Retrocesso

  - Recursivamente por força bruta, testando todas as opções 
  - porderosos, entretanto lentos
  - tempo exponencial para execução
  - não adequados para implementação em compiladores

### Análise Preditiva Tabular

  - utiliza pilha explícita
  - implementa automato de pilha controlado por uma tabela de análise ??
  - se baseia no próximo caractere 

**Tabela de Parsing**
  - Uma matriz bidimensional M[A, a]
    - A é um não terminal
    - a é um terminal
  
**Gramáticas LL(1)**

  - Da esquerda pra diretita, com derivação mais à esquerda
  - Lookahead -> quantos símbolos olha a frente para para decidir a produção
  - A gramática **NÃO** pode:
    - Não pode ser ambígua
    - Recursiva à esquerda
    - Em uma produção A -> $\alpha | \beta$, tanto $\alpha$ quanto $\beta$ não podem começar com o mesmo símbolo (prefixo comum)

  **Como corrigir**

  - Elimicação de recursão à esquerda
    - possível transformar em recursão à direita
    - A -> $A\beta | \delta$
    - Trocando:
    - A-> $\delta A'$
    - A' -> $\beta A' | \epsilon$
  - Fatoração à esquerda
    - A-> $\alpha \beta | \alpha \gamma$
    - Trocando:
    - A-> $\alpha A'$
    - A'-> $\beta | \gamma$

  **First and Follow**
  
  - First: Conjunto de todos os símbolos terminais que podem iniciar uma string derivada de x
  - **Regra**:
    - Se X -> aYZ, onde a é um terminal, então Firs(a) está em First(X). o First de um terminal é o próprio terminal
    - Se X -> $\epsilon$ é uma produção, então adicione $\epsilon$ em First(X)
    - Se X -> YZW, onde Y, Z e W são não terminais, então First(X) contém First(Y)-{$\epsilon$}. Caso First(Y) pode ser $\epsilon$, então usa-se First(Z)-{$\epsilon$} e assim por diante. Ou seja, primeiro símbolo terminal a partir de X

  **Follow**
  - Follow de X é o conjunto de terminais que podem aparecer imediatamente à direita de X em alguma forma sentencial

  **Construção da Tabela**

  - Analisador preditivo

                       ┌───────────┐
                       │   input   │
        ┌─────┐        └─────┬─────┘
        │     │              │
        │     │        ┌─────▼─────┐
        │     │        │           │
        │     │        │           │
        │Pilha│▲───────┤    P.D    ├────► Saída/Erro
        │     ├───────▼│           │
        │     │        │           │
        │     │        └──────▲────┘
        │     │               │
        └─────┘        ┌──────┴─────┐
                       │            │
                       │   Tabela   │
                       │            │
                       └────────────┘
## Exercícios 

3) b)
   
  S -> ABC \
  A -> aA | $\epsilon$ \
  B -> bB | CdA \
  C -> cC | $\epsilon$ 

|       |   **First**   | **Follow** |
| :---: | :-----------: | :--------: |
| **S** |  a, b, c, d   |     $      |
| **A** | a, $\epsilon$ | b, c, d, $ |
| **B** |    b, c, d    |    c, $    |
| **C** | c, $\epsilon$ |    $, d    |

| **tabela sintática preditiva** |  **a**   |      **b**      |      **c**      |      **d**      |      **$**      |
| :----------------------------: | :------: | :-------------: | :-------------: | :-------------: | :-------------: |
|             **S**              | S -> ABC |    S -> ABC     |    S -> ABC     |    S -> ABC     |                 |
|             **A**              | A -> aA  | A -> $\epsilon$ | A -> $\epsilon$ | A -> $\epsilon$ | A -> $\epsilon$ |
|             **B**              |          |     B -> bB     |    B -> CdA     |    B -> CdA     |                 |
|             **C**              |          |                 |     C -> cC     | C -> $\epsilon$ | C -> $\epsilon$ |

c)

S -> 0A | 1B\
A -> 1B | 2\
B -> 0A | 2

|       | **First** | **Follow** |
| :---: | :-------: | :--------: |
| **S** |    0,1    |     $      |
| **A** |    1,2    |     $      |
| **B** |    0,2    |     $      |

| **tabela sintática preditiva** |  **0**  |  **1**  | **2**  | **$** |
| :----------------------------: | :-----: | :-----: | :----: | :---: |
|             **S**              | S -> 0A | S -> 1B |        |       |
|             **A**              |         | A -> 1B | A -> 2 |       |
|             **B**              | B -> 0A |         | B -> 2 |       |
