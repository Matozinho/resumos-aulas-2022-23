# Deadlocks

## Características para que ocorra deadlock

**Devem ocorrer de forma simultânea**

a) **Exclusão mútua:** acesso exclusivo a recursos \
b) **Obtém espera:** Um processo em posse de um recurso espera pra obter outro recurso \
c) **Sem preempção:** Um recurso somente pode ser liberado voluntariamente pelo processo \
d) **Espera circular:** conjunto de processos $P_i$ esperando a liberação de um processo $P_{i+1}$ 

### Grafo de Alocação de recursos (Grafo direcionado)

- Conjunto de vértices $V$ e arestas $E$
- $V$ é particionado em 2 tipos:
  - $P$ - Processos
  - $R$ - Recursos
- Aresta requisição de recurso: $P_i \rightarrow R_j$
- Aresta de atribuição de recurso: $R_j \rightarrow P_i$
  
**Se tem ciclo, pode ser que exita empasse -> Existe ciclo sem deadlock**

## Manipulação de Impasses (Deadolocks)

  1. Garantir que um sistema nunca entre em deadlock
     1. Prevenção de impasse (por construção)
     2. Evitar o impasse (em tempo de execução)
        1. Monitoramento os recursos e caso vá gerar um deadlock, não aceitar a requisição (retor um NULL no malloc)
  2. Detecta e recupera
     1. Mata um dos processos que estão em deadlock
     2. A variação é qual critério usar para escolher o processo que será morto
  3. Ignorar o problema e reinicia o PC quando ocorrer

**Obtém espera:**
  - Solicitar todos os recursos no início da execução (se estou em posse de todos os recursos que preciso, nunca vou entrar em deadlock)
    - Declarar todas as variáveis na mais
    - Word alocar impressora sem nem usar a impressora
  - Gera um baixa utilização de recursos.
  - Para BD é viável. Separar todas as tabelas que serão escritas antes de começar a execução da query no BD

**Sem Preempção:**
  - Impossível fazer isso sistemas
  - preemptar uma impressora gera confusão na impressão

**Espera circular:**
  - Impor uma ordem dos recursos, e possibilitar somente alocação de recursos na ordem crescente
  - Problemas:
    - Enumerar os recursos 
    - Obrigar o programador a saber a ordem dos recursos
  - Complicado de satisfazer

## Evitar Deadlock

  - Algoritmo de detecção de ciclo em grafo: Recursos com uma única instância

### Algorimo do Banqueiro

  - Estado seguro
    - sequência de processos <$P_0, P_1, ..., P_n$> em que todos os recursos necessários estão disponíveis no sistema, ou alocados para o processo $j$, onde $j < i$
  - Problema:
    - Falar exatamente o máximo de recursos de cada tipo que o processo vai usar

  - **Algoritmo de verificação de estado seguro**
    - Vetor AVAILABLE: recursos disponíveis
    - Matriz MAX: máximo de recursos que podem ser alocados por um processo
    - Matriz ALLOC: recursos alocados para um processo $P$
    - Matriz NEED: Matriz MAX - Matriz ALLOC
    - FINISH: F para tod $i=0 ... n-1$
    - WORK: AVAILABLE
    1. FINISH: Falso p todo i; work = available
    2. Se existe NEED $<=$ WORK e FINISH[i] $==$ F
       1. passo 3
       2. se não, passo 4
    3. WORK = WORK + ALLOC;
       1. FINISH[i] = T
       2. passo 2
    4. Se FINISH[T] para todo $I$, sistema em estado seguro
       1. Se não, estado inseguro -> possibilidade de deadlock
   
 - **Algoritmo de execução de requisição**
   - $REQ_i$ = requisição de um processo $i$
    1. Se ($REQ_i$ $<=$ $NEED_i$) GOTO 2
       1. SENÃO erro -> processo requisitou acima do declarado
    2. Se ($REQ_i$ $<=$ AVAILABLE) GOTO 3
       1. SENÃO Não aceita requisição
    3. $ALLOC_i$ = $ALLOC_i$ + $REQ_i$
       1. $NEED_i$ = $NEED_i$ - $REQ_i$
       2. AVAILABLE = AVAILABLE - $REQ_i$
    4. Se o estado está seguro, aceita a requisiçãp. Senão, da um rollback nas alterações e não aceita a requisição

## Detecção em Deadlocks

  1. $FINISH[i]$ = F p/ todo i=0 ... n-1
     1. WORK = AVAILABLE
  2. SE existe um i $REQ_i$ <= WORK e $FINISH[i] == F$ => GOTO 3
     1. SENÃO GOTO 4
  3. $FINISH[i] = T$
     1. WORK = WORK + $ALLOC_i$
     2. GOTO 2
  4. SE $FINISH[i] == T$ p/ todo i sem deadlock
     1. SENÃO sistema em DEADLOCK (Processo com FINISH=F em deadlock)
   
Problema do banqueiro é o processo dizer quanto vai usar de um recurso

Para matar um processo em deadlock há diferentes critérios
  - Finalizar todos os processos
  - Prioridade
  - Tempo de execução
  - Nº de recursos