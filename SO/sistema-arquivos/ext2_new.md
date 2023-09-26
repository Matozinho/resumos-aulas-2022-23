**ext2_new**

## **Superbloco**

**total_inodes** = 10240\
**total_blocks** = 20480\
**block_number_SB** = 0\
**block_size** = 1 => (1024 << 1 = 2048 bytes)\
**blocks_per_group** = 16384\
**inodes_per_group** = 5120 => Quantidade de entradas no inode table

## **BG0 - Group Descriptor**

**group_descriptor_begin** = 2048\
**block_bitmap_addr** = 21\
**inode_bitmap_addr** = 22\
**inode_table_addr** = 23

**inode_table_begin** = 47104\
**pointer_to_datablock_root** = 343

## **Entradas no root dir**

**data_block_begin** = 702464

**Entrada 1**\
end -> 702464\
inode -> 0x00000002\
entry_total_size -> 0x000C\
name_lenght -> 0x01\
type -> 0x02\
name -> "."

**Entrada 2**\
end -> 702476\
inode -> 0x00000002\
entry_total_size -> 0x000C\
name_lenght -> 0x02\
type -> 0x02\
name -> ".."

**Entrada 3**\
end -> 0x000AB818\
inode -> 0x0000000B\
entry_total_size -> 20\
name_lenght -> 10\
type -> 0x02\
name -> "lost+found"

**Entrada 4**\
end -> 0x000AB82C\
inode -> 0x00001401\
entry_total_size -> 40\
name_lenght -> 5\
type -> 0x02\
name -> "teste"

**Entrada 5**\
end -> 0x000AB854\
inode -> 0x0000000D\
entry_total_size -> 1964 bytes\
name_lenght -> 59\
type -> 0x01\
name -> "teste.txt"

## **Lendo arquivo teste.txt**

Descobrindo qual block group o inode 0x0000000D está\
**inode-addr** % **inodes_per_group** = 13 / 5120 = 0

**inode_table_begin** + 12 * 128 = 48640\
**file_size** = 8 bytes\
**pointer_to_datablock_root** = 1024\
**end_ini_file** = 2097152\
**file_content** = "abcdefg\n"
