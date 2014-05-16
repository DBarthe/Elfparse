/*
** arparse_int.h for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Fri Mar  7 18:24:39 2014 Barthelemy Delemotte
** Last update Fri Mar  7 18:33:42 2014 Barthelemy Delemotte
*/

#ifndef			ARPARSE_INT_H_
# define		ARPARSE_INT_H_

# include		"arparse.h"

char			*ar_strtab_fetch_name(t_ar *ar, struct ar_hdr *header);
ssize_t			ar_entry_header_get_num(char *s, size_t n);
int			ar_entry_header_parse(t_ar *ar, t_ar_entry *entry,
					      struct ar_hdr *header);

#endif			/* ARPARSE_INT_H_ */
