/*
** zc_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Wed Jul  2 02:07:31 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

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

static int	fill_build(char *pubkey, size_t pubkey_len,
			   char *build, size_t build_size)
{
  FILE		*rstream;
  FILE		*wstream;

  rstream = NULL;
  wstream = NULL;
  if ((rstream = fmemopen(pubkey, pubkey_len, "r")) == NULL ||
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

static char	*build_pubkey(char *pubkey)
{
  char		*build;
  size_t	pubkey_len;
  size_t	build_size;

  pubkey_len = strlen(pubkey);
  build_size = pubkey_len + (pubkey_len / 64) + 55;
  if ((build = calloc(build_size + 1, sizeof (char))) == NULL)
    return (NULL);
  if (fill_build(pubkey, pubkey_len, build, build_size) == RET_FAILURE)
    {
      free(build);
      return (NULL);
    }
  return (build);
}

bool		zc_rmt_pubkey(t_zc *this, const char *cmd)
{
  char		*pubkey;
  char		*build;

  if (strncmp(cmd, "RMT PUBKEY ", 11) != 0)
    return (false);
  pubkey = NULL;
  build = NULL;
  if ((pubkey = strdup((cmd + 11))) == NULL ||
      (build = build_pubkey(pubkey)) == NULL ||
      (this->key_encrypt = zt_rsa_new(build, true)) == NULL)
    {
      free(pubkey);
      free(build);
      zc_handle_errno(this, NULL);
      return (true);
    }
  zc_handle_rmt_pubkey(this, build);
  free(pubkey);
  free(build);
  return (true);
}
