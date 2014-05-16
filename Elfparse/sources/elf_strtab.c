/*
** elf_strtab.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar 11 12:01:53 2014 Barthelemy Delemotte
** Last update Tue Mar 11 12:17:33 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>

#include		"elfparse_int.h"

/*
** Check if index is outside the strtable and if there is a null byte
*/
static int		verification(t_elf *elf, t_elf_section *strtab,
				     size_t index)
{
  size_t		size;

  size = elf_section_get_size(elf, strtab);
  if (index + 1 >= size)
    {
      fprintf(stderr, "%s: section name index is outside the strtab\n",
	      elf->filename);
      return (-1);
    }
  while (index < size)
    {
      if (strtab->content[index] == '\0')
	return (0);
      index++;
    }
  fprintf(stderr, "%s: string table entry has no final null byte\n",
	  elf->filename);
  return (-1);
}

/*
** Get a string entry in a string table
*/
int			elf_strtab_get(t_elf *elf, t_elf_section *strtab,
				       size_t index, const char **str_ptr)
{
  *str_ptr = NULL;
  if (verification(elf, strtab, index) == -1)
    return (-1);
  *str_ptr = (const char *)&strtab->content[index];
  return (0);
}
