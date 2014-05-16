/*
** display_elf.c for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Wed Mar 12 19:24:24 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:03:10 2014 Barthelemy Delemotte
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>

#include		"nm.h"

static void		*xmalloc(size_t size)
{
  void			*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      fprintf(stderr, "fatal error: malloc has returned null\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

static int		display_symtab(t_elf *elf, t_sym **syms)
{
  size_t		idx;

  idx = 0;
  while (syms[idx])
    idx++;
  heapsort((void **)syms, idx, (t_cmp_funct)&sym_cmp);
  idx = 0;
  while (syms[idx])
    {
      display_sym(elf, syms[idx]->sym, syms[idx]->name);
      idx++;
    }
  return (RET_SUCCESS);
}

static t_sym		**parse_symtab(t_elf *elf, t_elf_section *symtab)
{
  ssize_t		syms_number;
  ssize_t		idx;
  t_sym			**syms;

  if ((syms_number = elf_symtab_get_symnum(elf, symtab)) == -1)
    return (NULL);
  syms = xmalloc((syms_number + 1) * sizeof(t_sym *));
  memset(syms, 0, (syms_number + 1) * sizeof(t_sym *));
  idx = -1;
  while (++idx < syms_number)
    {
      syms[idx] = xmalloc(sizeof(t_sym));
      if (elf_symtab_get_sym(elf, symtab, idx, &syms[idx]->sym) == -1 ||
	  elf_sym_get_name(elf, syms[idx]->sym, &syms[idx]->name) == -1)
	{
	  syms_free(syms);
	  return (NULL);
	}
    }
  return (syms);
}

int			display_elf(t_elf *elf)
{
  t_elf_section		*symtab;
  t_sym			**syms;
  int			ret;

  printf("\n%s:\n", elf->filename);
  if (elf_get_symtab(elf, &symtab) == -1)
    return (RET_FAILURE);
  if (symtab == NULL)
    {
      fprintf(stderr, "nm: %s: no symbols\n", elf->filename);
      return (RET_SUCCESS);
    }
  if ((syms = parse_symtab(elf, symtab)) == NULL)
    return (RET_FAILURE);
  ret = display_symtab(elf, syms);
  syms_free(syms);
  return (ret);
}
