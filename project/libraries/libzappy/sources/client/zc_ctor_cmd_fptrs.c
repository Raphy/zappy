/*
** zc_ctor_cmd_fptrs.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:53:30 2014 raphael defreitas
** Last update Tue Jul  1 04:02:02 2014 raphael defreitas
*/

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

int		zc_ctor_cmd_fptrs(t_zc *this)
{
  if (list_enqueue(this->cmd_fptrs, (void *)&zc_cmd_welcome) == RET_FAILURE ||
      list_enqueue(this->cmd_fptrs, (void *)&zc_rmt_pubkey) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
