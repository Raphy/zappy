/*
** zs_rmt_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:53:47 2014 raphael defreitas
** Last update Wed Jul  2 11:31:03 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_rmt_stop(t_zs *this, t_zc *zc, const char *cmd)
{
  char		*cmdd;
  int		ret;

  if (!zt_get_rmt_cmd(this->key_decrypt, cmd, &cmdd, &ret))
    return (false);
  if (ret == RET_FAILURE)
    {
      zs_handle_errno(this, "decryption failed");
      return (true);
    }
  if (strcmp(cmdd, "stop") != 0)
    return (false);
  zs_handle_rmt_stop(this, zc);
  free(cmdd);
  return (true);
}
