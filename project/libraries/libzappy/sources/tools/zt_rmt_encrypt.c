/*
** zt_rmt_encrypt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 16:56:57 2014 raphael defreitas
** Last update Tue Jul  1 17:24:42 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"_zappy.h"

int		zt_rmt_encrypt(RSA *rsa, const char *cmd, char **res)
{
  int		encrypted_len;
  unsigned char	*encrypted;
  char		*encoded;

  *res = NULL;
  if ((encrypted = zt_rsa_encrypt(rsa, cmd, &encrypted_len)) == NULL)
    return (RET_FAILURE);
  if ((encoded = zt_b64_encode(encrypted, encrypted_len)) == NULL)
    {
      free(encrypted);
      return (RET_FAILURE);
    }
  if ((*res = calloc(encrypted_len + strlen(encoded), sizeof (char))) == NULL)
    {
      free(encrypted);
      free(encoded);
      return (RET_FAILURE);
    }
  sprintf(*res, "%d %s", encrypted_len, encoded);
  return (RET_SUCCESS);
}
