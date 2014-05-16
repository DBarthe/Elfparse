/*
** ar_entry.c for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Fri Mar  7 18:29:08 2014 Barthelemy Delemotte
** Last update Fri Mar  7 18:32:47 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

#include		"arparse_int.h"

/*
** Get a number from an entry header field. n must be the size of
** the field.
*/
ssize_t			ar_entry_header_get_num(char *s, size_t n)
{
  size_t		idx;
  ssize_t		num;

  idx = 0;
  num = 0;
  while (idx < n && s[idx] >= '0' && s[idx] <= '9')
    {
      num = num * 10 + (ssize_t)(s[idx] - '0');
      idx++;
    }
  return (num);
}

/*
** Fetch the name in the header entry filling the t_ar_entry structure
** If the string is in the strtable, the appropriated function is called.
** Set entry filename to NULL if the entry is the symbols or strings table.
** If entry is the string table, copy the t_ar_entry structure in the t_ar
** field 'strtab'
** Return 0 on success, -1 on error
*/
static int		ar_entry_fetch_name(t_ar *ar, t_ar_entry *entry,
					    struct ar_hdr *header)
{
  ssize_t		i;

  entry->filename = NULL;
  i = 16;
  while (--i >= 0 && header->ar_name[i] == ' ');
  if (i == 1 && header->ar_name[0] == '/' && header->ar_name[1] == '/')
    ar->strtab = *entry;
  else if (i > 0 && header->ar_name[0] == '/')
    return ((entry->filename = ar_strtab_fetch_name(ar, header)) ? 0 : -1);
  else if (i != 0 || header->ar_name[0] != '/')
    {
      if (header->ar_name[i] == '/')
	i--;
      if ((entry->filename = strndup(header->ar_name, i + 1)) == NULL)
	{
	  fprintf(stderr, "malloc has returned NULL\n");
	  return (-1);
	}
    }
  return (0);
}

/*
** Fetch the size of then entry content in the entry header.
** Return -1 if the size is negative, 0 otherwise.
*/
static int		ar_entry_fetch_size(t_ar_entry *entry,
					    struct ar_hdr *header)
{
  ssize_t		num;

  num = ar_entry_header_get_num(header->ar_size, 10);
  if (num < 0)
    return (-1);
  entry->content_size = (size_t)num;
  return (0);
}

/*
** Parse an entry header :
**   - check the entry validity (returns -1 or 0)
**   - fetch filename and size
**   - fill the t_ar_entry fields (name, content, size)
*/
int			ar_entry_header_parse(t_ar *ar, t_ar_entry *entry,
					      struct ar_hdr *header)
{
  size_t		content_off;
  int			error;

  content_off = ar->current_idx + sizeof(struct ar_hdr);
  error = 0;
  if (content_off >= ar->size)
    error = 1;
  if (!error && ar_entry_fetch_size(entry, header) == -1)
    return (-1);
  if (!error && content_off + entry->content_size > ar->size)
    error = 1;
  if (error)
    {
      fprintf(stderr, "%s: error: the archive is truncated\n", ar->filename);
      return (-1);
    }
  entry->content = &ar->raw_data[content_off];
  return (ar_entry_fetch_name(ar, entry, header));
}
