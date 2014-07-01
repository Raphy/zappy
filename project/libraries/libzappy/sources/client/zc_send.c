/*
** zc_send.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:06:55 2014 raphael defreitas
** Last update Tue Jul  1 19:27:27 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<string.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zc_send(t_zc *this, const char *packet)
{
  char		*tmp;

  if (this->has_to_stop)
    return ;
  tmp = NULL;
  if ((tmp = strdup(packet)) == NULL ||
      list_enqueue(this->pckts_to_snd, tmp) == RET_FAILURE)
    {
      zc_handle_errno(this, "packet to send queuing failed");
      free(tmp);
    }
}
