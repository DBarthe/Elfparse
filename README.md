Elfparse
========

Elf parsing library, and small implementation of objdump and nm. 


Usage
-----------

To compile :
~~~bash
$ make
~~~

To run :
~~~
$ ./my_objdump my_nm
my_nm:     file format elf64-x86-64
architecture: i386:x86-64, flags 0x00000112:
EXEC_P, HAS_SYMS, D_PAGED
start address 0x0000000000400b88

Contents of section .interp:
 400200 2f6c6962 36342f6c 642d6c69 6e75782d  /lib64/ld-linux-
 400210 7838362d 36342e73 6f2e3200           x86-64.so.2.    
Contents of section .note.ABI-tag:
 40021c 04000000 10000000 01000000 474e5500  ............GNU.
 40022c 00000000 02000000 06000000 1a000000  ................
Contents of section .note.gnu.build-id:
 40023c 04000000 14000000 03000000 474e5500  ............GNU.
 40024c 574e3932 090a1882 93631b90 6a6aa7ec  WN92.....c..jj..
 40025c fb931c1c                             ....            
Contents of section .hash:
 400260 11000000 1b000000 02000000 00000000  ................
...
$ ./my_nm my_objdump
./my_objdump:
0000000000603aa8 d _DYNAMIC
0000000000603c90 d _GLOBAL_OFFSET_TABLE_
0000000000402d88 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 w _Jv_RegisterClasses
0000000000403a88 r __FRAME_END__
0000000000603aa0 d __JCR_END__
0000000000603aa0 d __JCR_LIST__
0000000000603d50 D __TMC_END__
0000000000603d50 A __bss_start
0000000000603d40 D __data_start
0000000000400aa0 t __do_global_dtors_aux
...
~~~
