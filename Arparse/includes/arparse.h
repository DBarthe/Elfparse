/*
** arparse.h for arparse in /home/bade/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/includes
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Thu Mar  6 12:56:47 2014 Barthelemy Delemotte
** Last update Sun Mar 16 17:10:20 2014 Barthelemy Delemotte
*/

#ifndef			ARPARSE_H_
# define		ARPARSE_H_

# include		<sys/types.h>
# include		<ar.h>

typedef	struct
{
  char			*filename;
  size_t		content_size;
  const char		*content;
}			t_ar_entry;

typedef	struct
{
  char			*filename;
  size_t		size;
  char			*raw_data;
  size_t		current_idx;
  t_ar_entry		strtab;
}			t_ar;

# define		AR_OK		0
# define		AR_ERROR	-1
# define		AR_NOT		1

int			ar_load_file(const char *filename, t_ar *ar);
int			ar_get_next_entry(t_ar *ar, t_ar_entry *entry);
void			ar_free(t_ar *ar);
void			ar_entry_free(t_ar_entry *entry);

#endif			/* ARPARSE_H_ */
