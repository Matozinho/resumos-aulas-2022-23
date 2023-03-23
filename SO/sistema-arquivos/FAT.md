# FAT (File Allocation Table)

OS dev -> https://wiki.osdev.org/FAT

1 - Boot Record
2 - Tabela FAT
3 - Root Dir
4 - Dados (restante dos setores)

**Questões**

1) Como determinar o nº de tabelas FAT?\
   **R.:** O nº de tabelas FAT é determinado pelo campo "FATs" do BPB (BIOS Parameter Block). Fica no BR(16) e tem um tamanho de 1 byte. Normalmente é 2.
  
2) Quantos setores cada tabela FAT ocupa?\
   **R.:** O nº de setores ocupados por cada tabela FAT é determinado pelo campo "Sectors per FAT" do BPB. Está no BR(22) e tem tamanho de 2 bytes.

3) Quantas entradas tem o diretório raiz?\
   **R.:** O nº de entradas do diretório raiz é determinado pelo campo "Root entries" do BPB. Está no BR(17) e tem tamanho de 2 bytes.

4) Quantos setores ocupa o diretório raiz?\
   **R.:** 
   $root\_dir\_sectors = ((fat\_boot->root\_entry\_count * 32) + (fat\_boot->bytes\_per\_sector - 1)) / fat\_boot->bytes\_per\_sector;$

5) Como calcular as posições iniciais da FAT, ROOT DIR e dados?\
   **R.:**
  $first\_fat\_sector = fat\_boot->reserved\_sector\_count;$ 
  $first\_root\_dir\_sector = first\_data\_sector - root\_dir\_sectors;$
  $first\_data\_sector = fat\_boot->reserved\_sector\_count + (fat\_boot->table\_count * fat\_size) + root\_dir\_sectors;$

1) Quais informações são armazenadas no padrão 8.3? Quantos bytes ele ocupa?\
   **R.:** \
   [0 - 11]: O nome do arquivo, onde os 8 primeiros caracteres são o nome 3 a extensão. \
   [11 - 12]: Os atributos do arquivo, onde:
    READ_ONLY=0x01 HIDDEN=0x02 SYSTEM=0x04 VOLUME_ID=0x08 DIRECTORY=0x10 ARCHIVE=0x20 LFN=READ_ONLY|HIDDEN|SYSTEM|VOLUME_ID\
   [12 - 13]: reservado para uso do windows NT\
   [13 - 14]: Tempo de criação do arquivo em milésimos.\
   [14 - 16]: The time that the file was created. Multiply Seconds by 2.
    5 bits p hora | 6 bits para minuto | 5bits para segundo\
   [16 - 18]: Data de criação do arquivo.
   7 bits para ano | 4 bits para mês | 5 bits para dia\
   [18 - 20]: Data de último acesso (no mesmo formato da data de criação)\
   [20 - 22]: 16 bits mais significativos do cluster\
   [22 - 24]: último tempo de modificação (mesmo formato do tempo de criação)\
   [24 - 26]: Última data de modificação (mesmo formato da data de criação)\
   [26 - 28]: 16 bits menos significativos do cluster\
   [28 - 32]: Tamanho do arquivo em bytes\

**Tamanho da FAT varia de acordo com o disco**

## Inspecionando arquivo

- 512 bytes por setor -> 0X0B\
- 2 FATs -> 0x10 | 1byte\
- Cada fat tem 155 setores -> 0x16 | 2bytes\
- boot entry count: 512 -> 0x11 | 2bytes\
- Número total de setores = 400000 => 0x13 | 2bytes\
  - Se o endereço 0x13 tiver valor 0, a quantidade estará no 0x20 (arquivo contém mais de 65535 setores) 
### FAT 1
- Inicia no byte 512\

### FAT 2
- Inicia no byte 512 + 155 * 512 = 79872\

### Root Dir
- A partir da FAT 2, contar mais 155 setores\
- inicia no byte => 79872 + 155 * 512 = 159232\
- Root dir ocupa 32 setores -> 16384 bytes\
$(fat\_boot->root\_entry\_count * 32)/512 = (512 * 32)/512 = 32$
- **0x0F -> Long File name no atributo 11**

### Dados
- A partir do final Root Dir
- Root dir ocupa 32 setores -> 16384 bytes\
- Root dir inicia no byte 159232\
- Setor de dados inicia no byte 159232 + 16384 = 175616\


### Arquivo no Root Dir -> 8.3
**Arquivo 1**
- Atributo: 10 (diretório)
- Nome arquivo: "SUB     "
- Extensão: "   "
- First cluster: 3
- Tamanho: 0

**Arquivo 2**
- Atributo: 0x20 (ARCHIVE)
- Nome arquivo: "TESTE   "
- Extensão: "TXT"
- First cluster: (00 38) -> 56
- Tamanho: (00 00 04 4F) 1103 bytes

Para descobrir o cluster na tabela fat -> number_cluster * 2 + begin_Fat
0 Significa cluster livre
acima de FFF8 significa final
Na área de dados não existe cluster 0

Para pegar o deslocamento correto na área de dados, sempre subtrai 2
(cluster_namber - 2) * 512 + 175616 = 175616

54 * 512 + 175616 = 203264

**Diretório SUB**
- cluster 3 somente\
- Endereço na camada de dados: (cluster_namber - 2) * 512 + 175616 = -> 512 + 175616 = 176128

- Atributo: 0x10 (DIRECTORY)\
- Nome arquivo: ".        "\
- Extensão: "   "\
- First cluster: (00 03) -> 03\
- Tamanho: (00 00 00 00) 0 bytes

- Atributo: 0x10 (DIRECTORY)\
- Nome arquivo: "..       "\
- Extensão: "   "\
- First cluster: (00 00) -> 03\
- Tamanho: (00 00 00 00) 0 bytes

- Atributo: 0x10 (DIRECTORY)\
- Nome arquivo: "SUB2    "\
- Extensão: "   "\
- First cluster: (00 3B) -> 59\
- Tamanho: (00 00 00 00) 0 bytes

- Atributo: 0x20 (ARCHIVE)\
- Nome arquivo: "TESTE   "\
- Extensão: "TXT"\
- First cluster: (00 3C) -> 60\
- Tamanho: (00 00 04 4F) 1103 bytes
  - Clusters 3C, 3D, 3E
  - Dado do 3C: (60 - 2) * 512 + 175616 = 205312
  - Dado do 3D: (61 - 2) * 512 + 175616 = 205824
  - Dado do 3E: (62 - 2) * 512 + 175616 = 206336 

**Diretório SUB2**
- cluster 59 somente\
- Endereço na camada de dados: (cluster_namber - 2) * 512 + 175616 = -> 57 * 512 + 175616 = 204800

- Atributo: 0x10 (DIRECTORY)\
- Nome arquivo: ".        "\
- Extensão: "   "\
- First cluster: (00 3B) -> 59\
- Tamanho: (00 00 00 00) 0 bytes

- Atributo: 0x10 (DIRECTORY)\
- Nome arquivo: "..       "\
- Extensão: "   "\
- First cluster: (00 03) -> 03\
- Tamanho: (00 00 00 00) 0 bytes