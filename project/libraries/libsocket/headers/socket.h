/*
** socket.h for liboskcet in /home/raphy/Epitech/Libraries/libsocket/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon Apr 14 16:45:01 2014 raphael defreitas
** Last update Thu Jul 10 07:23:56 2014 raphael defreitas
*/

#ifndef		SOCKET_H_
# define	SOCKET_H_

# include	<arpa/inet.h>
# include	<glib.h>
# include	<netinet/in.h>
# include	<sys/socket.h>

G_BEGIN_DECLS

# ifndef	RET_ERROR
#  define	RET_ERROR	-1
# endif /* !RET_ERROR */

# ifndef	RET_SUCCESS
#  define	RET_SUCCESS	0
# endif /* !RET_SUCCESS */

# ifndef	RET_FAILURE
#  define	RET_FAILURE	1
# endif /* !RET_FAILURE */

# ifndef	SOCK_BUF_LEN
#  define	SOCK_BUF_LEN	1024
# endif /* !SOCK_BUF_LEN */

typedef	struct	hostent		t_hostent;

/*
** +--------+
** | Socket |
** +--------+
*/
typedef	struct	sockaddr_in	t_sockaddr_in;

typedef	struct
{
  int		fd;
  int		domain;
  socklen_t	addr_len;
  t_sockaddr_in	addr;
}		t_socket;

int		socket_ctor(t_socket *, int, int, int);
void		socket_dtor(t_socket *);

t_socket	*socket_new(void);
void		socket_delete(t_socket *);

int		socket_fd(t_socket *);
const char	*socket_ip(t_socket *);

int		socket_connect(t_socket *, in_addr_t, int);

int		socket_bind(t_socket *, in_addr_t, int);
int		socket_listen(t_socket *, int);
t_socket	*socket_accept(t_socket *);

int		socket_write(t_socket *, const void *, size_t);
int		socket_read(t_socket *, void *, size_t);

G_END_DECLS

#endif /* !SOCKET_H_*/
