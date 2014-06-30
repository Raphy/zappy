/*
** zt_b64_encode.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jun 30 22:29:52 2014 raphael defreitas
** Last update Mon Jun 30 22:49:33 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<math.h>
#include	<openssl/bio.h>
#include	<openssl/evp.h> 
#include	<stdio.h>
#include	<stdlib.h>

#include	"my.h"

static int	encode(const unsigned char *data, int len, FILE *stream)
{
  BIO		*b64;
  BIO		*bio;

  bio = NULL;
  b64 = NULL;
  if ((b64 = BIO_new(BIO_f_base64())) == NULL ||
      (bio = BIO_new_fp(stream, BIO_NOCLOSE)) == NULL)
    {
      BIO_free_all(bio);
      return (RET_FAILURE);
    }
  bio = BIO_push(b64, bio);
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
  BIO_write(bio, data, len);
  BIO_flush(bio);
  BIO_free_all(bio);
  return (RET_SUCCESS);
}

char		*zt_b64_encode(const unsigned char *data, int len)
{
  char		*encoded;
  int		encoded_size;
  FILE		*stream;

  encoded = NULL;
  stream = NULL;
  encoded_size = 4 * ceil((double)len / 3);
  if ((encoded = calloc(encoded_size + 1, sizeof(char))) == NULL ||
      (stream = fmemopen(encoded, encoded_size + 1, "w")) == NULL ||
      encode(data, len, stream) == RET_FAILURE)
    {
      free(encoded);
      if (stream)
	fclose(stream);
      return (NULL);
    }
  fclose(stream);
  return (encoded);
}
