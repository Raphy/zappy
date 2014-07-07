/*
** zc_send_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Mon Jul  7 18:01:19 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_cmd_bct(t_zc *this, t_position *position)
{
  char		buf[30];

  if (this == NULL)
    return ;
  sprintf(buf, "bct %u %d\n", position->x, position->y);
  zc_send(this, buf);
}
