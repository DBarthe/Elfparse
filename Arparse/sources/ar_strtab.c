/*
** ar_strtab.c for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Fri Mar  7 18:17:13 2014 Barthelemy Delemotte
** Last update Fri Mar  7 18:33:33 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

#include		"arparse_int.h"

/*
** Get the name in the strtab
*/
static char		*ar_strtab_get(t_ar *ar, size_t str_idx)
{
  t_ar_entry		*strtab;
  size_t		idx;
  char			*name;

  strtab = &ar->strtab;
  name = NULL;
  idx = 0;
  while (str_idx + idx < strtab->content_size - 2
	 && strncmp(&strtab->content[str_idx + idx], "/\n", 2))
    idx++;
  if (strncmp(&strtab->content[str_idx + idx], "/\n", 2))
    fprintf(stderr, "%s: the last name in the strtab is not terminated by "
	    "a \"/\\n\"\n", ar->filename);
  else if ((name = strndup(&strtab->content[str_idx], idx)) == NULL)
    fprintf(stderr, "malloc has returned NULL\n");
  return (name);
}

/*
** Fetch the entry name from the strtab.
*/
char			*ar_strtab_fetch_name(t_ar *ar, struct ar_hdr *header)
{
  ssize_t		str_idx;

  if (ar->strtab.content == NULL)
    {
      fprintf(stderr, "%s: there is no string table to get the archive"
	      " member filename\n", ar->filename);
      return (NULL);
    }
  str_idx = ar_entry_header_get_num(header->ar_name + 1, 15);
  if (str_idx < 0 || (size_t)str_idx >= ar->strtab.content_size - 2)
    {
      fprintf(stderr, "%s: bad member file name: invalid string table"
	      " reference\n", ar->filename);
      return (NULL);
    }
  return (ar_strtab_get(ar, (size_t)str_idx));
}
