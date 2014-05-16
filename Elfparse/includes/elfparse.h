/*
** elfparse.h for elfparse in /home/bade/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/includes
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar  3 17:38:40 2014 Barthelemy Delemotte
** Last update Sun Mar 16 17:52:17 2014 Barthelemy Delemotte
*/

#ifndef			ELFPARSE_H_
# define		ELFPARSE_H_

# include		<sys/types.h>
# include		<elf.h>

typedef	union
{
  Elf32_Ehdr		_32;
  Elf64_Ehdr		_64;
}			t_elf_header;

typedef	struct
{
  union	u_elf_sh
  {
    Elf32_Shdr		_32;
    Elf64_Shdr		_64;
  }			*header;
  unsigned char		*content;
}			t_elf_section;

typedef	union
{
  Elf32_Sym		_32;
  Elf64_Sym		_64;
}			t_elf_sym;

typedef	struct
{
  char			*filename;
  size_t		size;
  unsigned char		*raw_data;
  unsigned char		*ident;
  unsigned char		class;
  t_elf_header		*header;
  t_elf_section		*sections;
}			t_elf;

int			elf_load_file(const char *filename, t_elf *elf);
int			elf_load_buffer(const char *filename,
					const char *buffer,
					size_t buffer_size,
					t_elf *elf);
void			elf_free(t_elf *elf);

/*
** elf_header_get_*
*/
uint16_t		elf_header_get_type(t_elf *elf);
uint16_t		elf_header_get_machine(t_elf *elf);
uint32_t		elf_header_get_version(t_elf *elf);
size_t			elf_header_get_entry(t_elf *elf);
size_t			elf_header_get_phoff(t_elf *elf);
size_t			elf_header_get_phentsize(t_elf *elf);
size_t			elf_header_get_phnum(t_elf *elf);
size_t			elf_header_get_shoff(t_elf *elf);
size_t			elf_header_get_shentsize(t_elf *elf);
size_t			elf_header_get_shnum(t_elf *elf);
size_t			elf_header_get_shstrndx(t_elf *elf);

/*
** elf_section_get_*
*/
int			elf_section_get_name(t_elf *elf,
					     t_elf_section *section,
					     const char **name_ptr);
uint32_t		elf_section_get_type(t_elf *elf,
					     t_elf_section *section);
size_t			elf_section_get_offset(t_elf *elf,
					       t_elf_section *section);
size_t			elf_section_get_size(t_elf *elf,
					     t_elf_section *section);
uint64_t		elf_section_get_flags(t_elf *elf,
					      t_elf_section *section);
uint64_t		elf_section_get_addr(t_elf *elf,
					      t_elf_section *section);

/*
** elf_symtab
*/
int			elf_get_symtab(t_elf *elf, t_elf_section **section_ptr);
int			elf_symtab_get_sym(t_elf *elf, t_elf_section *symtab,
					   size_t index, t_elf_sym **sym_ptr);
ssize_t			elf_symtab_get_symnum(t_elf *elf,
					      t_elf_section *symtab);

/*
** elf_sym_get_*
*/
int			elf_sym_get_name(t_elf *elf, t_elf_sym *sym,
					 const char **name_ptr);
size_t			elf_sym_get_value(t_elf *elf, t_elf_sym *sym);
unsigned char		elf_sym_get_info(t_elf *elf, t_elf_sym *sym);
unsigned char		elf_sym_get_other(t_elf *elf, t_elf_sym *sym);
uint16_t		elf_sym_get_shndx(t_elf *elf, t_elf_sym *sym);
size_t			elf_sym_get_size(t_elf *elf, t_elf_sym *sym);

#endif			/* ELFPARSE_H_ */
