/*
** ar_free.c for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Thu Mar  6 13:41:46 2014 Barthelemy Delemotte
** Last update Fri Mar  7 15:06:30 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<string.h>

#include		"arparse.h"

/*
** Free allocated datas in 'ar', if they have already been allocated.
** Do not free the structure it self. Reset all structure fields to zero.
*/
void			ar_free(t_ar *ar)
{
  free(ar->filename);
  free(ar->raw_data);
  memset(ar, 0, sizeof(t_ar));
}

/*
** Free allocated datas in a t_ar_entry structure and reset all fields to zero
*/
void			ar_entry_free(t_ar_entry *entry)
{
  free(entry->filename);
  memset(entry, 0, sizeof(t_ar_entry));
}
