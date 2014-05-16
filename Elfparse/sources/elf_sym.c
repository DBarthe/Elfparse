/*
** elf_sym.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar 11 13:30:58 2014 Barthelemy Delemotte
** Last update Thu Mar 13 21:04:05 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>

#include		"elfparse_int.h"

int			elf_sym_get_name(t_elf *elf, t_elf_sym *sym,
					 const char **name_ptr)
{
  t_elf_section		*symstrtab;
  size_t		index;

  *name_ptr = NULL;
  if (elf_get_symstrtab(elf, &symstrtab) == -1)
    return (-1);
  if (symstrtab == NULL)
    return (0);
  if (ELF_IS_32(elf))
    index = sym->_32.st_name;
  else
    index = sym->_64.st_name;
  if (elf_strtab_get(elf, symstrtab, index, name_ptr) == -1)
    return (-1);
  return (0);
}

size_t			elf_sym_get_value(t_elf *elf, t_elf_sym *sym)
{
  if (ELF_IS_32(elf))
    return ((size_t)sym->_32.st_value);
  return ((size_t)sym->_64.st_value);
}

unsigned char		elf_sym_get_info(t_elf *elf, t_elf_sym *sym)
{
  if (ELF_IS_32(elf))
    return (sym->_32.st_info);
  return (sym->_64.st_info);
}

unsigned char		elf_sym_get_other(t_elf *elf, t_elf_sym *sym)
{
  if (ELF_IS_32(elf))
    return (sym->_32.st_other);
  return (sym->_64.st_other);
}

uint16_t		elf_sym_get_shndx(t_elf *elf, t_elf_sym *sym)
{
  if (ELF_IS_32(elf))
    return (sym->_32.st_shndx);
  return (sym->_64.st_shndx);
}
