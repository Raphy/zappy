/*
** zs_hook_cmd_invocation.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Sun Jul 13 01:20:36 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_hook_cmd_invocation(t_zc *this, t_zsh_client_basic h, void *d)
{
  if (this == NULL)
    return ;
  zc_hook(this, ZHT_CMD_INVOCATION, h, d);
}
