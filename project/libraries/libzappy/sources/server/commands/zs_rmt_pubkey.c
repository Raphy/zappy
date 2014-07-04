/*
** zs_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:53:47 2014 raphael defreitas
** Last update Thu Jul  3 22:45:02 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_rmt_pubkey(t_zs *this, t_zc *zc, const char *cmd)
{
  char		*pubkey;
  char		*build;

  if (strncmp(cmd, "RMT PUBKEY ", 11) != 0)
    return (false);
  pubkey = NULL;
  build = NULL;
  if ((pubkey = strdup((cmd + 11))) == NULL ||
      (build = zt_unlinearize_pubkey(pubkey)) == NULL ||
      (zc->key_encrypt = zt_rsa_new(build, true)) == NULL)
    {
      free(pubkey);
      free(build);
      zs_handle_errno(this, NULL);
      return (true);
    }
  zs_handle_rmt_pubkey(this, zc, build);
  free(pubkey);
  free(build);
  return (true);
}
