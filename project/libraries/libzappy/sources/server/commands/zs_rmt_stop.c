/*
** zs_rmt_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:53:47 2014 raphael defreitas
** Last update Tue Jul  1 17:42:27 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_rmt_stop(t_zs *this, t_zc *zc, const char *cmd)
{
  char		*cmdd;

  cmdd = NULL;
  if (!my_match(cmd, "RMT CMD * *") ||
      (zt_rmt_decrypt(this->private_key, cmd, &cmdd) == RET_SUCCESS &&
       cmdd == NULL) || strcmp(cmdd, "stop") != 0)
    return (false);
  zs_handle_rmt_stop(this, zc);
  free(cmdd);
  return (true);
}
