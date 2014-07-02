/*
** zs_send_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 02:52:24 2014 raphael defreitas
** Last update Wed Jul  2 02:24:41 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_rmt_pubkey(t_zs *this, t_zc *zc)
{
  if (this == NULL)
    return ;
  if (this->pubkey == NULL ||
      this->key_encrypt == NULL ||
      this->key_decrypt == NULL)
    return ;
  zs_send(this, zc, "RMT PUBKEY ");
  zs_send(this, zc, this->pubkey);
  zs_send(this, zc, "\n");
}
