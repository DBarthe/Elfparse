/*
** display_file.c<2> for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed Mar 12 19:21:07 2014 Barthelemy Delemotte
** Last update Wed Mar 12 19:40:11 2014 Barthelemy Delemotte
*/

#include		"nm.h"

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
