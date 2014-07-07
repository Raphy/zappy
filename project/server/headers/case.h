/*
** case.h for  in /home/svirch_n/zappy/project/server/headers
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Jul  7 16:42:06 2014 nicolas svirchevsky
** Last update Mon Jul  7 16:43:48 2014 nicolas svirchevsky
*/

#ifndef		CASE_H_
# define	CASE_H_

# include	"inventory.h"
# include	"list.h"

typedef struct	s_case
{
  t_inventory	inventory;
  t_list	players;
}		t_case;

#endif		/* !CASE_H_ */
