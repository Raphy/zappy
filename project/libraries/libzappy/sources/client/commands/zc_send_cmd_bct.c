/*
** zc_send_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Thu Jul 10 01:09:38 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_cmd_bct(t_zc *this, const t_position *position)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "bct %u %u\n", position->x, position->y);
  zc_send(this, buf);
}
