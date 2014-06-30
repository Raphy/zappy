/*
** zt_b64_decode.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jun 30 22:52:35 2014 raphael defreitas
** Last update Mon Jun 30 23:44:50 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<openssl/bio.h>
#include	<openssl/evp.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

static int	get_decoded_size(const char *b64_input, int len)
{
  int padding;

  padding = 0;
  if (b64_input[len-1] == '=' && b64_input[len-2] == '=')
    padding = 2;
  else if (b64_input[len-1] == '=')
    padding = 1;
  return ((int)len * 0.75 - padding);
}

static int	decode(unsigned char *decoded, int len, FILE *stream)
{
  BIO		*bio;
  BIO		*b64;
  int		bio_len;

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
  if ((bio_len = BIO_read(bio, decoded, len)) == -1)
    {
      BIO_free_all(bio);
      return (RET_FAILURE);
    }
  decoded[bio_len] = 0;
  BIO_free_all(bio);
  return (RET_SUCCESS);
}

unsigned char	*zt_b64_decode(const char *data)
{

  unsigned char	*decoded;
  int		len;
  int		decoded_size;
  FILE		*stream;

  if (data == NULL)
    return (NULL);
  len = strlen(data);
  decoded_size = get_decoded_size(data, len);
  decoded = NULL;
  stream = NULL;
  if ((decoded = calloc(decoded_size + 1, sizeof(unsigned char))) == NULL ||
      (stream = fmemopen((char *)data, len, "r")) == NULL ||
      decode(decoded, len, stream) == RET_FAILURE)
    {
      free(decoded);
      if (stream)
	fclose(stream);
    }
  fclose(stream);
  return (decoded);
}
