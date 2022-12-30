1. Relacione cinco aplicações da Internet não proprietárias elas usam. e os protocolos de camada de aplicação que elas usam. \
  **R.:** Web – HTTP. \
  Email – SMTP, POP e IMAP. \
  Streaming – RTP \
  Servidor de arquivos – NFC \
  Conexão remota – SSH \
  Troca de arquivos – FTP 

3. De que modo mensagem instantânea é um híbrido das arquiteturas cliente-servidor e P2P? \
  **R.:** Pq a comunicação é feita peer to peer, a mensagem é enviada direto para o cliente, enquanto o servidor é utilizado para armazenar os dados e buscar dados dos usuários.

4. Para uma sessão de comunicação entre um par de processos, qual processo é o cliente e qual é o servidor?
  **R.:** O processo cliente é aquele que requisita uma informação, ou seja, quem inicia a comunicação. O processo servidor é quem disponibiliza a informação respondendo à requisição.

5. Em uma aplicação de compartilhamento de arquivos P2P, você concorda com a afirmação: "não existe nenhuma noção de lados cliente e servidor de uma sessão de comunicação"? Por que sim ou por que não?
  **R.:** Não porque no compartilhamento de arquivos P2P, um processo pode ser ambos, cliente e servidor; um processo pode carregar e descarregar arquivos, mesmo assim no contexto de qualquer dada sessão entre um par de processos ainda podemos rotular um processo de cliente e o outro de servidor; quem inicia a comunicação é o cliente e quem espera ser contatado para iniciar a sessão é o servidor.

6. Que informação é usada por um processo que está rodando em um hospedeiro para identificar um processo que está rodando em outro hospedeiro?
  **R.:** No caso da arquitetura TCP/IP utiliza-se o endereço IP(endereço de rede) e a porta(UDP ou TCP).

9. O que significa protocolo de apresentação (handshaking protocol)?
  **R.:** É uma conexão Internet existente usando protocolos, cujo pontos trocam primeiramente pacotes de controle antes de trocarem pacotes de dados.

10. Por que HTTP, FTP, SMTP, POP3 e IMAP rodam sobre TCP e não sobre UDP?
  **R.:** Por que os serviços citados necessitam de conexão, logo o TCP é um serviço orientado a conexão, enquanto o UDP é um serviço sem conexão.

12. Qual é a diferença entre HTTP persistente com paralelismo e HTTP persistente sem paralelismo? Qual dos dois é usado pelo HTTP/1.1?
  **R.:** Na versão sem paralelismo, o cliente emite uma nova requisição somente quando a resposta anterior foi recebida. Nesse caso, o cliente sofre um RTT para requisitar e receber cada um dos objetos referenciados.
  Na versão com paralelismo, o cliente HTTP emite uma requisição logo que encontra uma referência. Assim, pode fazer requisições seqüenciais para os objetos relacionados, isto é, pode fazer uma nova requisição antes de receber uma resposta a uma requisição anterior. Quando o Servidor recebe as requisições seqüenciais, envia os objetos seqüencialmente. Com paralelismo é possível gastar somente um RTT para todos os objetos referenciados.
  No HTTP/1.1 é usado o HTTP persistente sem paralelismo.

13. Descreva como o cache Web pode reduzir o atraso na recepção de um objeto desejado. O cache Web reduzirá o atraso para todos os objetos requisitados por um usuário ou somente para alguns objetos? Por quê?
  **R.:** O cache web reduz o atraso pois verifica primeiro se objeto está armazenado localmente antes de requisitar à origem, devolvendo a cópia local, reduzindo o atraso. Somente para alguns, pois se não estiver armazenado localmente, terá de buscá-lo na origem

15. Por que se diz que o FTP envia informações de controle 'fora da banda??
  **R.:** Porque o FTP usa uma conexão de controle separada. O FTP usa duas conexões TCP paralelas para transferir um arquivo: uma conexão de controle e uma conexão de dados. A primeira é usada para enviar informações de controle entre os dois hospedeiros – como identificação de usuário, senha, comandos para trocar diretório remoto e comandos de “inserir” e ”pegar” arquivos. A conexão de dados é a usada para efetivamente enviar ou receber um arquivo.

16. Suponha que Alice envie uma mensagem a Bob por meio de uma conta de e-mail da Web (como o Hotmail), e que Bob acesse seu e-mail por seu servidor de correio usando POP3. Descreva como a mensagem vai do hospedeiro de Alice até o hospedeiro de Bob. Não se esqueça de relacionar a série de protocolos de camada de aplicação usados para movimentar a mensagem entre os dois hospedeiros.
  **R.:** A mensagem é enviada de Alice para seu servidor de email através de HTTP. O servidor de email de Alice envia a mensagem ao servidor de email de Bob sobre SMTP. Bob então transfere a mensagem do seu servidor de email para o seu host utilizando POP3.

1. Verdadeiro ou Falso
   1. Falso - uma úinica resposta
   2. Verdadeiro - mesmo domínio
   3. Falso - não persistente
   4. Falso - Modified since

2. CDUP - Change to Parent Directory
  SMNT - Structure Mount
  STOU - Store Unique
  RMD - Remove Directory
  MKD - Make Directory
  PWD - Print Directory
  SYST - System

3. Visite http://www.iana.org. Quais são os números de porta bem conhecidos para o protocolo simples de transferência de arquivos (STFP)? E para o protocolo de transferência de notícias pela rede (NNTP)?
  **R.:** SFTP - 22, NNTP - 119

4. Considere um cliente HTTP que queira obter um documento Web em um dado URL. Inicialmente, o endereço IP do servidor HTTP é desconhecido. O documento Web no URL tem uma imagem GIF inserida que reside no mesmo servidor do documento original. Nesse cenário, quais protocolos de transporte e de camada de aplicação são necessários, além do HTTP?
  **R.:** UDP, TCP e DNS.

5. Obtenha a especificação HTTP/1.1 (RFC 2616). Responda às seguintes perguntas:
  a. Explique o mecanismo de sinalização que cliente e servidor utilizam para indicar que uma conexão persistente está sendo fechada. O cliente, o servidor, ou ambos, podem sinalizar o encerramento de uma conexão?
  **R.:** Tanto o cliente quanto o servidor podem encerrar uma conexão. Para isso basta sinalizar a intenção incluindo no cabeçalho o campo “connection; close”.
  b. Que serviços de criptografia são providos pelo HTTP?
  **R.:** SSL