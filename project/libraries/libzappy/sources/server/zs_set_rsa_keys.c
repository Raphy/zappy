/*
** zs_set_rsa_keys.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 02:03:24 2014 raphael defreitas
** Last update Thu Jul  3 23:41:31 2014 raphael defreitas
*/

#include	<openssl/err.h>
#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static int	load_public_key(t_zs *this, const char *public_key_filename)
{
  if ((this->pubkey = my_get_file_contents(public_key_filename, NULL)) == NULL)
    return (RET_FAILURE);
  if ((this->key_encrypt = zt_rsa_new(this->pubkey, true)) == NULL)
    {
      free(this->pubkey);
      this->pubkey = NULL;
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

static int	load_private_key(t_zs *this, const char *private_key_filename)
{
  char		*privkey;

  if ((privkey = my_get_file_contents(private_key_filename, NULL)) == NULL)
    return (RET_FAILURE);
  if ((this->key_decrypt = zt_rsa_new(privkey, false)) == NULL)
    {
      free(privkey);
      return (RET_FAILURE);
    }
  free(privkey);
  return (RET_SUCCESS);
}

int		zs_set_rsa_keys(t_zs *this, const char *pub_key_filename,
				const char *priv_key_filename)
{
  if (this == NULL || pub_key_filename == NULL || priv_key_filename == NULL)
    return (RET_FAILURE);
  if (load_public_key(this, pub_key_filename) == RET_FAILURE)
    return (RET_FAILURE);
  if (load_private_key(this, priv_key_filename) == RET_FAILURE)
    return (RET_FAILURE);
  if ((this->pubkey = zt_linearize_pubkey(this->pubkey)) == NULL)
    {
      printf("Public key linearization failed\n");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}
