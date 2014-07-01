/*
** zc_send_rmt_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/client/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 16:32:11 2014 raphael defreitas
** Last update Tue Jul  1 17:27:08 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_rmt_stop(t_zc *this)
{
  char		*tmp;

  if (this == NULL)
    return ;
  if (zt_rmt_encrypt(this->pubkey, "stop", &tmp) == RET_FAILURE ||
      tmp == NULL)
    {
      zc_handle_errno(this, "encryption failed");
      return ;
    }
  zc_send(this, "RMT CMD ");
  zc_send(this, tmp);
  zc_send(this, "\n");
  free(tmp);
}
