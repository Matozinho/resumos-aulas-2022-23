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

**big exemple**

P -> begin D C end \
D -> int id I \
I -> , id I | $\epsilon$ \
C -> C ; T = E | T = E4 \
E -> E + T | T \
T -> id | id[E]

**Removendo recursão à esquerda de C**
C -> C ; T = E | T = E4 

C == A \
; T = E == $\beta$ \
T=E == $\delta$ \

C -> T=E C' \
C' -> ; T=E C' | $\epsilon$

**Removendo recursão à esquerda de E**
E -> E + T | T 

E -> TE' \
E' -> + TE' | $\epsilon$

**Removendo prefixo comum**
T -> id | id[E]

T -> id T' \
T' -> [E] | $\epsilon$

**Gramática Corrigida**

P -> begin D C end \
D -> int id I \
I -> , id I | $\epsilon$ \
C -> T=E C' \
C' -> ; T=E C' | $\epsilon$ \
E -> TE' \
E' -> + TE' | $\epsilon$ \
T -> id T' \
T' -> [E] | $\epsilon$


**First e Follow**

|        |    **First**     |    **Follow**     |
| :----: | :--------------: | :---------------: |
| **P**  |      begin       |         $         |
| **D**  |       int        |        id         |
| **I**  | ',', $\epsilon$  |        id         |
| **C**  |        id        |        end        |
| **C'** | ';' , $\epsilon$ |        end        |
| **E**  |        id        |    ';', end, ]    |
| **E'** |  +, $\epsilon$   |    ';', end, ]    |
| **T**  |        id        | =, +, ';', end, ] |
| **T'** |  [, $\epsilon$   | =, +, ';', end, ] |

## Validar essa Tabela (possível erro)
================================================================================

| **Tabela sintática preditiva** |     **begin**      |     **end**      |    **int**    |      **id**      |   **,**    |      **;**       |      **=**       |      **+**       |   **[**   |      **]**       | **$** |
| :----------------------------: | :----------------: | :--------------: | :-----------: | :--------------: | :--------: | :--------------: | :--------------: | :--------------: | :-------: | :--------------: | :---: |
|             **P**              | P -> begin D C end |                  |               |                  |            |                  |                  |                  |           |                  |       |
|             **D**              |                    |                  | D -> int id I |                  |            |                  |                  |                  |           |                  |       |
|             **I**              |                    |                  |               | I -> $\epsilon$  | I -> ,id I |                  |                  |                  |           |                  |       |
|             **C**              |                    |                  |               |    C-> T=E C'    |            |                  |                  |                  |           |                  |       |
|             **C'**             |                    | C' -> $\epsilon$ |               | C' -> ; T = E C' |            |                  |                  |                  |           |                  |       |
|             **E**              |                    |     E -> TE'     |               |                  |            |                  |                  |                  |           |                  |       |
|             **E'**             |                    | E' -> $\epsilon$ |               |                  |            | E' -> $\epsilon$ |                  |    E' -> +TE'    |           | E' -> $\epsilon$ |       |
|             **T**              |                    |                  |               |    T -> id T'    |            |                  |                  |                  |           |                  |       |
|             **T'**             |                    | T' -> $\epsilon$ |               |                  |            | T' -> $\epsilon$ | T' -> $\epsilon$ | T' -> $\epsilon$ | T' -> [E] | T' -> $\epsilon$ |       |

================================================================================

| Pilha               | Entrada                                 | Prod               |
| ------------------- | --------------------------------------- | ------------------ |
| $P                  | **begin** int id, id id = id[id+id] end | P -> begin D C end |
| $end C D begin      | **begin** int id, id id = id[id+id] end |                    |
| $end C D            | **int** id, id id = id[id+id] end       | D -> int id I      |
| $end C I id int     | **int** id, id id = id[id+id] end       |                    |
| $end C I id         | **id**, id id = id[id+id] end           |                    |
| $end C I            | **,** id id = id[id+id] end             | I -> , id I        |
| $end C I id ,       | **,** id id = id[id+id] end             |                    |
| $end C I id         | **id** id = id[id+id] end               |                    |
| $end C I            | **id** = id[id+id] end                  | I -> $\epsilon$    |
| $end C              | **id** = id[id+id] end                  | C -> T=E C'        |
| $end C C' E = T     | **id** = id[id+id] end                  | T -> id T'         |
| $end C C' E = T' id | **id** = id[id+id] end                  |                    |
| $end C C' E = T'    | **=** id[id+id] end                     | T' -> $\epsilon$   |
| $end C C' E =       | **=** id[id+id] end                     |                    |
| $end C C' E         | **id**[id+id] end                       | E -> T E'          |
| $end C C' E' T      | **id**[id+id] end                       | T -> id T'         |
| $end C C' E' T' id  | **id**[id+id] end                       |                    |
| $end C C' E' T'     | **\[**id+id] end                        | T' -> [E]          |
| $end C C' E ] E [   | **\[**id+id] end                        |                    |
| $end C C' E ] E     | **id**+id] end                          |                    |

# Bottom-up

- Menos restrições quanto à grámatica
  - Prefixo comum não importa
  - Pode ter recursão à esquerda
- Inicia dos terminais e faz redução

**Redução:** substituição do lado direito de uma produção pelo não 
terminal correspondente (lado esquerdo)

**Handle:** sequência  de  símbolos  do  lado  direito  da 
produção,  tais  que  suas  reduções  levam,  no  final,  ao 
símbolo inicial da gramática

- Se a gramática é não ambígua, cada forma sentendial à direita tem um handle único