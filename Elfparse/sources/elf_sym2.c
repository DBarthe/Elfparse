/*
** elf_sym2.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Thu Mar 13 21:03:13 2014 Barthelemy Delemotte
** Last update Thu Mar 13 21:04:35 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>

#include		"elfparse_int.h"

size_t			elf_sym_get_size(t_elf *elf, t_elf_sym *sym)
{
  if (ELF_IS_32(elf))
    return ((size_t)sym->_32.st_size);
  return ((size_t)sym->_64.st_size);
}
