/*
** zc_ctor_cmd_fptrs.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:53:30 2014 raphael defreitas
** Last update Sat Jul 12 13:24:54 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static int	player_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, &zc_ok) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_ko) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

static int	graphic_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, &zc_cmd_msz) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_bct) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_tna) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pnw) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_ppo) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_plv) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pin) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pex) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pbc) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pic) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pie) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pfk) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pdr) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pdr) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_pdi) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_enw) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_eht) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_sgt) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

static int	rmt_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, &zc_rmt_authorized) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_rmt_unauthorized) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_rmt_pubkey) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_rmt_teams) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		zc_ctor_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, &zc_cmd_welcome) == RET_FAILURE ||
      player_cmd_fptrs(this) == RET_FAILURE ||
      graphic_cmd_fptrs(this) == RET_FAILURE ||
      rmt_cmd_fptrs(this) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
