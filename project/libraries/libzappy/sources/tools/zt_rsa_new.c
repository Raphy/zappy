/*
** zt_rsa_new.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:32:52 2014 raphael defreitas
** Last update Tue Jul  1 02:50:41 2014 raphael defreitas
*/

#include	<openssl/bio.h>
#include	<openssl/pem.h>
#include	<openssl/rsa.h>
#include	<stdbool.h>
#include	<stdlib.h>

RSA		*zt_rsa_new(const char *key, bool is_public)
{
  RSA		*rsa;
  BIO		*bio;

  if (key == NULL)
    return (NULL);
  rsa = NULL;
  bio = NULL;
  if ((bio = BIO_new_mem_buf((void *)key, -1)) == NULL)
    return (NULL);
  if (is_public)
    rsa = PEM_read_bio_RSA_PUBKEY(bio, &rsa, NULL, NULL);
  else
    rsa = PEM_read_bio_RSAPrivateKey(bio, &rsa, NULL, NULL);
  if (rsa == NULL)
    BIO_free_all(bio);
  return (rsa);
}
