1) Seguinte:\
  a) $R =2^p$\
    $R =2^3$\
    $R = 8bytes$

  b) $R = 2^p$\
    $R = 2^5$\
    $R = 32$ entradas

  c) $R = entradas * bytes$\
    $R = 32 * 1$\
    $R = 32$ bytes

  d) 0x00 -> 00000000 -> 00000|000\
    end fisico = 00011|000 -> 0001100 -> 0x18

  0x01 -> 00000001 -> 00000|001 \
  end fisico = 00011|001 -> 00011001 -> 0x19

  0x10 -> 00010000 -> 00010|000 \
  fisico = 00010|000 -> 00010000 -> 0x10

  0x07 -> 00000111 -> 00000|111 \
  fisico = 00011|111 -> 00011111 -> 0x1F

  0x08 -> 00001000 -> 00001|000 \
  fisico = 00001|000 -> 00001000 -> 0x08

  0x40 -> 01000000 -> 01000|000 \
  fisico = Endereço inválido

2) Seguinte\
  a) $2^n=1024$\
  $n=log_2(1024)$\
  $n=10$

  b) $2^p=4194304$, sendo $p=22$\
  $4MiB$

  c) $entradas * 4bytes$\
  $4MiB * 4bytes = 16MiB$

  d) dois níveis de 11 bits cada\
  cada tabela terá $2^{11} = 2048$ entradas\
  cada entrada terá 4 bytes\
  $2048 * 4 = 8192 bytes$ -> $8KiB$

  e) Para um nível, será armazenado $4MiB$\
  Para uma paginação de dois níveis, será necessário uma tabela de páginas de $8KiB$ para o primeiro nível e uma de $8KiB$ para o segundo nível, totalizando $16KiB$.

  f) $T_{md}$ = $\alpha$ * ($T_{TLB} + T_m$) + (1-$\alpha$) * ($T_{TLB} + (N\_niveis+1)*T_m$)

  $T_{TLB} = 20ns$\
  $T_M = 120ns$\
  $\alpha = 0.85$

  **Para 1 nível**\
  $T_{md}$ = $0.85 * (20 + 120) + (1-0.85) * (20 + 2*120)$\
  $T_{md}$ = $0.85 * 140 + 0.15 * 260$\
  $T_{md}$ = $119 + 39$\
  $T_{md}$ = $158ns$

  **Para 2 níveis**\
  $T_{md}$ = $0.85 * (20 + 120) + (1-0.85) * (20 + 3*120)$\
  $T_{md}$ = $0.85 * 140 + 0.15 * 380$\
  $T_{md}$ = $119 + 57$\
  $T_{md}$ = $176ns$
