/*
** zappy.h for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:15:24 2014 raphael defreitas
** Last update Mon May 12 17:58:45 2014 raphael defreitas
*/

#ifndef		ZAPPY_H_
# define	ZAPPY_H_

/*
** +----------+
** | Includes |
** +----------+
*/
# include	"list.h"
# include	"socket.h"

/*
** +-------------+
** | Definitions |
** +-------------+
*/
# ifndef	RET_ERROR
#  define	RET_ERROR	-1
# endif /* !RET_ERROR */

# ifndef	RET_SUCCESS
#  define	RET_SUCCESS	0
# endif /* !RET_SUCCESS */

# ifndef	RET_FAILURE
#  define	RET_FAILURE	1
# endif /* !RET_FAILURE */

/*
** +---------+
** | Command |
** +---------+
*/
typedef	struct
{
  unsigned int	x;
  unsigned int	y;
}		t_cmd_msz;

typedef	struct
{
  unsigned int	x;
  unsigned int	y;
  unsigned char	food;
  unsigned char	linemate;
  unsigned char	deraumere;
  unsigned char	sibur;
  unsigned char	mendiane;
  unsigned char	phiras;
  unsigned char	thystame;
}		t_cmd_bct;

/*
** +-----------------------+
** | Typedef client/server |
** +-----------------------+
*/
typedef	struct	s_zs		t_zs;
typedef	struct	s_zc		t_zc;

/*
** +--------+
** | Server |
** +--------+
*/
struct		s_zs
{
  t_socket	socket;
  t_list	clients;
};

t_zs		*zs_new(int);
int		zs_ctor(t_zs *, int);
void		zs_dtor(t_zs *);
void		zs_delete(t_zs *);

/*
** +--------+
** | Client |
** +--------+
*/
struct	s_zc
{
  t_socket	socket;
};

t_zc		*zc_new(const char *, int);
int		zc_ctor(t_zc *, const char *, int);
void		zc_dtor(t_zc *);
void		zc_delete(t_zc *);

#endif /* !ZAPPY_H_*/
