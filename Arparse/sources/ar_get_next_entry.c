/*
** ar_get_next_entry.c for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Thu Mar  6 13:44:40 2014 Barthelemy Delemotte
** Last update Fri Mar  7 18:30:19 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		<ar.h>

#include		"arparse_int.h"

/*
** Increase the internal position index of the t_ar structure by the
** size of the current archive entry
*/
static void		ar_increase_index(t_ar *ar, t_ar_entry *entry)
{
  ar->current_idx += sizeof(struct ar_hdr) + entry->content_size;
  if (ar->current_idx % 2 != 0)
    ar->current_idx++;
}

/*
** Get the next file of the archive, filling the t_ar_entry structure.
** Return -1 if an error occured, -1 otherwise
*/
int			ar_get_next_entry(t_ar *ar, t_ar_entry *entry)
{
  struct ar_hdr		*header;

  memset(entry, 0, sizeof(t_ar_entry));
  if (ar->current_idx >= ar->size)
    return (0);
  header = (struct ar_hdr *)&ar->raw_data[ar->current_idx];
  if (ar_entry_header_parse(ar, entry, header) == -1)
    return (-1);
  ar_increase_index(ar, entry);
  return (entry->filename ? 0 : ar_get_next_entry(ar, entry));
}
