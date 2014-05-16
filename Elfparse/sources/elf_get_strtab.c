/*
** elf_get_strtab.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed Mar  5 12:08:39 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:00:34 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

#include		"elfparse_int.h"

/*
** Set 'section_ptr' to the address of the section corresponding to the strtab.
** If there is no strtab, 'section_ptr' is set to NULL.
** Return -1 if an error occured, 0 otherwise
*/
int			elf_get_shstrtab(t_elf *elf,
					 t_elf_section **sections_ptr)
{
  size_t		shstrndx;

  shstrndx = elf_header_get_shstrndx(elf);
  if (shstrndx == SHN_UNDEF)
    *sections_ptr = NULL;
  else if (shstrndx >= elf_header_get_shnum(elf))
    {
      fprintf(stderr, "%s: invalid header: index of the strtab isn't"
	      " inferior than the number of sections\n", elf->filename);
      return (-1);
    }
  else
    *sections_ptr = &elf->sections[shstrndx];
  return (0);
}

/*
** Same as elf_get_strtab but returns the symbol strings table.
*/
int			elf_get_symstrtab(t_elf *elf,
					  t_elf_section **section_ptr)
{
  size_t		idx;
  size_t		shnum;
  t_elf_section		*section;
  const char		*name;

  shnum = elf_header_get_shnum(elf);
  idx = 0;
  while (idx < shnum)
    {
      section = &elf->sections[idx];
      if (elf_section_get_type(elf, section) == SHT_STRTAB)
	{
	  if (elf_section_get_name(elf, section, &name) == -1)
	    return (-1);
	  else if (name && strcmp(name, ".strtab") == 0)
	    {
	      *section_ptr = section;
	      return (0);
	    }
	}
      idx++;
    }
  *section_ptr = NULL;
  return (0);
}
