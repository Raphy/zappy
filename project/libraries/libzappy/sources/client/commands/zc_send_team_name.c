/*
** zc_send_team_name.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Sun Jun 29 10:13:59 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_team_name(t_zc *this, const char *team_name)
{
  if (this == NULL || team_name == NULL)
    return ;
  zc_send(this, team_name);
  zc_send(this, "\n");
}
