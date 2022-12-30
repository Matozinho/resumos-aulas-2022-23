# Capítulo 1

1. Qual é a diferença entre um hospedeiro e um sistema final? Cite tipos de sistemas finais. Um servidor Web é um sistema final? \
  **R.:** Hospedeiros e sistema final são sinônimos. Um **hospedeiro** ou **sistema final** é qualquer dipositivo que esteja conectado à rede e esteja rodando um sistema. Dois exemplos são notebooks e celulares. Um servidor Web é um sistema final, porque ele está na borda e recebe/envia informação para outros sistemas conectados a internet.

3. O que é um programa cliente? O que é um programa servidor? Um programa servidor requisita e recebe serviços de um programa cliente? \
  **R.:** Um programa cliente é uma aplicação que funciona em um hospedeiro ou sistema final, solicitando e enviando informações a outro sistema final na rede, enquanto o sistema que responde a essas solicitações é o programa servidor. Um programa servidor somente recebe serviços de um programa cliente.

4. Quais são os dois tipos de serviços de transporte que a Internet provê às suas aplicações? Cite algumas características de cada um desses serviços. \
   **R.:** A internet provê os serviços **TCP** e **UDP** para as aplicações. 
   - O **TCP** é um serviço confiável de transporte e orientado a conexão, que garante a entrega de dados e a ordem de chegada dos pacotes. Além disso, garante também um controle de congestionamento. 
   - O **UDP** é um serviço não orientado a conexão, que não garante a entrega de dados e a ordem de chegada dos pacotes, também não tem a apresentação entre o solicitante e o receptor.
  
5. Afirma-se que controle de fluxo e controle de congestionamento são equivalentes. Isso é válido para o serviço orientado para conexão da Internet? Os objetivos do controle de fluxo e do controle de congestionamento são os mesmos? \
   **R.:** Essa afirmação não é valida, pois os objetivos do **controle de fluxo** e **controle de congestionamento** são, respectivamente, o emissor não enviar mais dados que a capacidade do receptor, evitando problemas como excesso de informação ao receptor; a diminuição da taxa de transmissão de um emissor para evitar congestionamento na rede como um todo.

7. Qual é a vantagem de uma rede de comutação de circuitos em relação a uma de comutação de pacotes? Quais são as vantagens da TDM sobre a FDM em uma rede de comutação de circuitos? \
   **R.:** Em uma rede de comutação de circuitos há a vantagem de redução no atraso, pois não há a necessidade de roteamento, pois o circuito é reservado para o emissor e receptor,sendo ideal para comunicações em tempo real. As vantagens da TDM sobre a FDM são:
   - Funcionamento com sinais analógicos e digitais.
   - Baixo conflito de sinais;
   - Mais eficiente;
  
11. Suponha que você esteja desenvolvendo o padrão para um novo tipo de rede de comutação de pacotes e precisa decidir se sua rede usará Circuito Virtual (CVs) ou roteamento de datagramas. Quais são os prós e os contras da utilização de CVs? \
  **R.:** Os circuitos virtuais são mais confiáveis, garante os recursos necessários para o seu tráfego e necessita apenas um cabeçalho, enquanto o roteamento por datagramas tem como desvantagem a necessidade de cada pacote necessitar um cabeçalho e ser menos confiável, porém ele é mais barato para ser implementado.

13.  Qual é principal diferença que distingue ISPS de nível 1 e de nível 2? \
  **R.:** Um ISP de nível 1 é aquele que conecta as redes de um ISP de de nível 2, sendo o nível mais alto conectando o mundo todo. Um ISP de nível 2 é aquele que conecta as redes de um ISP de nível 3 às de nível 1, chamada tmb de ISP regional.

14. Qual é a diferença entre um POP e um NAP? \
  **R.:** 