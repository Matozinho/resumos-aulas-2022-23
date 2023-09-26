# Parser Flex-Bison

O presente trabalho realiza a análise léxica e sintática de um arquivo de entrada, utilizando as ferramentas Flex e Bison.

A gramática da linguagem pode ser encontrada no arquivo `definition.pdf`. A saída da execução são os tokens encontrados e se o parse da gramática foi bem sucedido.

## Como rodar
Para compilar os arquivo utilize o comando:

```bash
make
```

Isso gerará o arquivo `analyse`. Para executá-lo, rode
  
```bash
./analyse <arquivo_de_entrada>
```

Exemplo:

```bash
./analyse tests/all.lng
```

## Limpeza

Para deixar somente os arquivos essenciais, rode

```bash
make clean
```
O presente código **não realiza** a geração do IR de 3 endereços.