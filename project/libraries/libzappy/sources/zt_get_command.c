/*
** zt_get_command.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jun 28 02:21:31 2014 raphael defreitas
** Last update Sat Jun 28 05:37:18 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"socket.h"
#include	"list.h"

/*
static void	restore(t_list *packets, t_list *build)
{
  t_item	*item;

  item = build->back;
  while (item)
    {
      list_push(packets, item_data(item));
      item = item->prev;
    }
}
*/
int		zt_get_command(t_list *packets, char **command)
{
  *command = NULL;
  return (RET_SUCCESS);
}
