/*
** zt_rsa_encrypt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jun 30 21:43:59 2014 raphael defreitas
** Last update Mon Jun 30 22:28:46 2014 raphael defreitas
*/

#include	<openssl/rsa.h>
#include	<stdlib.h>
#include	<string.h>

unsigned char	*zt_rsa_encrypt(RSA *rsa, const char *data, int *len)
{
  unsigned char	*encrypted;

  if ((encrypted = calloc(RSA_size(rsa) + 1, sizeof(unsigned char))) == NULL)
    return (NULL);
  *len = RSA_public_encrypt(strlen(data), (unsigned char *)data, encrypted, rsa,
			    RSA_PKCS1_PADDING);
  if (*len == -1)
    {
      free(encrypted);
      return (NULL);
    }
  return (encrypted);
}
