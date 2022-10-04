# Analise Assintotica de Algoritmos Recursivos

É Preciso computar o custo necessário para computar as chamadas 

Equação de recorrência
$$
  T(n) = aT(\frac{n}{b}) + f(n)
$$
a -> número de chamadas recursivas por execução \
$\frac{n}{b}$ ou b -> fator de redução, quanto o problema vai se reduzir por iteração. quanto maior for a razão, mais rápido o problema finaliza \
f(n) -> custo das chamadas recursivas e do retorno da função