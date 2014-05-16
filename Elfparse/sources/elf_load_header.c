/*
** elf_load_header.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar  4 15:10:34 2014 Barthelemy Delemotte
** Last update Tue Mar  4 15:40:00 2014 Barthelemy Delemotte
*/

#include		<elf.h>
#include		<string.h>
#include		<stdio.h>

#include		"elfparse.h"

/*
** Load the identity of the file.
*/
static int		elf_load_ident(t_elf *elf)
{
  if (elf->size < EI_NIDENT || memcmp(elf->raw_data, ELFMAG, 4))
    {
      fprintf(stderr, "%s: file format not reconize\n", elf->filename);
      return (-1);
    }
  elf->ident = elf->raw_data;
  return (0);
}

/*
** Load the elf header in the elf structure.
** The identity is loaded first. Then, when the file class has been
** reconized, the entire header is loaded in the field 'elf->header'
*/
int			elf_load_header(t_elf *elf)
{
  if (elf_load_ident(elf) == -1)
    return (-1);
  if ((elf->class = elf->ident[EI_CLASS]) != ELFCLASS32
      && elf->class != ELFCLASS64)
    {
      fprintf(stderr, "%s: unknow class '%u'\n", elf->filename, elf->class);
      return (-1);
    }
  elf->header = (t_elf_header *)elf->raw_data;
  if ((elf->class == ELFCLASS32 && elf->size < sizeof(Elf32_Ehdr)) ||
      (elf->class == ELFCLASS64 && elf->size < sizeof(Elf64_Ehdr)))
    {
      fprintf(stderr, "%s: invalid header: too small\n", elf->filename);
      return (-1);
    }
  return (0);
}
