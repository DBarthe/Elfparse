/*
** display_sym.c for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed Mar 12 20:41:34 2014 Barthelemy Delemotte
** Last update Sun Mar 16 17:41:51 2014 Barthelemy Delemotte
*/

#include		<stdbool.h>
#include		<stdio.h>
#include		<string.h>

#include		"nm.h"

static bool		has_to_display_sym(t_elf *elf, t_elf_sym *sym)
{
  unsigned char		info;
  unsigned char		type;

  info = elf_sym_get_info(elf, sym);
  if (elf->class == ELFCLASS32)
    type = ELF32_ST_TYPE(info);
  else
    type = ELF64_ST_TYPE(info);
  if (type == STT_FILE)
    return (false);
  return (true);
}

static void		display_sym_value(t_elf *elf, t_elf_sym *sym,
					  char letter)
{
  size_t		value;

  value = elf_sym_get_value(elf, sym);
  if (letter == 'C')
    value = elf_sym_get_size(elf, sym);
  if (value || elf_sym_get_size(elf, sym) || strchr("r", letter))
    printf("%0*lx", elf->class == ELFCLASS32 ? 8 : 16, value);
  else
    printf("%s", elf->class == ELFCLASS32 ? EIGHT_SPACES : SIXTEEN_SPACES);
}

int			display_sym(t_elf *elf, t_elf_sym *sym,
				    const char *name)
{
  char			letter;

  if (name && *name && has_to_display_sym(elf, sym))
    {
      letter = get_sym_letter(elf, sym);
      display_sym_value(elf, sym, letter);
      printf(" %c %s\n", letter, name);
    }
  return (RET_SUCCESS);
}
