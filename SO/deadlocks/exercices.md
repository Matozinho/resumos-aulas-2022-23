# Exercícios


**Exercício**

Allocation:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 1   | 1   | 1   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 0   |

Max:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 3   | 2   | 2   |
| P1      | 0   | 1   | 1   |
| P2      | 4   | 3   | 4   |

Available: [4 3 3]

**b)** P1 requisita [0 1 0]

Need:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 1   |
| P1      | 0   | 1   | 1   |
| P2      | 4   | 3   | 4   |

$REQ_i <= NEED_i$ -> OK\
$REQ_i <= AVAILABLE_i$ -> OK\

Allocation:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 1   | 1   | 1   |
| P1      | 0   | 1   | 0   |
| P2      | 0   | 0   | 0   |

Need:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 1   |
| P1      | 0   | 0   | 1   |
| P2      | 4   | 3   | 4   |

Available: [4 2 3] \
**Verificação de estado seguro**

Finish = [F F F]\
Work = [4 2 3]
$NEED_0 <= WORK$ -> OK\
WORK = WORK + $ALLOC_0$ = [5 3 4]

Finish = [T F F]\
Work = [5 3 4]
$NEED_1 <= WORK$ -> OK\
WORK = WORK + $ALLOC_1$ = [5 4 4]

Finish = [T T F]\
Work = [5 4 4]
$NEED_2 <= WORK$ -> OK\
WORK = WORK + $ALLOC_2$ = [5 4 4]

Finish = [T T T] -> **Sistema seguro**\
Work = [5 4 4]

**c)** Erro

## Verificação de DEADLOCK

Allocation:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 1   | 0   |
| P1      | 2   | 0   | 0   |
| P2      | 3   | 0   | 3   |
| P3      | 2   | 1   | 1   |
| P4      | 0   | 0   | 2   |

Request:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 0   | 0   |
| P1      | 2   | 0   | 2   |
| P2      | 0   | 0   | 0   |
| P3      | 1   | 0   | 0   |
| P4      | 0   | 0   | 2   |

Available: [0 0 0]

**a)** Verificar se existe deadlock

FINISH = [F F F F F]\
WORK = [0 0 0]

$REQUEST_0$ <= WORK -> OK\
FINISH = [T F F F F]\
WORK = WORK + $ALLOCATION_0$ = [0 1 0]

$REQUEST_1$ <= WORK -> FALSO

$REQUEST_2$ <= WORK -> OK\
FINISH = [T F T F F]\
WORK = WORK + $ALLOCATION_2$ = [3 1 3]

$REQUEST_1$ <= WORK -> OK\
FINISH = [T T T F F]\
WORK = WORK + $ALLOCATION_1$ = [5 1 3]

$REQUEST_3$ <= WORK -> OK\
FINISH = [T T T T F]\
WORK = WORK + $ALLOCATION_3$ = [7 2 4]

$REQUEST_4$ <= WORK -> OK\
FINISH = [T T T T T]\
WORK = WORK + $ALLOCATION_4$ = [7 2 6]

**Não está em deadlock**

**b)** P2 requisita [0 0 1]

Allocation:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 1   | 0   |
| P1      | 2   | 0   | 0   |
| P2      | 3   | 0   | 3   |
| P3      | 2   | 1   | 1   |
| P4      | 0   | 0   | 2   |

Request:
| Process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 0   | 0   |
| P1      | 2   | 0   | 2   |
| P2      | 0   | 0   | 1   |
| P3      | 1   | 0   | 0   |
| P4      | 0   | 0   | 2   |

Available: [0 0 0]

FINISH = [F F F F F]\
WORK = [0 0 0]

$REQUEST_0$ <= WORK -> OK\
FINISH = [T F F F F]\
WORK = WORK + $ALLOCATION_0$ = [0 1 0]

$REQUEST_1$ <= WORK -> FALSO\
$REQUEST_2$ <= WORK -> FALSO\
$REQUEST_3$ <= WORK -> FALSO\
$REQUEST_4$ <= WORK -> FALSO

**Os processos $P1$ a $P4$ estão em deadlock**