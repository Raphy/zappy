/*
** player.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 11:57:43 2014 damien sauvalle
** Last update Thu Jul 10 14:54:07 2014 damien sauvalle
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

/*
  Faire le TRi des Fcontion il y en a qui servent a rien !! sErieux le C++ faut pas en abuser
 */

typedef struct s_player t_player;

# include	"zappy.h"
# include	"inventory.h"
# include       "bundle.h"
# include	"server.h"

typedef enum
  {
    DIRECTION_NORTH,
    DIRECTION_EST,
    DIRECTION_SOUTH,
    DIRECTION_WEST
  }	t_direction;

typedef enum
  {
    NORMAL,
    INCANTATION,
    FORK
  }	t_etat;

struct		s_player
{
  t_inventory	inventory;
  t_direction	direction;
  unsigned int	x;
  unsigned int	y;
  char		*team_name;
  char		level; /* level and view range*/
  unsigned int	life;
  char		etat; /* ?? util */
  t_zc		*zc;
};

/*
** Player
*/
int			player_ctor(t_player *, t_server *, t_zc *, char *);
void			player_dtor(t_player *);
t_player		*player_new(t_server *,  t_zc *, char *);
void			player_delete(t_player *);

/*
** Direction
*/
void			player_set_direction(t_player *, t_direction);
t_direction		player_get_direction(t_player *);

/*
** coord
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

void			player_apply_action(t_player *, t_bundle *, void *);
void                    player_action_goahead(t_player *, t_bundle *);
void                    player_action_right(t_player *, void *);
void                    player_action_left(t_player *, void *);
void                    player_action_see(t_player *, void *);
void                    player_action_inventory(t_player *, void *);
void                    player_action_pick(t_player *, void *);
void                    player_action_put(t_player *, void *);
void                    player_action_expel(t_player *, void *);
void                    player_action_broacast(t_player *, void *);
void                    player_action_incantation(t_player *, void *);
void                    player_action_fork(t_player *, void *);
void                    player_action_slot_number(t_player *, void *);

/*
** Norme espace !!!
*/

typedef void (*fct_direction)(t_player *, t_arg *);


#endif /* !PLAYER_H_ */
