/*
** zs_hook_new_client.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:27:55 2014 raphael defreitas
** Last update Thu May 15 11:06:32 2014 raphael defreitas
*/

#include	"zappy.h"

void		zs_hook_new_client(t_zs *this, t_zsh_new_client h, void *d)
{
  zs_hook(this, ZHT_NEW_CLIENT, h, d);
}
