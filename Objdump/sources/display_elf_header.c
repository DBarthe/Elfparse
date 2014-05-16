/*
** display_elf_header.c for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 19:55:56 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:12:26 2014 Barthelemy Delemotte
*/

#include		<stdio.h>
#include		<string.h>

#include		"objdump.h"

const char		*get_arch_mach_name(t_elf *elf)
{
  uint16_t		machine;

  machine = elf_header_get_machine(elf);
  if (machine == EM_386)
    return ("i386");
  else if (machine == EM_X86_64)
    return ("i386:x86-64");
  return ("UNKNOWN!");
}

const char		*get_file_format_name(t_elf *elf)
{
  uint16_t		machine;

  machine = elf_header_get_machine(elf);
  if (machine == EM_386)
    return ("i386");
  else if (machine == EM_X86_64)
    return ("x86-64");
  return (elf->ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
}

void			display_elf_header(t_elf *elf)
{
  unsigned int		flags;

  flags = calc_flags(elf);
  printf("architecture: %s, flags 0x%08x:\n", get_arch_mach_name(elf), flags);
  display_flags(flags);
  printf("start address 0x%0*lx\n", elf->class == ELFCLASS32 ? 8 : 16,
	 elf_header_get_entry(elf));
}
