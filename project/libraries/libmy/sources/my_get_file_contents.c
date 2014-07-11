/*
** my_get_file_contents.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libmy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jul  3 23:32:24 2014 raphael defreitas
** Last update Fri Jul 11 17:03:47 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

static char	*get_full_name(const char *d, const char *f)
{
  char		*fullname;

  if (d == NULL)
    fullname = strdup(f);
  else
    {
      if ((fullname = calloc(strlen(d)
			     + strlen(f) + 2, sizeof(char))) == NULL)
	return (NULL);
      strcat(fullname, d);
      strcat(fullname, "/");
      strcat(fullname, f);
    }
  return (fullname);
}

char		*my_get_file_contents(const char *filename, const char *dir)
{
  FILE		*stream;
  long		fsize;
  char		*contents;
  char		*fullname;

  if ((fullname = get_full_name(dir, filename)) == NULL ||
      (stream = fopen(fullname, "r")) == NULL)
    {
      free(fullname);
      return (NULL);
    }
  free(fullname);
  fseek(stream, 0, SEEK_END);
  fsize = ftell(stream);
  fseek(stream, 0, SEEK_SET);
  if ((contents = calloc(fsize + 1, sizeof (char))) == NULL)
    {
      fclose(stream);
      return (NULL);
    }
  fread(contents, fsize, 1, stream);
  fclose(stream);
  return (contents);
}
