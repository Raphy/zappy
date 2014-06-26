/*
** zs_hook_new_client.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Thu Jun 26 11:55:04 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zs_hook_new_client(t_zs *this, t_zsh_new_client h, void *d)
{
  if (this == NULL)
    return ;
  zs_hook(this, ZHT_NEW_CLIENT, h, d);
}
