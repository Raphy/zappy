/*
** zt_get_rmt_cmd.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jul  2 11:03:55 2014 raphael defreitas
** Last update Wed Jul  2 11:25:31 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

#include	"my.h"
#include	"_zappy.h"

bool		zt_get_rmt_cmd(RSA *rsa, const char *cmd, char **cmdd, int *ret)
{
  *cmdd = NULL;
  if (!my_match(cmd, "RMT CMD * *"))
    return (false);
  *ret = zt_rmt_decrypt(rsa, cmd, cmdd);
  if (*cmdd == NULL)
    return (false);
  return (true);
}
