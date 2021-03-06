/*
** zt_linearize_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 03:03:20 2014 raphael defreitas
** Last update Wed Jul  2 04:00:55 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

static int	linearize(FILE *rstream, char **res, size_t len)
{
  FILE		*wstream;
  char		*line;
  size_t	line_size;
  size_t	line_len;

  wstream = NULL;
  if ((wstream = fmemopen(*res, len, "w")) == NULL)
    return (RET_FAILURE);
  line_size = 0;
  line = NULL;
  while (getline(&line, &line_size, rstream) != -1)
    {
      line_len = strlen(line);
      if (line[0] != '-')
	fwrite(line, sizeof(char), line_len - 1, wstream);
    }
  free(line);
  fclose(wstream);
  return (RET_SUCCESS);
}

char		*zt_linearize_pubkey(const char *pubkey)
{
  FILE		*rstream;
  size_t	pubkey_len;
  char		*res;

  rstream = NULL;
  pubkey_len = strlen(pubkey);
  if ((res = calloc(pubkey_len + 1, sizeof(char))) == NULL ||
      (rstream = fmemopen((char *)pubkey, pubkey_len, "r")) == NULL ||
      linearize(rstream, &res, pubkey_len) == RET_FAILURE)
    {
      if (rstream)
	fclose(rstream);
      free(res);
      return (NULL);
    }
  fclose(rstream);
  return (res);
}
