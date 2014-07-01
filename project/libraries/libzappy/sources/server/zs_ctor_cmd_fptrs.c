/*
** zs_ctor_cmd_fptrs.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:51:34 2014 raphael defreitas
** Last update Tue Jul  1 01:52:30 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

int		zs_ctor_cmd_fptrs(t_zs *this)
{
  if (list_enqueue(this->cmd_fptrs, (void *)&zs_cmd_team_name) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, (void *)&zs_cmd_graphic) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, (void *)&zs_cmd_rmt) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
