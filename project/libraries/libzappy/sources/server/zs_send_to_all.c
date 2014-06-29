/*
** zs_send_to_all.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 18:58:12 2014 raphael defreitas
** Last update Fri Jun 27 19:10:06 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_to_all(t_zs *this, const char *packet)
{
  t_iterator	it;
  t_zc		*zc;

  iterator_ctor(&it, this->clients, IT_DATA);
  while ((zc = iterator_current(&it)))
    {
      iterator_next(&it);
      zs_send_to_client(this, zc, packet);
    }
  iterator_dtor(&it);
}
