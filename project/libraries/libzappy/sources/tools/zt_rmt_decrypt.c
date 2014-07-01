/*
** zt_rmt_decrypt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 16:10:46 2014 raphael defreitas
** Last update Tue Jul  1 17:48:03 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"_zappy.h"

int		zt_rmt_decrypt(RSA *rsa, const char *cmd, char **plain)
{
  char		*encrypted_len_str;
  char		*encoded;
  int		encrypted_len;
  unsigned char	*encrypted;

  *plain = NULL;
  encrypted = NULL;
  if ((encrypted_len_str = strdup(cmd + 8)) == NULL)
    return (RET_FAILURE);
  encoded = strchr(encrypted_len_str, ' ');
  *encoded = 0;
  encoded++;
  if ((encrypted_len = atoi(encrypted_len_str)) <= 0 ||
      (encrypted = zt_b64_decode(encoded)) == NULL ||
      (*plain = zt_rsa_decrypt(rsa, encrypted, encrypted_len)) == NULL)
    {
      free(encrypted_len_str);
      free(encrypted);
      return (RET_FAILURE);
    }
  free(encrypted_len_str);
  free(encrypted);
  return (RET_SUCCESS);
}
