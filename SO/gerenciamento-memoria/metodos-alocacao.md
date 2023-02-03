# Métodos de alocação

a) Alocação contígua

armazena de forma contígua na memória, como se fosse um array sequêncial

**registrador de realocação:** (diz onde começou o armazenamento físico para calcular o endereço lógico)

**Limite:** quantidade máxima de endereços que o programa pode gerar

vantagens:
- simples

desvantagens:
- Ter o espaço disponível, mas não de forma contígua (memória mal aproveitada)

## Problema da alocação dinâmica

decidir **como** colocar os programas na memória

a) fisrt fit: Aloca no primeiro espaço disponível q tiver \
b) best fit: Busca todos os espaços disponíveis e escolhe o que está mais próximo do tamanho do processo. (os espaços livres e acaba segmentando muito a memória) \
c) worst fit: Busca todos os espaços e escolhe o que sobra mais espaço

os estudos mostram que compensa usar o first fit msm, pois os outros métodos não apresentam muitos ganhos

## Compactação de memória ou desfragmentação

Consiste em realocar os processos para obter um espaço livre contiguo

pra fazer esse processo, é preciso congelar o sistema, atualizar os contextos e depois liberar

b) Segmentação

alocação => visão de programador

o programa passa a ter um segmento e não um bloco

não se pode quebrar um segmento, mas podem estar divididos na memória

CPU deixa de mandar só o endereço e passa a mandar uma tupla de segmento e endereço