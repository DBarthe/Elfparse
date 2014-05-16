/*
** elf_get_symtab.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar 11 12:27:41 2014 Barthelemy Delemotte
** Last update Tue Mar 11 14:19:36 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<string.h>

#include		"elfparse_int.h"

int			elf_get_symtab(t_elf *elf, t_elf_section **section_ptr)
{
  size_t		shnum;
  size_t		idx;
  t_elf_section		*section;
  const char		*name;

  *section_ptr = NULL;
  shnum = elf_header_get_shnum(elf);
  idx = 0;
  while (idx < shnum)
    {
      section = &elf->sections[idx];
      if (elf_section_get_type(elf, section) == SHT_SYMTAB)
	{
	  if (elf_section_get_name(elf, section, &name) == -1)
	    return (-1);
	  else if (name && strcmp(name, ".symtab") == 0)
	    {
	      *section_ptr = section;
	      return (0);
	    }
	}
      idx++;
    }
  return (0);
}
