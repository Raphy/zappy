/*
** zc_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Wed Jul  2 03:56:12 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zc_rmt_pubkey(t_zc *this, const char *cmd)
{
  char		*pubkey;
  char		*build;

  if (strncmp(cmd, "RMT PUBKEY ", 11) != 0)
    return (false);
  pubkey = NULL;
  build = NULL;
  if ((pubkey = strdup((cmd + 11))) == NULL ||
      (build = zt_unlinearize_pubkey(pubkey)) == NULL ||
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
