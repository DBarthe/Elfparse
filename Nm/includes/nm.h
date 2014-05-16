/*
** nm.h for nm in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/Nm
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Tue Mar 11 11:30:24 2014 Barthelemy Delemotte
** Last update Sun Mar 16 18:07:48 2014 Barthelemy Delemotte
*/

#ifndef			NM_H_
# define		NM_H_

# include		<sys/types.h>

# include		"elfparse.h"
# include		"arparse.h"

# define		RET_SUCCESS	0
# define		RET_FAILURE	1
# define		RET_ERROR	-1

# define		EIGHT_SPACES	"        "
# define		SIXTEEN_SPACES	EIGHT_SPACES EIGHT_SPACES

typedef	struct
{
  const char		*name;
  t_elf_sym		*sym;
}			t_sym;

int			display_elf(t_elf *elf);
int			display_archive(t_ar *ar);
int			display_file(const char *filename);
int			display_sym(t_elf *elf, t_elf_sym *sym,
				    const char *name);
void			syms_free(t_sym **syms);
int			sym_cmp(t_sym *a, t_sym *b);
char			get_sym_letter(t_elf *elf, t_elf_sym *sym);

typedef	int		(*t_cmp_funct)(const void *, const void *);

void			heapsort(void **tab, size_t size,
				 t_cmp_funct cmpFunction);

#endif			/* NM_H_ */
