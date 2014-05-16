/*
** display_archive.c for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 15:38:35 2014 Barthelemy Delemotte
** Last update Wed Mar 12 19:39:53 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdbool.h>
#include		<stdio.h>

#include		"objdump.h"

/*
** Display all file contained in the archive.
*/
int			display_archive(t_ar *ar)
{
  t_ar_entry		entry;
  t_elf			elf;
  int			ret;
  bool			error;

  printf("In archive %s:\n", ar->filename);
  error = false;
  while ((ret = ar_get_next_entry(ar, &entry)) != -1 && entry.filename)
    {
      ret = elf_load_buffer(entry.filename, entry.content,
			    entry.content_size, &elf);
      if (ret == -1)
	error = true;
      else
	display_elf(&elf);
      elf_free(&elf);
      ar_entry_free(&entry);
    }
  if (ret == -1)
    error = true;
  ar_entry_free(&entry);
  ar_free(ar);
  return (error ? RET_FAILURE : RET_SUCCESS);
}
