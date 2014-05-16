/*
** utils.c for elfparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Mon Mar  3 18:39:14 2014 Barthelemy Delemotte
** Last update Tue Mar  4 15:35:54 2014 Barthelemy Delemotte
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<sys/types.h>

/*
** Get the file size by using lseek. The file position
** is saved and restored if no error occured.
*/
ssize_t			elf_get_file_size(int fd)
{
  off_t			save_pos;
  off_t			size;

  if ((save_pos = lseek(fd, 0, SEEK_CUR)) == (off_t)-1
      || ((size = lseek(fd, 0, SEEK_END)) == (off_t)-1)
      || lseek(fd, save_pos, SEEK_SET) == (off_t)-1)
    {
      perror("lseek");
      return ((ssize_t)-1);
    }
  return ((ssize_t)size);
}
