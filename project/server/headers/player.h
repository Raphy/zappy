/*
** player.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 11:57:43 2014 damien sauvalle
** Last update Sun Jul 13 03:19:49 2014 damien sauvalle
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

/*
  Faire le TRi des Fcontion il y en a qui servent a rien !! sErieux le C++ faut pas en abuser
 */

# include	"zappy.h"
# include	"inventory.h"
# include	"server.h"

typedef enum
  {
    NORMAL,
    INCANTATION,
    FORK
  }	t_etat;

typedef struct	s_player
{
  t_items	inventory;
  t_orientation	direction;
  unsigned int	x;
  unsigned int	y;
  char		*team_name;
  unsigned char	level;
  unsigned int	life;
  unsigned char	etat;
  t_zc		*zc;
}		t_player;

/*
** Player
*/
int			player_ctor(t_player *, t_server *, t_zc *, const char *);
void			player_dtor(t_player *);
t_player		*player_new(t_server *,  t_zc *, const char *);
void			player_delete(t_player *);

/*
** Direction
*/
void			player_set_direction(t_player *, t_orientation);
t_orientation		player_get_direction(t_player *);

/*
** 8coord
*/
void			player_set_x(t_player *, int);
void			player_set_y(t_player *, int);

int			player_get_x(t_player *);
int			player_get_y(t_player *);

/*
** Team Name
*/
int			player_set_team_name(t_player *, char *); /* Here ? || ctor*/
char			*player_get_team_name(t_player *); /* Really util ?*/

/*
** Level / Range view
*/
void			player_set_level(t_player *, int);
int			player_get_level(t_player *);

/*
** time life
*/
int			player_set_life(t_player *);
unsigned int		player_get_life(t_player *);

bool    find_by_uid(t_player *, unsigned int *);

/*
** Norme espace !!!
*/



/*
 ** Do not change this structure without controlling its result in handler_incantation.c
 */

struct s_elevation_condition
{
    unsigned int player_required;
    t_items items;
};

#endif /* !PLAYER_H_ */
