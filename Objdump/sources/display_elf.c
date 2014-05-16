/*
** display_elf.c for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 16:08:27 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:12:27 2014 Barthelemy Delemotte
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<stdbool.h>

#include		"objdump.h"

static bool		has_to_display_section(t_elf *elf,
					       t_elf_section *section)
{
  uint32_t		type;

  type = elf_section_get_type(elf, section);
  if (type == SHT_NULL || type == SHT_NOBITS || type == SHT_SYMTAB ||
      type == SHT_RELA)
    return (false);
  if (type == SHT_STRTAB && !(elf_section_get_flags(elf, section) & SHF_ALLOC))
    return (false);
  if (!section->content || elf_section_get_size(elf, section) == 0)
    return (false);
  return (true);
}

/*
** Dump or skip a section.
*/
static int		display_section(t_elf *elf, t_elf_section *section)
{
  const char		*name;
  int			ret;

  ret = RET_SUCCESS;
  if (has_to_display_section(elf, section))
    {
      if (elf_section_get_name(elf, section, &name) == -1)
	ret = RET_FAILURE;
      else if (name)
	{
	  printf("Contents of section %s:\n", name);
	  dump_section(elf, section);
	}
    }
  return (ret);
}

/*
** Display an elf file : dump header and sections.
*/
int			display_elf(t_elf *elf)
{
  size_t		shnum;
  size_t		idx;

  printf("\n%s:     file format elf%d-%s\n",
	 elf->filename, elf->class == ELFCLASS32 ? 32 : 64,
	 get_file_format_name(elf));
  display_elf_header(elf);
  printf("\n");
  shnum = elf_header_get_shnum(elf);
  idx = 0;
  while (idx < shnum)
    {
      if (display_section(elf, &elf->sections[idx]) == RET_FAILURE)
	return (RET_FAILURE);
      idx++;
    }
  return (RET_SUCCESS);
}
