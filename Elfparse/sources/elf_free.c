/*
** elf_free.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar  4 15:05:51 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:00:35 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>

#include		"elfparse.h"

/*
** Free allocated memory contained in the elf structure.
** Does not free the structure itself.
*/
void			elf_free(t_elf *elf)
{
  free(elf->filename);
  free(elf->raw_data);
  free(elf->sections);
}
