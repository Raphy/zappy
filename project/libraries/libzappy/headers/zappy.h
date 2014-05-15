/*
** zappy.h for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:15:24 2014 raphael defreitas
** Last update Thu May 15 11:21:42 2014 raphael defreitas
*/

#ifndef		ZAPPY_H_
# define	ZAPPY_H_

/*
** +----------+
** | Includes |
** +----------+
*/
# include	<sys/select.h>
# include	<sys/time.h>

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
** +----------+
** | Typedefs |
** +----------+
*/
typedef	struct	s_zs		t_zs;
typedef	struct	s_zc		t_zc;
typedef	struct	timeval		t_timeval;

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
** +-------+
** | Hooks |
** +-------+
*/
typedef	enum
  {
    ZHT_UNKNOWN,
    ZHT_TIMEOUT,
    ZHT_NEW_CLIENT,
    ZHT_CMD_MSZ,
    ZHT_CMD_BCT,
    ZHT_MAX
  }		t_zht;

typedef	struct
{
  t_zht		type;
  void		(*handler)();
  void		*data;
}		t_zh;

/*
** +--------+
** | Server |
** +--------+
*/
struct		s_zs
{
  t_socket	*socket;
  t_list	clients;
  t_zh		hooks[ZHT_MAX];
  fd_set	rfds;
  fd_set	wfds;
  t_timeval	timeout;
};

t_zs		*zs_new(int);
int		zs_ctor(t_zs *, int);
void		zs_dtor(t_zs *);
void		zs_delete(t_zs *);

void		zs_main(t_zs *);

void		zs_set_timeout(t_zs *, time_t, suseconds_t);
t_timeval	zs_get_timeout(t_zs *);
void		zs_disable_timeout(t_zs *);

typedef	void	(*t_zsh_timeout)(t_zs *, void *);
void		zs_hook_timeout(t_zs *, t_zsh_timeout, void *);

typedef	void	(*t_zsh_new_client)(t_zs *, t_zc *, void *);
void		zs_hook_new_client(t_zs *, t_zsh_new_client, void *);

void		zs_hook(t_zs *, t_zht, void (*)(), void *);
void		zs_handle_timeout(t_zs *);
void		zs_handle_new_client(t_zs *, t_zc *);

void		zs_treat_new_client(t_zs *);
void		zs_treat_clients(t_zs *);

/*
** +--------+
** | Client |
** +--------+
*/
struct	s_zc
{
  t_socket	*socket;
};

t_zc		*zc_new(void);
int		zc_ctor(t_zc *);
void		zc_dtor(t_zc *);
void		zc_delete(t_zc *);

#endif /* !ZAPPY_H_*/
