/*
** elf_symtab.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar 11 12:36:07 2014 Barthelemy Delemotte
** Last update Tue Mar 11 13:50:06 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>

#include		"elfparse_int.h"

static size_t		elf_get_symsize(t_elf *elf)
{
  if (ELF_IS_32(elf))
    return (sizeof(Elf32_Sym));
  return (sizeof(Elf64_Sym));
}

int			elf_symtab_get_sym(t_elf *elf, t_elf_section *symtab,
					   size_t index, t_elf_sym **sym_ptr)
{
  ssize_t		sym_num;
  size_t		sym_size;

  *sym_ptr = NULL;
  if ((sym_num = elf_symtab_get_symnum(elf, symtab)) == -1)
    return (-1);
  if (index >= (size_t)sym_num)
    {
      fprintf(stderr, "%s: invalid reference to symbols table\n",
	      elf->filename);
      return (-1);
    }
  sym_size = elf_get_symsize(elf);
  *sym_ptr = (t_elf_sym *)&symtab->content[index * sym_size];
  return (0);
}

ssize_t			elf_symtab_get_symnum(t_elf *elf, t_elf_section *symtab)
{
  size_t		sym_size;
  size_t		symtab_size;

  sym_size = elf_get_symsize(elf);
  symtab_size = elf_section_get_size(elf, symtab);
  if (symtab_size % sym_size != 0)
    {
      fprintf(stderr, "%s: invalid symbol table size\n", elf->filename);
      return (-1);
    }
  return (symtab_size / sym_size);
}
