# Lista 2 - 10/10/2022

## 1
### 1.1
```c
  int Peso (int *V, int ini, int fim)
  { 
    int i, P=0; 
    for(i=ini;i<=fim;i++) 
    P += V[i]; 
    return P; 
  } 
```
|                                     |      |
| ----------------------------------- | ---- |
| int Peso (int *V, int ini, int fim) |      |
| int i, P=0;                         | 1    |
| for(i=ini;i<=fim;i++)               | 2n+2 |
| P += V[i];                          | 2n   |
| return P;                           | 1    |


```c
int Falsa (int *V, int ini, int fim) 
{ 
 if (ini == fim)
  return ini; 
 else 
 { 
  int meio = (ini+fim)/2; 
  if (Peso(V,ini,meio) < Peso(V,meio+1,fim)) 
   return Falsa(V,ini,meio); 
  else 
   return Falsa(V,meio+1,fim); 
 } 
}
```
|                                            |               |
|--------------------------------------------|---------------|
| int Falsa (int *V, int ini, int fim)       |               |
| if (ini == fim)                            | 1             |
| return ini;                                | 1             |
| else                                       | 0             |
| int meio = (ini+fim)/2;                    | 3             |
| if (Peso(V,ini,meio) < Peso(V,meio+1,fim)) | 4+2(4(n/2)+4) | 4n+12
| return Falsa(V,ini,meio);                  | 2+4(n/2)+4    |
| else                                       |               |
| return Falsa(V,meio+1,fim);                | 3+4(n/2)+4    |2n+7
|                                            |               |


considerando n como fim - ini, temos: 

$T(n) = 1$ se n = 1 \
$T(n) = aT(\frac{n}{b}) + f(n)$ se n > 1 

$a=1$, \
$b=2$, \
$f(n) = 6n+24$

$
\left\{
  \begin{array}{lll}
    T(n) = 1 \\
    T(n) = T(\frac{n}{2}) + 6n + 24
  \end{array}
\right.
$ 
