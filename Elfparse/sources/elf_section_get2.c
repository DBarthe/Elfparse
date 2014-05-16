/*
** elf_section_get2.c for elparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 18:54:44 2014 Barthelemy Delemotte
** Last update Mon Mar 10 18:56:40 2014 Barthelemy Delemotte
*/

#include		"elfparse_int.h"

/*
** Get the flags of the section
*/
uint64_t		elf_section_get_addr(t_elf *elf,
					     t_elf_section *section)
{
  uint64_t		addr;

  if (ELF_IS_32(elf))
    addr = (uint64_t)section->header->_32.sh_addr;
  else
    addr = (uint64_t)section->header->_64.sh_addr;
  return (addr);
}
