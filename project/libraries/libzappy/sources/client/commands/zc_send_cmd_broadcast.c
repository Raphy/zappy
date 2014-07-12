/*
** zc_send_broadcast.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Sun Jul 13 00:44:47 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_broadcast(t_zc *this, const char *message)
{
  if (this == NULL || message == NULL)
    return ;
  zc_send(this, "broadcast ");
  zc_send(this, message);
  zc_send(this, "\n");
}
