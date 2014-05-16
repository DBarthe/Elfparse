/*
** main.c for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar 11 11:30:20 2014 Barthelemy Delemotte
** Last update Wed Mar 12 20:21:40 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>

#include		"nm.h"

int			main(int ac, char **av)
{
  int			idx;
  int			ret;

  ret = 0;
  idx = 1;
  if (ac == 1)
    ret = display_file("a.out");
  else
    while (idx < ac)
      {
	ret |= display_file(av[idx]);
	idx++;
      }
  return (ret);
}
