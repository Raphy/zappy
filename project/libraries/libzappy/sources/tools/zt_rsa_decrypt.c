/*
** zt_rsa_decrypt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jun 30 22:17:21 2014 raphael defreitas
** Last update Mon Jun 30 22:29:18 2014 raphael defreitas
*/

#include	<openssl/rsa.h>
#include	<stdlib.h>

char		*zt_rsa_decrypt(RSA *rsa, const unsigned char *data, int len)
{
  char		*decrypted;

  if (rsa == NULL || data == NULL)
    return (NULL);
  if ((decrypted = calloc(RSA_size(rsa) + 1, sizeof (char))) == NULL)
    return (NULL);
  if (RSA_private_decrypt(len, data, (unsigned char *)decrypted, rsa,
			  RSA_PKCS1_PADDING) == -1)
    {
      free(decrypted);
      return (NULL);
    }
  return (decrypted);
}
