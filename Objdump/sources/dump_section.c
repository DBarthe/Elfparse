/*
** dump_section.c for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 19:37:16 2014 Barthelemy Delemotte
** Last update Mon Mar 10 19:59:20 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>

#include		"objdump.h"

static void		dump_hex(const unsigned char *buffer,
				 size_t idx, size_t size)
{
  size_t		cnt;

  cnt = 0;
  while (cnt < 16)
    {
      if (cnt > 0 && cnt % 4 == 0)
	printf(" ");
      if (cnt + idx < size)
	printf("%02x", buffer[idx + cnt]);
      else
	printf("  ");
      cnt++;
    }
}

static void		dump_ascii(const unsigned char *buffer,
				   size_t idx, size_t size)
{
  size_t		cnt;
  char			chr;

  cnt = 0;
  while (cnt < 16)
    {
      if (cnt + idx < size)
	{
	  chr = buffer[idx + cnt];
	  if (chr < ' ' || chr >= 127)
	    chr = '.';
	}
      else
	chr = ' ';
      printf("%c", chr);
      cnt++;
    }
}

static unsigned int	calc_hex_digits(size_t n)
{
  unsigned int		digits;

  digits = sizeof(n) * 2;
  while (digits > 0 && !((0xf << ((digits - 1) * 4)) & n))
    digits--;
  return (digits);
}

static void		dump_binary_buffer(size_t offset,
					   const unsigned char *buffer,
					   size_t size)
{
  size_t		limit;
  int			padding;
  size_t		idx;

  limit = (size / 16 + (size % 16 ? 1 : 0)) * 16;
  padding = calc_hex_digits(offset + limit - 1);
  if (padding < 4)
    padding = 4;
  idx = 0;
  while (idx < limit)
    {
      printf(" %0*lx ", padding, offset + idx);
      dump_hex(buffer, idx, size);
      printf("  ");
      dump_ascii(buffer, idx, size);
      printf("\n");
      idx += 16;
    }
}

void			dump_section(t_elf *elf, t_elf_section *section)
{
  size_t		size;
  size_t		offset;

  size = elf_section_get_size(elf, section);
  offset = (size_t)elf_section_get_addr(elf, section);
  dump_binary_buffer(offset, section->content, size);
}
