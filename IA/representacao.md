## Representação

  - Espaços de busca
  - Espaço de Estados
  - Algoritmos de busca (cega e heurística)
  - Lógica
  - 
  - O Computador precisa de um meio para representar o mundo real para poder solucionar um problema
  - A representação utilizada para u problema é muito importante
    - Necessidade de representação realista
    - Aproximação
    - Atrelada ao objetivo do método
  - Essa importância é verificada em todos os problemas que a IA resolve
  - A representação que será utilizada deve ser útil, eficiente e significativa
    - Eficácia em resolver o problema
    - Eficiente em termos computacionais (redução de custo)
    - Deve representar um comportamento inteligente/real

### Representações

  - Procedural
    - representado em forma de funções/procedimentos
    - Mover objeto da posição A para posição B
  - Redes semânticas
    - Conhecimento representado por grafo consistido em vértices e conectados por arestas
    - Vértices são as "classes"
    - Arestas são as características que ligam a classe
  - Quadros e Roteiros
    - Visão coputacional
  - Lógica (declarativa)
    - Modo de declaração que apresenta o conhecimento
    - Ex: Primo(Pedro,Marcia)
  - Árvores de Decisão
    - Conceitos organizados em forma de árvore
    - "if else"
  - Conhecimento Estatístico
    - uso de fatores de certeza, Redes Bayesianas, Lógica Fuzzy, etc.
  - Regras
    - Sistemas de produção para codificar regras de condição/ação
  - Casos (RBC)
    - experiência passada, acumulando casos e tentando descobrir por analogia, soluções para outros problemas
    - Adicionar novas experiências
    - Analogia para tomar decisões (em casos nunca vistos)
  - Esquemas hibridos
    - utiliza mais de uma representação
  - Herança
    - o conhecimento é representado em objetos com linguagens orientadas a objetos
    - Cria classe, coloca atributos e descreve como interage com o ambiente
  - Árvore semântica
    - Representada de forma hieráquica
    - Semelhante à rede semântica

## Espaços de Busca

  - É uma representação do conjunto de possíveis escolhas de um dado problema, uma ou mais das quais é a solução do problema
  - O número de soluções dos problemas que a IA resolve é expresso, em geral, em termos de N! ou $a^n$
  - Tentar localizar uma palavra específica em um dicionário com 100 páginas há o espaço de busca consistirá em cada uma das 100 páginas
  - espaço de estados:
    - conjunto de estados, conectados por caminhos que representam ações

## Representação do Conhecimento

  - 4 partes
  - Representação Léxica
    - Determina que símbolos são permitidos no vocabulário de representação
  - Estrutural
    - O que é possível de ser feito
  - Procedural
    - Descreve as restrições de como os símbolos podem ser manipulados, definido prodcedimentos que possibilitam criar e modificar descrições e responder questões utilizando descrições

### Sistemas de produção ou regras de produção
  - descrever uma família de sistemas
  - Conjunto de regras pra definir determinados problemas
  - constituídos de regras que reúnem condições e ações
  - Regras do tipo if-then-else