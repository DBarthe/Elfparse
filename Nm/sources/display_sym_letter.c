/*
** display_sym_letter.c for nm in /home/bade/Dev/tek2/Unix/PSU_2013_nmobjdump/PSU_2013_nmobjdump
**
** Made by Barthelemy Delemotte
** Login   <bade@epitech.net>
**
** Started on Sun Mar 16 17:40:22 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:05:13 2014 Barthelemy Delemotte
*/

#include		<stdbool.h>
#include		<string.h>

#include		"nm.h"

static int		cmp(const char *current, const char *model)
{
  return (strncmp(current, model, strlen(model)));
}

static bool		location_based_letter(t_elf *elf, uint16_t shndx,
					      unsigned char bind, char *letter)
{
  t_elf_section		*section;
  const char		*name;

  if (shndx >= elf_header_get_shnum(elf))
    return (false);
  section = &elf->sections[shndx];
  if (elf_section_get_name(elf, section, &name) == -1 || !name || !*name)
    return (false);
  if (!cmp(name, ".text") || !cmp(name, ".init") || !cmp(name, ".plt") ||
      !cmp(name, ".fini") || !cmp(name, ".text") || !cmp(name, ".init_array")
      || !cmp(name, ".fini_array"))
    *letter = (bind == STB_LOCAL ? 't' : 'T');
  else if (!cmp(name, ".rodata") || !cmp(name, ".eh_frame"))
    *letter = (bind == STB_LOCAL ? 'r' : 'R');
  else if (!cmp(name, ".jcr") || !cmp(name, ".dynamic") ||
	   !cmp(name, ".got.plt") || !cmp(name, ".data"))
    *letter = (bind == STB_LOCAL ? 'd' : 'D');
  else if (!cmp(name, ".bss"))
    *letter = (bind == STB_LOCAL ? 'b' : 'B');
  else if (!cmp(name, ".debug"))
    *letter = 'N';
  return (true);
}

static char		_get_sym_letter(t_elf *elf, size_t value,
					unsigned short info, uint16_t shndx)
{
  char			letter;
  unsigned char		bind;
  unsigned char		type;

  type = (unsigned char)(info & 0xFF);
  bind = (unsigned char)(info >> 8);
  letter = '?';
  if (shndx == SHN_ABS)
    letter = 'A';
  else if (bind == STB_WEAK && type == STT_OBJECT && !value)
    letter = 'v';
  else if (bind == STB_WEAK && type == STT_OBJECT && value)
    letter = 'V';
  else if (bind == STB_WEAK && !value)
    letter = 'w';
  else if (bind == STB_WEAK && value)
    letter = 'W';
  else if (shndx == SHN_UNDEF)
    letter = 'U';
  else if (shndx == SHN_COMMON)
    letter = 'C';
  else
    location_based_letter(elf, shndx, bind, &letter);
  return (letter);
}

char			get_sym_letter(t_elf *elf, t_elf_sym *sym)
{
  char			letter;
  unsigned char		bind;
  unsigned char		type;
  uint16_t		shndx;
  size_t		value;

  shndx = elf_sym_get_shndx(elf, sym);
  value = elf_sym_get_value(elf, sym);
  if (elf->class == ELFCLASS32)
    {
      type = ELF32_ST_TYPE(elf_sym_get_info(elf, sym));
      bind = ELF32_ST_BIND(elf_sym_get_info(elf, sym));
    }
  else
    {
      type = ELF64_ST_TYPE(elf_sym_get_info(elf, sym));
      bind = ELF32_ST_BIND(elf_sym_get_info(elf, sym));
    }
  if (!value)
    value = elf_sym_get_size(elf, sym);
  letter = _get_sym_letter(elf, value, (short)type | ((short)bind << 8), shndx);
  return (letter);
}
