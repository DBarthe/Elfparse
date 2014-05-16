/*
** elfparse_int.h for elfparse in /home/bade/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/includes
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar  3 18:49:40 2014 Barthelemy Delemotte
** Last update Sun Mar 16 17:52:33 2014 Barthelemy Delemotte
*/

#ifndef			ELFPARSE_INT_H_
# define		ELFPARSE_INT_H_

# include		"elfparse.h"

# define		ELF_IS_32(e) ((e)->class == ELFCLASS32)
# define		ELF_IS_64(e) ((e)->class == ELFCLASS64)

ssize_t			elf_get_file_size(int fd);
int			elf_load_header(t_elf *elf);
int			elf_load_sections(t_elf *elf);
int			elf_get_shstrtab(t_elf *elf,
					 t_elf_section **section_ptr);
int			elf_get_symstrtab(t_elf *elf,
					  t_elf_section **section_ptr);
int			elf_strtab_get(t_elf *elf, t_elf_section *strtab,
				       size_t index, const char **str_ptr);

#endif			/* ELFPARSE_INT_H_ */
