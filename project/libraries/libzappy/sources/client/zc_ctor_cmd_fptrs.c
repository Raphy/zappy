/*
** zc_ctor_cmd_fptrs.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:53:30 2014 raphael defreitas
** Last update Wed Jul  9 18:41:58 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static int	player_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, &zc_ok) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_ko) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_FAILURE);
}

static int	graphic_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, &zc_cmd_msz) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_bct) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, &zc_cmd_tna) == RET_FAILURE)
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
