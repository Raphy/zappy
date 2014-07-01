/*
** zt_rsa_delete.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 01:38:28 2014 raphael defreitas
** Last update Tue Jul  1 01:38:57 2014 raphael defreitas
*/

#include	<openssl/rsa.h>

void		zt_rsa_delete(RSA *rsa)
{
  if (rsa)
    RSA_free(rsa);
}
