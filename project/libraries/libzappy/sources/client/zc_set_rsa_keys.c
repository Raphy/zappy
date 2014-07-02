/*
** zc_set_rsa_keys.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 02:03:24 2014 raphael defreitas
** Last update Wed Jul  2 02:09:58 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

static char	*get_file_contents(const char *filename)
{
  FILE		*stream;
  long		fsize;
  char		*contents;

  if ((stream = fopen(filename, "r")) == NULL)
    return (NULL);
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

static int	load_public_key(t_zc *this, const char *public_key_filename)
{
  if ((this->pubkey = get_file_contents(public_key_filename)) == NULL)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

static int	load_private_key(t_zc *this, const char *private_key_filename)
{
  char		*private_key_str;

  if ((private_key_str = get_file_contents(private_key_filename)) == NULL)
    return (RET_FAILURE);
  if ((this->key_decrypt = zt_rsa_new(private_key_str, false)) == NULL)
    {
      free(private_key_str);
      return (RET_FAILURE);
    }
  free(private_key_str);
  return (RET_SUCCESS);
}

int		zc_set_rsa_keys(t_zc *this, const char *pub_key_filename,
				const char *priv_key_filename)
{
  if (this == NULL || pub_key_filename == NULL || priv_key_filename == NULL)
    return (RET_FAILURE);
  if (load_public_key(this, pub_key_filename) == RET_FAILURE ||
      load_private_key(this, priv_key_filename) == RET_FAILURE)
    return (RET_FAILURE);
  if (zt_linearize_pubkey(&this->pubkey) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
