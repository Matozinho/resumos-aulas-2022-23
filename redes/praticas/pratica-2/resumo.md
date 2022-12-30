# Execução

Validação de métodos http

Arquivo pequeno - cabe dentro de um pacote
200 - retorno de todos os dados do html + favicon
mensagens em pares -> Requisição + retorno

304 - conteúdo com cache
Diferença -> If-Modified-Since: Tue, 18 Oct 2022 05:59:01 GMT\r\n

Arquivo grande

Qual o tamanho do pacote?
Em geral 1500 bytes
Quebra em vários pacotes -> quem quebra é o tcp

Trabalhar com documentos com vários obj
Se arquivos em diferentes servidores, então tem q abrir conexão com todos os servidores relacionados para buscar o arquivo
um get para cada obj

Quando precisa ser autenticado
401 - unauthorized
coloca senha
Manda no Authorization do Header
retorna http 200

HTTP2