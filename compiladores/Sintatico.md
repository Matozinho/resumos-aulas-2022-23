# Analisado Sintático (ou parser)

  - Revebe os tokens do analisador léxico e gera uma árvore sintática
  - Relaciona as partes e subpartes de um programa
  - Verificar se todas as estruturas de um comando estão presentes
  - Não há como impor restrição de distribuição no código fonte
    - variável duplicada
    - variável usada antes de ser declarada
  - A parte de contexto é feito na proxima etapa
  - Se preocupa com a sequência, mas não com o contexto

## Derivações

  - Contruir uma árvore usando derivações
  - top-down 
  - Tratar ambiguidade
  - 
    - Reesscrever a gramática
    - Definir orden de prioridade durante a derivação
  - Bottom-up
    - Redução (contrário da derivação)
    - Constrói a árvore a partir das folhas
    - 