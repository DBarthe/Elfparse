/*
** ar_load_file.c for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse/sources
**
** Made by Barthelemy Delemotte
** Login   <delemo_b@epitech.net>
**
** Started on Thu Mar  6 13:12:26 2014 Barthelemy Delemotte
** Last update Mon Mar 10 16:09:55 2014 Barthelemy Delemotte
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		<fcntl.h>
#include		<errno.h>
#include		<ar.h>

#include		"arparse.h"

/*
** Get the file size by using lseek. The file position
** is saved and restored if no error occured.
*/
static ssize_t		get_file_size(int fd)
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

/*
** Load the content data of the archive file.
*/
static int		ar_load_file_content(t_ar *ar, int fd)
{
  ssize_t		ssize;

  if ((ssize = get_file_size(fd)) == -1)
    return (-1);
  ar->size = (size_t)ssize;
  if ((ar->raw_data = malloc(ar->size * sizeof(char))) == NULL)
    {
      fprintf(stderr, "malloc has returned NULL\n");
      return (-1);
    }
  if (read(fd, ar->raw_data, ar->size) == -1)
    {
      perror(ar->filename);
      return (-1);
    }
  return (0);
}

/*
** Load the archive file. Fill the structure t_ar.
** Return:
**    - AR_OK on success
**    - AR_ERROR if an error occured
**    - AR_NOT if the file isn't an archive file
*/
int			ar_load_file(const char *filename, t_ar *ar)
{
  int			fd;
  int			ret;

  ret = 0;
  memset(ar, 0, sizeof(t_ar));
  if ((fd = open(filename, O_RDONLY)) == -1)
    {
      perror(filename);
      return (AR_ERROR);
    }
  if ((ar->filename = strdup(filename)) == NULL)
    fprintf(stderr, "malloc has returned NULL\n");
  else
    ret = ar_load_file_content(ar, fd);
  close(fd);
  if (!ar->filename || ret == -1)
    return (AR_ERROR);
  if (ar->size < SARMAG || strncmp(ar->raw_data, ARMAG, SARMAG) != 0)
    return (AR_NOT);
  ar->current_idx = SARMAG;
  return (AR_OK);
}
