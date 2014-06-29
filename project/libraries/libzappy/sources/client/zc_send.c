/*
** zc_send.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:06:55 2014 raphael defreitas
** Last update Sun Jun 29 10:05:17 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zc_send(t_zc *this, const char *packet)
{
  if (this->has_to_stop)
    return ;
  if (list_enqueue(this->pckts_to_snd, (void *)packet) == RET_FAILURE)
    zc_handle_errno(this, "packet to send queuing failed");
}
