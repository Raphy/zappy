/*
** zt_unlinearize_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jul  2 03:48:39 2014 raphael defreitas
** Last update Wed Jul  2 03:55:29 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

static int	streamize(FILE *rstream, FILE *wstream)
{
  char		buffer[64];
  int	read_len;

  fwrite("-----BEGIN PUBLIC KEY-----\n", sizeof (char), 27, wstream);
  while ((read_len = fread(buffer, sizeof (char), 64, rstream)) > 0)
    {
      fwrite(buffer,  sizeof (char), read_len, wstream);
      fwrite("\n",  sizeof (char), 1, wstream);
    }
  fwrite("-----END PUBLIC KEY-----\n", sizeof (char), 25, wstream);
  return (RET_SUCCESS);
}

static int	fill_build(const char *pubkey, size_t pubkey_len,
			   char *build, size_t build_size)
{
  FILE		*rstream;
  FILE		*wstream;

  rstream = NULL;
  wstream = NULL;
  if ((rstream = fmemopen((char *)pubkey, pubkey_len, "r")) == NULL ||
      (wstream = fmemopen(build, build_size, "w")) == NULL ||
      streamize(rstream, wstream) == RET_FAILURE)
    {
      if (rstream)
	fclose(rstream);
      if (wstream)
	fclose(wstream);
      return (RET_FAILURE);
    }
  fclose(rstream);
  fclose(wstream);
  return (RET_SUCCESS);
}

char		*zt_unlinearize_pubkey(const char *pubkey)
{
  char		*res;
  size_t	pubkey_len;
  size_t	res_size;

  pubkey_len = strlen(pubkey);
  res_size = pubkey_len + (pubkey_len / 64) + 55;
  if ((res = calloc(res_size + 1, sizeof(char))) == NULL ||
      (fill_build(pubkey, pubkey_len, res, res_size) == RET_FAILURE))
    {
      free(res);
      return (NULL);
    }
  return (res);
}
