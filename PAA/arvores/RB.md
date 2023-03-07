# Árvore Red Black (Rubro Negra)

- Todo nó é vermelho ou preto
- A raiz é preta
- Toda folha é preta (NULL)
- Se um nó é vermelho, então ambos seus filhos são pretos
- Para cada nó todos os caminhos do nó para as folhas descendentes contém o mesmo número de nós pretos
- Árvore é definida em $log_2n$
- Muita consulta e pouca inserção/remoção -> AVL
- Dados voláteis com muita alteração -> árvore RB
- Casos mais comuns de ferir os 5 princípios
  - quando houver 2 vermelhos seguidos
  - raiz vermelha
- Faz o balanceamento com no máximo dois níveis acima do nó inserido

## Inserção

- Problemas:
  - A raiz da árvore deve ser preta
  - Se um nó é vermelho, então ambos seus filhos são pretos

- Resoluções:
  - **Caso 1: o tio de Z é da cor vermelha**
    - Inverter a cor do avô, do tio e do pai
  - **Caso 2: Quando o tio do vértice é da cor preta e o Z é um filho da direita** 
    - left rotate
    - Não resolve o problema, é uma preparação para o caso 3
  - **Caso 3: O tio de Z é da cor preta e Z é um filho da esquerda**
    - Inverter o pai e o avô
    - rotação à direita no avô de Z