# Segundo arquivo

1 -> Processar Boot Record

**bytes_per_sector** = 512\
**sectors_per_cluster** = 4\
**reserved_sectors** = 4\
**number_of_fats** = 2\
**root_directory_entries** = 512\
**total_sectors** = 40960\
**sectors_per_fat** = 40\

2 -> Calcular início da FAT1, FAT2, root_dir e data_sector

**FAT1_begin** = sector 4 (2048)\
**FAT2_begin** = sector 4 + 40 => 44 (22528)\
**root_directory_begin** = sector 44 + 40 => 84 (43008)\
**data_sector** = root_dir_begin + root_dir_sectors => 84 + 32 => 116 (59392)
  root_dir_sectors = (root_directory_entries * 32) / bytes_per_sector => (512 * 32) / 512 => 32

3 -> Obter arquivos no root dir

**File 1**\
- Atributo: 10 (diretório)\
- Name: "SUBDIR  "\
- Extension: "   "\
- First Cluster: 00 0D (13)\
- Size: 00 00 00 00

**File 2**\
- Atributo: 20 (ARCHIVE)\
- Name: "TESTE   "\
- Extension: "C  "\
- First Cluster: 00 05 (5)\
- Size: 00 00 10 F5 (4341)

**File 3**\
- Atributo: 20 (ARCHIVE)\
- Name: "TESTE1  "\
- Extension: "C  "\
- First Cluster: 00 0A (10)\
- Size: 00 00 17 29 (5929)

**Conteúdo do arquivo TESTE.C**\
- Clusters: 00 05 | 00 06 | 00 07
- End cluster 00 05: 
  - (cluster_number - 2) * 4 + data_sector => (5 - 2) * 4 + 116 = 128 (65536)
- End cluster 00 06:
  - (cluster_number - 2) * 4 + data_sector => (6 - 2) * 4 + 116 = 132 (67584)
- End cluster 00 07:
  - (cluster_number - 2) * 4 + data_sector => (7 - 2) * 4 + 116 = 136 (69632)

**Conteúdo do arquivo TESTE1.C**\
- Clusters: 00 0A | 00 0B | 00 0C
- End cluster 00 0A:
  - (cluster_number - 2) * 4 + data_sector => (10 - 2) * 4 + 116 = 148 (75776)
- End cluster 00 0B:
  - (cluster_number - 2) * 4 + data_sector => (11 - 2) * 4 + 116 = 152 (77824)
- End cluster 00 0C:
  - (cluster_number - 2) * 4 + data_sector => (12 - 2) * 4 + 116 = 156 (79872)

**Conteúdo do Diretório SUBDIR**\
- Clusters: 00 0D
- Início do cluster 00 0D:
  - (cluster_number - 2) * 4 + data_sector => (13 - 2) * 4 + 116 = 160 (81920)

**File 1**\
- Atributo: 10 (diretório)\
- Name: ".       "\
- Extension: "   "\
- First Cluster: 00 0D (13)\
- Size: 00 00 00 00

**File 2**\
- Atributo: 10 (diretório)\
- Name: "..      "\
- Extension: "   "\
- First Cluster: 00 00 (0)\
- Size: 00 00 00 00

**File 3**\
- Atributo: 10 (diretório)\
- Name: "SUBSUB~1"\
- Extension: "   "\
- First Cluster: 00 11 (17)\
- Size: 00 00 00 00

**File 4**\
- Atributo: 20 (ARCHIVE)\
- Name: "SMALL   "\
- Extension: "TXT"\
- First Cluster: 00 10 (16)\
- Size: 00 00 00 06

**Conteúdo do arquivo SMALL.TXT**\
- Clusters: 00 10
- End cluster 00 0A:
  - (cluster_number - 2) * 4 + data_sector => (16 - 2) * 4 + 116 = 172 (88064)

**Conteúdo do Diretório SUBSUB~1**\
- Clusters: 00 11
- Início do cluster 00 11:
  - (cluster_number - 2) * 4 + data_sector => (17 - 2) * 4 + 116 = 176 (90112)
