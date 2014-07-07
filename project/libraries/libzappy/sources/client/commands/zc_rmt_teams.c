/*
** zc_rmt_teams.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/client/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jul  7 10:29:39 2014 raphael defreitas
** Last update Mon Jul  7 10:57:22 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zc_rmt_teams(t_zc *this, const char *cmd)
{
  char		*cmdd;
  int		ret;

  if (!zt_get_rmt_cmd(this->key_decrypt, cmd, &cmdd, &ret))
    return (false);
  if (ret == RET_FAILURE)
    {
      zc_handle_errno(this, "decryption failed");
      return (true);
    }
  if (strncmp("teams ", cmdd, 6) != 0)
    return (false);
  zc_handle_rmt_teams(this, cmdd + 6);
  free(cmdd);
  return (true);
}
