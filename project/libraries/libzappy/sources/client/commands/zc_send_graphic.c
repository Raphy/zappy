/*
** zc_send_graphic.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Sun Jun 29 10:14:37 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_graphic(t_zc *this)
{
  if (this == NULL)
    return ;
  zc_send(this, "GRAPHIC\n");
}
