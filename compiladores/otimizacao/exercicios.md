# Exercícios

1) 
  - Saída de O1: 
    - codes/1.c:18:3: optimized:   Inlining printf/15 into main/24 (always_inline).
    - **Tempo:** 0.415s
  - Saída de O2: 
    - codes/1.c:18:3: optimized:   Inlining printf/15 into main/24 (always_inline).
    - codes/1.c:16:12: optimized:  Inlining powern/23 into main/24.
    - **Tempo:** 0,398s
  - Saída de O3:
    - codes/1.c:18:3: optimized:   Inlining printf/15 into main/24 (always_inline).
    - codes/1.c:16:12: optimized:  Inlining powern/23 into main/24.
    - codes/1.c:6:17: optimized: loop with 3 iterations completely unrolled (header execution count 74105864)
    - **Tempo:** 0,387s
  - Saída de O3 com unroll-loops
    - codes/1.c:18:3: optimized:   Inlining printf/15 into main/24 (always_inline).
    - codes/1.c:16:12: optimized:  Inlining powern/23 into main/24.
    - codes/1.c:6:17: optimized: loop unrolled 7 times
    - codes/1.c:6:17: optimized: loop with 3 iterations completely unrolled (header execution count 74105864)
    - codes/1.c:15:17: optimized: loop unrolled 3 times
    - **Tempo:** 0,362s
