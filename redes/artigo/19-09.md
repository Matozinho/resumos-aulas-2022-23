# Host Software - Steve Crocker

### Dúvidas

  - Os links já existem, mesmo sem ter comunicação entre os hosts?
  - Links são dual channel?
  - Buscar a história recente de um link é ver as mensagens que foram enviadas através dele?
  - Pq 18 tabelas em cada host? Só posso me conectar a 18 hosts?

### 

  - Interface Message Processor - IMP
  - Network Measurement Center - NMC
  - Request for Next Message - RFNM

## Intro

  - Reuniçoes entre os representantes dos 4 siteis iniciais para discutir o software host de rede
  - Gerard DeLoche trabalhou na interface do HOST-IMP

## The IMP Software

  **Mensagens:**
  - Informações transmitidas de Host a Host em pacotes
  - São qualquere stream de dados menores de 8080 bits, juntamente ao header
  - O Header contém 16 bits e organizados do seguinte modo:
    - 5 bits: Destino
      - código numérico do host que receberá a mensagem
    - 8 bits: Link
    - 1 bit: Trace
      - Avisa se o IMP deve guardar a mensagem e enviá-la de volta ao NMC
    - 2 bits: Spare
      - Não são usados

  **Links:**
  - Dispositivo usado pelo pelos IMPs para limitar congestionamentos;
  - Mensagens podem ser passadas em qlqr direção;
  - Full-Duplex communication
    - Envio e recebimento simultâneo de mensagens
  - Sempre há 32 conexões lógicas para cada **par de hosts**
    - Independente de serem usadas ou não
    - Cada IMP deve conter 18 tabelas, cada uma com 32 entradas
  - Os IMPs bloqueiam os links de modo que nenhum host possa mandar duas mensagens seguidas no mesmo link;
  - Para desbloquear um link, o destinatário deve mandar uma mensagem RFNM;
  - IMPs estão sempre preparados para transmitir outra mensagem através do link
  - Não há noção de início e fim de conversa entre links, logo, não há como saber o estado de uma conversa
    - Entretanto é possível buscar a história recente de um link

  **IMP: Transmissão e Error Checking:**
  - Para enviar a mensagem de um IMP para outro, a mensagem é divida em um ou mais pacotes
    - Cada pacote tem no máximo 1010 bits
    - Os pacotes são enviado s de IMP para IMP
  - 24 bit ciclic checksum é calculado para cada pacote
    - É enviado junto com o pacote
    - O IMP que recebe o pacote calcula o checksum e compara com o checksum enviado
    - Se forem diferentes, o pacote é descartado

## Requisitos do Software Host-to-Host

  **Uso Simples:**
  - Considera-se um período de pouca atividade, até que a comunidade comece a usar o software
  - Um dos objetivos é estimular a utilização imediata por uma grande classe de users
  - Permitir que usuários utilizem essa rede com a mesma aplitude da rede telefônica
  - Transmitir arquivos, talvez como simulando um tty.
  
  **Uso Profundo:**
  - Um dos problemas é que host precisará de cerca de meio segundo para enviar uma mensagem
  - A utilização de uma organização half-duplex melhoraria a comunicação via tty, mas destruiria algumas das utilidades da rede
  - Considerando utlizações gráficas ou mais sofisticadas, o problema é pior

  **Error Checking:**
  - Host to host checking
  - Hardware de transmissão Host-IMP

## O Software de Host

  **Estabelecimento de conexão:**
  - link 0 é reservado para comunicação entre o SO dos hosts
    - As outras 31 conexões podem ser usadas a vontade
  - O SO de cada host deve prover programas para estabelecer e finalizar a conexão
    - Quando essas primitivas são iniciadas o SO seleciona um link livre
    - Envia uma mensagem via link 0 para para o host remoto solicitando a conexão do link escolhido
  - Caso os dois hosts realizem a solicitação de um link livre ao mesmo tempo
    - Uma tabela de prioridade simples, onde o host com menos prioridade deve deixar a requisição;
    - Um dos meios para definir essa prioridade é pelo id
    - As ações são complementares:
      - O HOST de prioridade mais alta desconsidera a solicitação, enquanto o HOST de prioridade mais baixa envia uma aceitação e outra solicitação.

  **Transmissão de auto volume:**
  - file-like connection deve ser feita paralela ao tty-like connection
  - O host de maior prioridade manda através do link 0, enquanto o de menor prioridade espera pela tranmissão
  - file-like links não tem pesquisa de caractere de interrupção e técnicas de buffer apropriadas para alta transmissão de dados

  **Resumo das Primitivas:**
  Todo host deve prover, no mínimo, as seguintes primitivas para o usuário:
  
  - Iniciar conexão tty-like com outro host
  - Terminar a conexão
  - Enviar e receber caracteres em tty-like connection
  - Iniciar conexões file-like paralela a tty-like connection
  - Terminar conexões file-like
  - Enviar e receber dados em file-like connection

  **Error Checking:**
  - Propsta: Cada mensagem carregar um número, quantidade de bit e um checksum no body que será transparente ao IMP
  - Checksum: 16 bits end-around-carry sum computada em 1152 bits e shift circuçar à direita de 1 bit

  **Fechamento de Interações:**
  - Criar um buffer de de caracteres e somente quando um enter for pressionado, a string pe processada
  - Implementar essa solução criando uma linguagem para controle de console