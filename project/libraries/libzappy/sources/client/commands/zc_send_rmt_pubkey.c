/*
** zc_send_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 02:52:24 2014 raphael defreitas
** Last update Thu Jul  3 22:55:03 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_rmt_pubkey(t_zc *this)
{
  if (this == NULL)
    return ;
  if (this->pubkey == NULL ||
      this->key_encrypt == NULL ||
      this->key_decrypt == NULL)
    return ;
  zc_send(this, "RMT PUBKEY ");
  zc_send(this, this->pubkey);
  zc_send(this, "\n");
}
