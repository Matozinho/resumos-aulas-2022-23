# Algoritmos de Busca

  - Espaço de busca pode ser organizado em forma de árvores ou grafos
    - Nós correspondem as situações de um problema
    - as arestas correspondem as ações ou passos
    - Especificar um estado inicial
    - Especificar um estado final
  - Os algoritmos de busca operam sobre árvores
    - Quando a representação utiliza grafos, eles serão modificados para incluir um mecanismo de controle de ciclos
  
## Problema dos Jarros de Água

  Em posse de dois jarros de água, um com capacidade de 4 litros e outro que suporta até 3 litros. deseja-se separar 2 litros de água ba jarra de 4L. Como fazer isso?

## Abordagens

  - Orientada por dados
    - encadeamento progressivo (encadeamento pra frente)
    - top-down
    - parte do estado inicial
    - É interessante quando os dados iniciais são fornecidos e não tem-se certeza sobre o objetivo
    - A subida da encosta
  - Orientada por objetivos
    - encadeamento regressivo
    - bottom-up
    - Começa com um objetivo e volta para um estado inicial, vendo quais deslocamentos são necessários
    - Útil em situações em que o objetivo pode ser claramente especificado
    - Ex: 
      - Saída do labirinto
      - Disgnóstico médico

## Propriedades dos métodos de busca

  -  Completude
     -  se o método garante encontrar a melhor solução
  -  Complexidade
     -  Eficiência do método em relação ao tempo de execução e espaço (memória)
     -  representação do espaço de busca e conjunto de informações para encontrar a solução
     -  o método rápido nem sempre enontrará a melhor solução
     -  Um método que examine cada possível solução garantirá encontrar a melhor solução, mas poderá ser muito ineficiente
  -  Otimalidade
     -  Um método é dito ótimo se garantir encontrar a melhor solução caso exista
     -  utilizado para descrever um algoritmo que encontre a solução no menor tempo possível
     -  define limite em relação à recursos
     -  admissibilidade -> A melhor solução com o melhor tempo possível, não com relação ao objetivo
  -  Irrevogabilidade
     -  Métodos que permitem retrocesso
     -  Uma decisão pode ser desfeita (tentativa)
     -  Métodos **irrevogáveis** são aqueles que analisam somente um caminho
     -  Subida da encosta é irrevogável
     -  Estratégia gulosa é irrevogável
     -  programação dinâmica é busca por tentativa
     -  busca em profundidade é busca por tentativa
     -  Métodos irrevogáveis normalmente encontram soluções subótimas para o problema

## Busca Cega

  - Procura em todo espaço de busca
  - É ineficiente
  - Aplicações em contextos pequenos

## Busca Heurística

  - Baseados em algum conhecimento que pode acelerar a solução do problema
  - Mais informações do que o estado atual
  - Exemplo de informação:
    - Estimativa de distância entre o nó atual e o objetivo