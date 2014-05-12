/*
** zappy.h for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:15:24 2014 raphael defreitas
** Last update Mon May 12 15:52:00 2014 raphael defreitas
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
** +-------+
** | Event |
** +-------+
*/

typedef	enum
  {
    ZET_UNKNOWN,
    ZET_TIMEOUT,
    ZET_CLIENT_CONNECTED,
    ZET_CLIENT_DISCONNECTED,
    ZET_SERVER_DISCONNECTED
  }		t_zet;

typedef struct
{
  t_zet		type;
  int		(*handler)();
  void		*data;
}		t_zeh;

t_zeh		*zeh_new(t_zet, int (*)(), void *);
int		zeh_ctor(t_zeh *, t_zet, int (*)(), void *);
void		zeh_dtor(t_zeh *);
void		zeh_delete(t_zeh *);

/*
** +---------+
** | Command |
** +---------+
*/

/*
** +--------+
** | Server |
** +--------+
*/
typedef	struct	s_zs		t_zs;
struct		s_zs
{
  t_socket	socket;
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
typedef	struct	s_zc		t_zc;
struct	s_zc
{
  t_socket	socket;
};

t_zc		*zc_new(const char *, int);
int		zc_ctor(t_zc *, const char *, int);
void		zc_dtor(t_zc *);
void		zc_delete(t_zc *);

#endif /* !ZAPPY_H_*/
