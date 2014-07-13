/*
** zs_send_cmd_pic.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sat Jul 12 12:17:01 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_pic(t_zs *this, t_zc *zc, const t_pic *pic)
{
  char		buf[50];
  unsigned int	i;

  if (this == NULL)
    return ;
  sprintf(buf, "pic %u %u %u ", pic->position.x, pic->position.y, pic->level);
  zs_send(this, zc, buf);
  i = 0;
  while (i < pic->nb_uids)
    {
      buf[0] = 0;
      sprintf(buf, "%d%s", pic->uids[i], i == pic->nb_uids ? "\n" : " ");
      zs_send(this, zc, buf);
      i++;
    }
}
