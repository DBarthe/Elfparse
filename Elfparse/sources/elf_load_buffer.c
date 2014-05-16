/*
** elf_load_buffer.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Fri Mar  7 18:46:14 2014 Barthelemy Delemotte
** Last update Sun Mar 16 17:55:58 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

#include		"elfparse_int.h"

/*
** Load the buffer content in t_elf member 'raw_data'
*/
static int		elf_load_buffer_content(t_elf *elf,
						const char *buffer,
						size_t buffer_size)
{
  elf->size = buffer_size;
  if ((elf->raw_data = malloc(buffer_size)) == NULL)
    {
      fprintf(stderr, "malloc has returned null\n");
      return (-1);
    }
  memcpy(elf->raw_data, buffer, buffer_size);
  return (0);
}

/*
** Load the elf file present in the buffer.
** This function is used to parse elf file contained in a static library
** archive.
*/
int			elf_load_buffer(const char *filename,
					const char *buffer,
					size_t buffer_size,
					t_elf *elf)
{
  int			ret;

  ret = 0;
  memset(elf, 0, sizeof(t_elf));
  if ((elf->filename = strdup(filename)) == NULL)
    fprintf(stderr, "malloc has returned null\n");
  else
    ret = elf_load_buffer_content(elf, buffer, buffer_size);
  if (!elf->filename || ret || elf_load_header(elf) || elf_load_sections(elf))
    return (-1);
  return (0);
}
