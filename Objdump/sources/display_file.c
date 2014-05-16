/*
** display_file.c for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 15:22:57 2014 Barthelemy Delemotte
** Last update Wed Mar 12 19:39:50 2014 Barthelemy Delemotte
*/

#include		"objdump.h"

/*
** Display a file.
** - Archives are passed to display_archive().
** - Other files are loaded like elf with elf_load_file() and displayed with
**   display_elf()
** Return RET_FAILURE if an error occured, RET_SUCCESS otherwise
*/
int			display_file(const char *filename)
{
  t_ar			ar;
  t_elf			elf;
  int			ret;

  ret = ar_load_file(filename, &ar);
  if (ret == AR_ERROR)
    ret = RET_FAILURE;
  else if (ret == AR_OK)
    ret = display_archive(&ar);
  else
    {
      ret = elf_load_file(filename, &elf);
      if (ret == RET_SUCCESS)
	display_elf(&elf);
      elf_free(&elf);
    }
  ar_free(&ar);
  return (ret == RET_SUCCESS ? RET_SUCCESS : RET_FAILURE);
}
