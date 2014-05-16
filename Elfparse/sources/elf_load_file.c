/*
** elf_load_file.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar  3 18:38:05 2014 Barthelemy Delemotte
** Last update Fri Mar  7 18:55:37 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		<errno.h>
#include		<fcntl.h>
#include		<sys/types.h>

#include		"elfparse.h"
#include		"elfparse_int.h"

/*
** Load the file content in the t_elf member 'raw_data'.
*/
static int		elf_load_file_content(t_elf *elf, int fd)
{
  int			ret;
  ssize_t		size;

  if ((size = elf_get_file_size(fd)) == -1)
    return (-1);
  else if (size < 1)
    {
      fprintf(stderr, "file '%s' is empty\n", elf->filename);
      return (-1);
    }
  elf->size = (size_t)size;
  ret = -1;
  if (!(elf->raw_data = malloc(elf->size)))
    fprintf(stderr, "malloc has returned null\n");
  else if (read(fd, elf->raw_data, elf->size) == -1)
    fprintf(stderr, "read: %s: %s\n", elf->filename, strerror(errno));
  else
    ret = 0;
  return (ret);
}

/*
** Load the elf file. Fill the elf structure.
** Return -1 if an error occurs, 0 otherwise.
*/
int			elf_load_file(const char *filename, t_elf *elf)
{
  int			fd;
  int			ret;

  ret = 0;
  memset(elf, 0, sizeof(t_elf));
  if ((fd = open(filename, O_RDONLY)) == -1)
    {
      fprintf(stderr, "open: %s: %s\n", filename, strerror(errno));
      return (-1);
    }
  if ((elf->filename = strdup(filename)) == NULL)
    fprintf(stderr, "malloc has returned null\n");
  else
    ret = elf_load_file_content(elf, fd);
  close(fd);
  if (!elf->filename || ret || elf_load_header(elf) || elf_load_sections(elf))
    return (-1);
  return (0);
}
