/*
** syms.c for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed Mar 12 21:55:32 2014 Barthelemy Delemotte
** Last update Wed Mar 12 21:59:46 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<string.h>

#include		"nm.h"

void			syms_free(t_sym **syms)
{
  size_t		idx;

  idx = 0;
  while (syms[idx])
    {
      free(syms[idx]);
      idx++;
    }
  free(syms);
}

int			sym_cmp(t_sym *a, t_sym *b)
{
  if (!a->name && !b->name)
    return (0);
  else if (!a->name)
    return (1);
  else if (!b->name)
    return (-1);
  return (strcmp(a->name, b->name));
}
