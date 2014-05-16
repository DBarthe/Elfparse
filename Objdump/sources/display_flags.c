/*
** display_flags.c for objdump in /home/bade/Dev/tek2/Unix/PSU_2013_nmobjdump/Objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Fri Mar 14 13:09:58 2014 Barthelemy Delemotte
** Last update Sun Mar 16 17:46:19 2014 Barthelemy Delemotte
*/

#include		<stdbool.h>
#include		<stdio.h>

#include		"objdump.h"

void			display_flags(unsigned int flags)
{
  int			ret;

  ret = 0;
  if (flags == BFD_NO_FLAGS)
    printf("BFD_NO_FLAGS");
  else
    {
      ret |= _F(flags, HAS_RELOC, ret);
      ret |= _F(flags, EXEC_P, ret);
      ret |= _F(flags, HAS_LINENO, ret);
      ret |= _F(flags, HAS_DEBUG, ret);
      ret |= _F(flags, HAS_SYMS, ret);
      ret |= _F(flags, DYNAMIC, ret);
      ret |= _F(flags, WP_TEXT, ret);
      ret |= _F(flags, D_PAGED, ret);
    }
  printf("\n");
}

static bool		elf_has_section_type(t_elf *elf, uint32_t type)
{
  size_t		idx;
  size_t		shnum;

  idx = 0;
  shnum = elf_header_get_shnum(elf);
  while (idx < shnum)
    {
      if (elf_section_get_type(elf, &elf->sections[idx]) == type)
	return (true);
      idx++;
    }
  return (false);
}

unsigned int		calc_flags(t_elf *elf)
{
  t_elf_section		*section;
  unsigned int		flags;

  flags = BFD_NO_FLAGS;
  if (elf_header_get_type(elf) == ET_EXEC)
    flags |= EXEC_P;
  if (elf_has_section_type(elf, SHT_REL))
    flags |= HAS_RELOC;
  if (!(flags & EXEC_P) && elf_has_section_type(elf, SHT_RELA))
    flags |= HAS_RELOC;
  if (elf_get_symtab(elf, &section) == 0 && section)
    flags |= HAS_SYMS;
  if (elf_has_section_type(elf, SHT_HASH))
    flags |= D_PAGED;
  return (flags);
}
