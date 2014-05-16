/*
** elf_header_get.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 20:36:56 2014 Barthelemy Delemotte
** Last update Mon Mar 10 20:51:03 2014 Barthelemy Delemotte
*/

#include		"elfparse_int.h"

size_t			elf_header_get_entry(t_elf *elf)
{
  size_t		entry;

  if (ELF_IS_32(elf))
    entry = (size_t)elf->header->_32.e_entry;
  else
    entry = (size_t)elf->header->_64.e_entry;
  return (entry);
}

uint16_t		elf_header_get_type(t_elf *elf)
{
  uint16_t		type;

  if (ELF_IS_32(elf))
    type = (uint16_t)elf->header->_32.e_type;
  else
    type = (uint16_t)elf->header->_64.e_type;
  return (type);
}

uint16_t		elf_header_get_machine(t_elf *elf)
{
  uint16_t		machine;

  if (ELF_IS_32(elf))
    machine = (uint16_t)elf->header->_32.e_machine;
  else
    machine = (uint16_t)elf->header->_64.e_machine;
  return (machine);
}

uint32_t		elf_header_get_version(t_elf *elf)
{
  uint32_t		version;

  if (ELF_IS_32(elf))
    version = (uint32_t)elf->header->_32.e_version;
  else
    version = (uint32_t)elf->header->_64.e_version;
  return (version);
}
