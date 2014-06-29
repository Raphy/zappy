/*
** zs_send_to_client.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 18:58:12 2014 raphael defreitas
** Last update Sun Jun 29 09:03:10 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_to_client(t_zs *this, t_zc *zc, const char *packet)
{
  if (zc->has_to_disconnect)
    return ;
  if (list_enqueue(zc->pckts_to_snd, (void *)packet) == RET_FAILURE)
    zs_handle_errno(this, "packet to send queuing failed");
}
