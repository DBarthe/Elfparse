/*
** main.c for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Fri Mar  7 23:31:18 2014 Barthelemy Delemotte
** Last update Wed Mar 12 19:39:52 2014 Barthelemy Delemotte
*/

#include		"objdump.h"

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
