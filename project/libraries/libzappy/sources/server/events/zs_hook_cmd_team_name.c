/*
** zs_hook_cmd_team_name.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Sun Jun 29 06:20:43 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_hook_cmd_team_name(t_zs *this, t_zsh_cmd_team_name h, void *d)
{
  if (this == NULL)
    return ;
  zs_hook(this, ZHT_CMD_TEAM_NAME, h, d);
}
