/*
** zs_ctor_cmd_fptrs.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:51:34 2014 raphael defreitas
** Last update Fri Jul 11 19:56:19 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static int	player_cmd_fptrs(t_zs *this)
{
  if (list_enqueue(this->cmd_fptrs, &zs_cmd_team_name) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_forward) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_left) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_right) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);

}

static int	graphic_cmd_fptrs(t_zs *this)
{
  if (list_enqueue(this->cmd_fptrs, &zs_cmd_graphic) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_msz) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_bct) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_mct) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_tna) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_ppo) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_plv) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_pin) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_sgt) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_sst) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_cmd_pfk) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);

}

static int	rmt_cmd_fptrs(t_zs *this)
{
  if (list_enqueue(this->cmd_fptrs, &zs_cmd_rmt) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_rmt_pubkey) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_rmt_stop) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zs_rmt_teams) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);

}

int		zs_ctor_cmd_fptrs(t_zs *this)
{
  if (player_cmd_fptrs(this) == RET_FAILURE ||
      graphic_cmd_fptrs(this) == RET_FAILURE ||
      rmt_cmd_fptrs(this) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
