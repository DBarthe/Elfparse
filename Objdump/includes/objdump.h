/*
** objdump.h for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar 10 15:31:07 2014 Barthelemy Delemotte
** Last update Fri Mar 14 13:14:51 2014 Barthelemy Delemotte
*/

#ifndef			OBJDUMP_H_
# define		OBJDUMP_H_

# include		"arparse.h"
# include		"elfparse.h"

# define		RET_SUCCESS	0
# define		RET_FAILURE	1

int			display_file(const char *filename);
int			display_archive(t_ar *ar);
int			display_elf(t_elf *elf);
void			display_elf_header(t_elf *elf);
void			dump_section(t_elf *elf, t_elf_section *section);
const char		*get_arch_mach_name(t_elf *elf);
const char		*get_file_format_name(t_elf *elf);
void			display_flags(unsigned int flags);
unsigned int		calc_flags(t_elf *elf);

enum
  {
    BFD_NO_FLAGS	= 0,
    HAS_RELOC		= 1,
    EXEC_P		= 2,
    HAS_LINENO		= 4,
    HAS_DEBUG		= 8,
    HAS_SYMS		= 16,
    HAS_LOCAL		= 32,
    DYNAMIC		= 64,
    WP_TEXT		= 128,
    D_PAGED		= 256
  };

# define _S		", "
# define _F(f, t, r)	printf("%s%s", r && (f & t) ? _S : "", f & t ? #t : "")

#endif			/* OBJDUMP_H_ */
