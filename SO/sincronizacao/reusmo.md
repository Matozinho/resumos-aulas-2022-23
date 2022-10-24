# Sincronização entre processos
  - Exclusão mútua -> só um em cada tempo
  - Progreção
  - Espera limitada
  - Velocidade escalonamento dos processos

## a) Estrita Alternância
  - 
## b) Solução de Petersen
  - Para 2 processos
## c) Desabilitar Interrupções
  - Não funciona
## d) Test_and_set
  - Instrução em HW
  - Atômica -> Vai do início ao final da função sem dois caras executando junto, ou sem trocar de contexto no meio

key variável global, que diz se o processo pode ou não entrar em uma seção crítica

```cpp
  bool Test_and_set(bool key) {
    bool t = key;
    key = true;
    return t;
  } 
```

  - Uso de test_and_set

```cpp
  // p1
  while (test_and_set(key) == true);
  // S.C

  key = false
```

```cpp
  // p2
  while (test_and_set(key) == true);
  // S.C

  key = false
```

Pode não garantir espera limitada, pq um pode fazer a seção crítica várias vezes seguidas, enquanto o outro fica esperando

## e) Swap
  - Instrução em HW
  - Atômica
  - Lock é privado 
  - Key é compartilhada
  
```cpp
  void Swap(bool key, bool lock) {
    bool t = key;
    key = lock;
    lock = t;
  } 
```

```cpp
  // p1
  lock = true
  while(lock == true) {
    Swap(key, lock);
  }
  // S.C
  key = false;
```

```cpp
  // p2
  lock = true
  while(lock == true) {
    Swap(key, lock);
  }
  // S.C
  key = false;
```

Tal como o test_and_set, pode não garantir espera limitada.

## Semáforos
  - Operação de alto nível
    - adquire (wait) - acquire
    - libera (signal) release
  - Representado por um valor numérico
  - Adquire e libera precisam ser atômicos

```cpp
  void adquire() {
    value--;
    if(value < 0) {
      block P;
    }
  }
```

```cpp
  void libera() {
    value++;
    if(value <= 0) {
      wakeup P na fila de espera;
    }
  }
```

### Semáforo binário
  - Somente um por vez
  - Inicializa o semáforo com 1
  - Usa test_and_set para garantir que o adquire e o libera são atômicos
  - Se não for, ambos são bloquados no adquire

### Semáforo Contador
  - N instâncias de um recurso
  - Inicia com N, não com 1

## Resolva o problema do produtor consumidor usando semáforos

**Produtor**

```cpp
  while(1) {
    while(count == n);
    buffer[in] = d;
    in = (in+1)%n;
    count++;
  }
```

**Consumidor**

```cpp
  while(1) {
    while(count == 0);
    d_out = buffer[out];
    out = out+1%n;
    count--;
  }
```

### Solução

**Produtor**

```cpp
  while(1) {
    while(count == n);
    buffer[in] = d;
    in = (in+1)%n;
    adquire(s);
    count++;
    libera(s);
  }
```

**Consumidor**

```cpp
  while(1) {
    while(count == 0);
    d_out = buffer[out];
    out = out+1%n;
    adquire(s);
    count--;
    libera(s);
  }
```

## N Produtores e M consumidores

Semáforo (contador) **Full** = elementos no buffer
Semáforo (contador) **Empty** = posições livres no buffer
Semáforo (binário) **Mutex** = acesso ao buffer

**FULL** inicia com 0;
**EMPTY** inicia com N;
**MUTEX** inicia com 1;

**Produtor**

```cpp
  while(1) {
    while(count == n);
    
    adquire(EMPTY);
    adquire(MUTEX);

    // produz

    libera(MUTEX);
    libera(FULL);
  }
```

**Consumidor**

```cpp
  while(1) {
    while(count == n);
    
    adquire(FULL);
    adquire(MUTEX);

    // consume

    libera(MUTEX);
    libera(EMPTY);
  }
```

- Não consume CPU, pois não tem espera ativa
- Com processamento pequeno, acaba virando (**quase**) um código sequencial

**Deadloack**

Semáforo P e Q

```cpp
// p1
adquire(P);
adquire(Q);
```

```cpp
// p2
adquire(Q);
adquire(P);
```