/*
** player.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 11:57:43 2014 damien sauvalle
** Last update Mon Jun 30 17:22:42 2014 damien sauvalle
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

# include	"inventory.h"

typedef enum
  {
    DIRECTION_NORTH,
    DIRECTION_SOUTH,
    DIRECTION_EST,
    DIRECTION_WEST
  }	t_direction;

typedef struct	s_player
{
  t_inventory	inventory;
  t_direction	direction;
  unsigned int	x;
  unsigned int	y;
  char		*team_name;
  char		level; /* level and view range*/
  unsigned int	life;
  /*  ? handler --> action ?*/
}		t_player;

/*
** Player
*/
int			player_ctor(t_player *);
void			player_dtor(t_player *);

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
char			*player_get_team_name(t_player *);/* Really util ?*/

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

#endif /* !PLAYER_H_ */
