/*
** zc_send_pick.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Sun Jul 13 00:43:58 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_pick(t_zc *this, const char *item)
{
  if (this == NULL || item == NULL)
    return ;
  zc_send(this, "prend ");
  zc_send(this, item);
  zc_send(this, "\n");
}
