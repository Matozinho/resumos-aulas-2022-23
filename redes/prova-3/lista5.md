# Lista 5

1. Se todos os enlaces da Internet fornecessem serviço confiável de entrega, o serviço confiável de entre- ga TCP seria redundante? Justifique sua resposta.\
**R.:** Se todos os enlaces da Internet fornecessem um serviço confiável de entrega, o serviço confiável de entrega TCP (Transmission Control Protocol) ainda teria sua relevância e importância, mas poderia ser considerado redundante em alguns contextos específicos. Garantia de Ordem: O TCP garante a entrega ordenada dos dados. Mesmo que todos os enlaces possam entregar os pacotes de forma confiável, a rede ainda pode rotear pacotes por caminhos diferentes, o que pode levar a variações de latência e ordem de chegada. O TCP garante que os pacotes sejam reorganizados na ordem correta, garantindo a integridade dos dados.
No entanto, é importante destacar que, em uma rede com todos os enlaces fornecendo um serviço confiável de entrega, alguns dos recursos de recuperação de erros e retransmissão de pacotes do TCP podem não ser necessários. Nesse cenário, outros protocolos de transporte mais leves e voltados para desempenho, como o UDP (User Datagram Protocol), podem ser preferidos para determinadas aplicações que requerem velocidade e baixa latência, desde que a tolerância a perdas seja aceitável para essas aplicações específicas.


2. Cite alguns possíveis serviços que um protocolo de camada de enlace pode oferecer à camada de rede. Quais desses serviços de camada de enlace têm serviços correspondentes no IP? E no TCP?\
Dentre os serviços oferecidos pela camada de enlace, estão:
- **Transmissão confiável de quadros:** Garante que os quadros sejam entregues corretamente, sem erros, perdas ou duplicatas.
- **Controle de Fluxo:** Evita que um dispositivo de destino mais rápido sobrecarregue um dispositivo de destino mais lento, regulando o tráfego de quadros.
- **Controle de Erros:** Detecta e corrige erros nos quadros durante a transmissão.
- **Delimitação de Quadros:** Define limites claros para identificar o início e o fim de cada quadro na transmissão.
- **Endereçamento Físico:** Fornece um mecanismo para identificar os dispositivos conectados na rede usando endereços MAC (Media Access Control).
**Enquadramento:** Empacota os datagramas da camada de rede em quadros que podem ser transmitidos pela camada física.
Desses serviços, os correspondentes com o IP são o endereçamento lógico. Já os correspondentes com o TCP são a transmissão confiável, o controle de fluxo e o controle de erros.

7. Que tamanho tem o espaço de endereço MAC? E o espaço de endereço IPv4? E o espaço de endereço IPv6?\
**R.:** O endereço MAC conta com 48bits para endereçamento, ou seja, pode contar com $2^{48}$ endereços. O IPv4 conta $2^{32}$ bits, enquanto o IPv6 tem $2^{128}$ endereços.

8. Suponha que cada um dos nós A, B e C esteja ligado à mesma LAN broadcast (por meio de seus adap- tadores). Se A enviar milhares de datagramas IP a B com quadro de encapsulamento endereçado ao endereço MAC de B, o adaptador de C processará esses quadros? Se processar, ele passará os datagra- mas IP desses quadros para C (isto é, para o nó pai do adaptador)? O que mudaria em suas respostas se A enviasse quadros com o endereço MAC de broadcast?\
**R.:** O adaptador de C processará esse quadro, mas não passará os datagramas IP para C. Se A enviasse quadros com o endereço MAC de broadcast, o adaptador de C processaria o quadro e passaria os datagramas IP para C.

9. Por que uma pesquisa ARP é enviada dentro de um quadro broadcast? Por que uma resposta ARP é enviada dentro de um quadro com um endereço MAC de destino específico?\
**R.:** Uma pesquisa ARP (Address Resolution Protocol) é enviada dentro de um quadro broadcast porque, no momento em que o remetente precisa enviar um pacote IP para um destino na mesma rede local, ele não possui o endereço MAC do destino para encapsular o pacote corretamente no quadro. Quando o nó de destino recebe a solicitação ARP, ele responde diretamente ao nó remetente que fez a pesquisa ARP anteriormente. Assim, o remetente obtém o endereço MAC do destino e pode, em seguida, encapsular o pacote IP no quadro Ethernet correto para a entrega direta ao destinatário desejado. A resposta é feita diretamente ao remetente, para que o mesmo possa armazenar o endereço MAC do destinatário em seu cache ARP e não precise fazer uma nova pesquisa ARP para o mesmo destinatário em um futuro próximo.

1.  Fé com fé irmão