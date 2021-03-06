/*
** zc_ctor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:49:43 2014 raphael defreitas
** Last update Wed Jul  9 19:08:39 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

static void	default_values(t_zc *this)
{
  this->socket = NULL;
  this->hooks = NULL;
  this->type = ZCT_UNKNOWN;
  zc_disable_timeout(this);
  this->has_to_disconnect = false;
  this->pckts_rcvd = NULL;
  this->pckts_to_snd = NULL;
  this->has_to_stop = false;
  this->cmd_fptrs = NULL;
  this->stdin = NULL;
  this->pubkey = NULL;
  this->key_encrypt = NULL;
  this->key_decrypt = NULL;
  this->uid = 0;
}

int		zc_ctor(t_zc *this)
{
  if (this == NULL)
    return (RET_FAILURE);
  default_values(this);
  if ((this->hooks = calloc(ZHT_MAX, sizeof(t_zh))) == NULL ||
      (this->pckts_rcvd = list_new(&free)) == NULL ||
      (this->pckts_to_snd = list_new(&free)) == NULL ||
      (this->commands = list_new(NULL)) == NULL)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
