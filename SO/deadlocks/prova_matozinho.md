**Aluno:** Felipi Lima Matozinho

**1)**
MAX = 
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 4   | 1   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 2   | 4   |

AVAILABLE = [5 5 5]

ALLOCATION = 
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 0   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 0   | 0   |

**a)** P0 requisita [2 1 0]

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 4   | 1   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 2   | 4   |

$REQ_0$ = [2 1 0]

$REQ_0 <= NEED_0$ => OK: GOTO 2\
$REQ_0 <= AVAILABLE$ => OK: GOTO 3

ALLOCATION = 
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 0   | 0   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 2   | 4   |

AVAILABLE = [3 4 5]

**Verificação de estado seguro**

FINISH = [F F F F]\
WORK = [3 4 5]

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => OK: GOTO 3\
$WORK$ = [3 4 5] + [2 1 0] = [5 5 5]\
$FINISH$ = [T F F F]

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => OK: GOTO 3\
$WORK$ = [5 5 5] + [0 0 0] = [5 5 5]\
$FINISH$ = [T T F F]

$NEED_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$WORK$ = [5 5 5] + [0 0 0] = [5 5 5]\
$FINISH$ = [T T T F]

$NEED_3 <= WORK$ \&\& $FINISH[3] == F$ => OK: GOTO 3\
$WORK$ = [5 5 5] + [0 0 0] = [5 5 5]\
$FINISH$ = [T T T T]

**Sistema em estado seguro => requisição aceita**

**b)** P3 requisita [0 0 1]
AVAILABLE = [3 4 5]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 0   | 0   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 2   | 4   |

$REQ_3$ = [0 0 1]

$REQ_3 <= NEED_3$ => OK: GOTO 2\
$REQ_3 <= AVAILABLE$ => OK: GOTO 3\
ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 0   | 1   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 2   | 3   |

AVAILABLE = [3 4 4]

**Verificação de estado seguro**

FINISH = [F F F F]\
WORK = [3 4 4]

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => OK: GOTO 3\
$WORK = [3 4 4] + [2 1 0] = [5 5 4]$\
$FINISH = [T F F F]$

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => OK: GOTO 3\
$WORK = [5 5 4] + [0 0 0] = [5 5 4]$\
$FINISH = [T T F F]$

$NEED_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$WORK = [5 5 4] + [0 0 0] = [5 5 4]$\
$FINISH = [T T T F]$

$NEED_3 <= WORK$ \&\& $FINISH[3] == F$ => OK: GOTO 3\
$WORK = [5 5 4] + [0 0 1] = [5 5 5]$\
$FINISH = [T T T T]$

**Sistema em estado seguro => requisição aceita**

**c)** P2 requisita [0 0 2]\
AVAILABLE = [3 4 4]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 0   | 1   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 2   | 3   |

$REQ_2$ = [0 0 2]

$REQ_2 <= NEED_2$ => OK: GOTO 2\
$REQ_2 <= AVAILABLE$ => OK: GOTO 3\
ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 2   |
| P3      | 0   | 0   | 1   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 0   |
| P3      | 2   | 2   | 3   |

AVAILABLE = [3 4 2]

**Verificação de estado seguro**

FINISH = [F F F F]\
WORK = [3 4 2]

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => OK: GOTO 3\
$WORK = [3 4 2] + [2 1 0] = [5 5 2]$\
$FINISH = [T F F F]$

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => OK: GOTO 3\
$WORK = [5 5 2] + [0 0 0] = [5 5 2]$\
$FINISH = [T T F F]$

$NEED_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$WORK = [5 5 2] + [0 0 2] = [5 5 4]$\
$FINISH = [T T T F]$

$NEED_3 <= WORK$ \&\& $FINISH[3] == F$ => OK: GOTO 3\
$WORK = [5 5 4] + [0 0 1] = [5 5 5]$\
$FINISH = [T T T T]$

**Sistema em estado seguro => requisição aceita**

**d)** P3 requisita [2 0 1]

AVAILABLE = [3 4 2]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 2   |
| P3      | 0   | 0   | 1   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 0   |
| P3      | 2   | 2   | 3   |

$REQ_3$ = [2 0 1]

$REQ_3 <= NEED_3$ => OK: GOTO 2\
$REQ_3 <= AVAILABLE$ => OK: GOTO 3\
ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 0   | 2   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 2   | 2   |

AVAILABLE = [1 4 1]

**Verificação de estado seguro**

FINISH = [F F F F]\
WORK = [1 4 1]

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => OK: GOTO 3\
$WORK = [1 4 1] + [0 0 0] = [1 4 1]$\
$FINISH = [F T F F]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$WORK = [1 4 1] + [0 0 2] = [1 4 3]$\
$FINISH = [F T T F]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_3 <= WORK$ \&\& $FINISH[3] == F$ => OK: GOTO 3\
$WORK = [1 4 3] + [2 0 2] = [3 4 5]$\
$FINISH = [F T T T]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => OK: GOTO 3\
$WORK = [3 4 5] + [2 1 0] = [5 5 5]$\
$FINISH = [T T T T]$

**Sistema em estado seguro => requisição aceita**

**e)** P1 requisita [0 4 1]

AVAILABLE = [1 4 1]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 0   | 2   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 4   | 1   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 2   | 2   |

$REQ_1$ = [0 4 1]

$REQ_1 <= NEED_1$ => OK: GOTO 2\
$REQ_1 <= AVAILABLE$ => OK: GOTO 3

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 0   | 2   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 2   | 2   |

AVAILABLE = [1 0 0]

**Verificação de estado seguro**

FINISH = [F F F F]\
WORK = [1 0 0]

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => Ok: GOTO 3\
$WORK = [1 0 0] + [0 4 1] = [1 4 1]$\
$FINISH = [F T F F]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$WORK = [1 4 1] + [0 0 2] = [1 4 3]$\
$FINISH = [F T T F]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_3 <= WORK$ \&\& $FINISH[3] == F$ => OK: GOTO 3\
$WORK = [1 4 3] + [2 0 2] = [3 4 5]$\
$FINISH = [F T T T]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => OK: GOTO 3\
$WORK = [3 4 5] + [2 1 0] = [5 5 5]$\
$FINISH = [T T T T]$

**Sistema em estado seguro => requisição aceita**

**f)** P1 requisita [1 0 0]

AVAILABLE = [1 0 0]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 1   | 0   |
| P1      | 0   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 0   | 2   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 2   | 0   | 0   |
| P1      | 1   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 2   | 2   |

$REQ_1$ = [1 0 0]

$REQ_1 <= NEED_1$ => OK: GOTO 2\
$REQ_1 <= AVAILABLE$ => OK: GOTO 3

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 3   | 1   | 0   |
| P1      | 0   | 4   | 1   |
| P2      | 0   | 0   | 2   |
| P3      | 2   | 0   | 2   |

NEED =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 1   | 0   | 0   |
| P1      | 1   | 0   | 0   |
| P2      | 0   | 0   | 0   |
| P3      | 0   | 2   | 2   |

AVAILABLE = [0 0 0]

**Verificação de estado seguro**

FINISH = [F F F F]\
WORK = [0 0 0]

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => FALSE

$NEED_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$WORK = [0 0 0] + [0 0 2] = [0 0 2]$\
$FINISH = [F F T F]$

$NEED_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$NEED_1 <= WORK$ \&\& $FINISH[1] == F$ => FALSE

$NEED_3 <= WORK$ \&\& $FINISH[3] == F$ => FALSE

**Sistema em estado inseguro => requisição recusada devido a risco de gerar deadlock**

**2)**

AVAILABLE = [0 0 0]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 3   | 0   | 1   |
| P1      | 0   | 1   | 0   |
| P2      | 5   | 2   | 0   |
| P3      | 0   | 0   | 1   |
| P4      | 0   | 0   | 1   |

REQUEST =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 0   | 1   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 1   | 1   |
| P3      | 0   | 0   | 1   |
| P4      | 0   | 0   | 0   |

**a)**

FINISH = [F F F F F]\
WORK = [0 0 0]

$REQUEST_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$REQUEST_1 <= WORK$ \&\& $FINISH[1] == F$ => OK: GOTO 3\
$FINISH = [F T F F F]$\
$WORK = [0 0 0] + [0 1 0] = [0 1 0]$

$REQUEST_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$REQUEST_2 <= WORK$ \&\& $FINISH[2] == F$ => FALSE

$REQUEST_3 <= WORK$ \&\& $FINISH[3] == F$ => FALSE

$REQUEST_4 <= WORK$ \&\& $FINISH[4] == F$ => OK: GOTO 3\
$FINISH = [F T F F T]$\
$WORK = [0 1 0] + [0 0 1] = [0 1 1]$

$REQUEST_0 <= WORK$ \&\& $FINISH[0] == F$ => OK: GOTO 3\
$FINISH = [T T F F T]$\
$WORK = [0 1 1] + [3 0 1] = [3 1 2]$

$REQUEST_2 <= WORK$ \&\& $FINISH[2] == F$ => OK: GOTO 3\
$FINISH = [T T T F T]$\
$WORK = [3 1 2] + [5 2 0] = [8 3 2]$

$REQUEST_3 <= WORK$ \&\& $FINISH[3] == F$ => OK: GOTO 3\
$FINISH = [T T T T T]$\
$WORK = [8 3 2] + [0 0 1] = [8 3 3]$

**Sistema não está em deadlock**

**b)**

AVAILABLE = [0 0 0]

ALLOCATION =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 3   | 0   | 1   |
| P1      | 0   | 1   | 0   |
| P2      | 5   | 2   | 0   |
| P3      | 0   | 0   | 1   |
| P4      | 0   | 0   | 1   |

REQUEST =
| process | A   | B   | C   |
| ------- | --- | --- | --- |
| P0      | 0   | 0   | 1   |
| P1      | 0   | 0   | 0   |
| P2      | 0   | 1   | 1   |
| P3      | 0   | 0   | 1   |
| P4      | 1   | 0   | 0   |

FINISH = [F F F F F]\
WORK = [0 0 0]

$REQUEST_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$REQUEST_1 <= WORK$ \&\& $FINISH[1] == F$ => OK: GOTO 3\
$FINISH = [F T F F F]$\
$WORK = [0 0 0] + [0 1 0] = [0 1 0]$

$REQUEST_0 <= WORK$ \&\& $FINISH[0] == F$ => FALSE

$REQUEST_2 <= WORK$ \&\& $FINISH[2] == F$ => FALSE

$REQUEST_3 <= WORK$ \&\& $FINISH[3] == F$ => FALSE

$REQUEST_4 <= WORK$ \&\& $FINISH[4] == F$ => FALSE

**Os processos P0, P2, P3 e P4 estão em deadlock**