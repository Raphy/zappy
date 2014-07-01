/*
** zappy.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Tue Jun 24 16:21:11 2014 raphael defreitas
** Last update Tue Jul  1 16:06:39 2014 raphael defreitas
*/

#ifndef		ZAPPY_H_
# define	ZAPPY_H_

/*
** +----------+
** | Required |
** +----------+
*/

# include	<glib.h>
# include	<openssl/rsa.h>
# include	<stdbool.h>
# include	<sys/select.h>
# include	<sys/time.h>

# include	"list.h"
# include	"socket.h"

G_BEGIN_DECLS

/*
** +--------+
** | Macros |
** +--------+
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
** +--------------+
** | Evenemential |
** +--------------+
*/

typedef	enum
  {
    ZHT_UNKNOWN,
    ZHT_ERRNO,
    ZHT_CALLBACK,
    ZHT_CLIENT_CONNECTED,
    ZHT_CLIENT_DISCONNECTED,
    ZHT_TIMEOUT,
    ZHT_STDIN,
    ZHT_CMD_UNKNOWN,
    ZHT_CMD_WELCOME,
    ZHT_CMD_TEAM_NAME,
    ZHT_CMD_GRAPHIC,
    ZHT_CMD_RMT,
    ZHT_RMT_PUBKEY,
    ZHT_RMT_STOP,
    ZHT_MAX
  }		t_zht;

typedef	struct
{
  t_zht		type;
  void		(*handler)();
  void		*data;
}		t_zh;

/*
** +----------+
** | Typedefs |
** +----------+
*/

typedef	struct s_zs		t_zs;
typedef	struct s_zc		t_zc;
typedef	struct s_zg		t_zg;
typedef	struct timeval		t_timeval;

/*
** +--------+
** | Server |
** +--------+
*/

struct		s_zs
{
  t_socket	*socket;
  t_list	*clients;
  t_zh		*hooks;
  fd_set	rfds;
  fd_set	wfds;
  t_timeval	timeout;
  bool		has_to_stop;
  t_list	*team_names;
  t_list	*cmd_fptrs;
  char		*public_key_str;
  RSA		*public_key;
  RSA		*private_key;
};

/*
** [Con|Des]structors
*/
t_zs		*zs_new(int port, t_list *team_names);
int		zs_ctor(t_zs *this, int port, t_list *team_names);
void		zs_delete(t_zs *this);
void		zs_dtor(t_zs *this);

void		zs_main(t_zs *this);

/*
** Actions
*/
void		zs_main(t_zs *this);
int		zs_set_rsa_keys(t_zs *this, const char *public_key_filename,
				const char *private_key_filename);
void		zs_disable_timeout(t_zs *this);
void		zs_stop(t_zs *this);

/*
** [G/S]etters
*/
void		zs_set_timeout(t_zs *this, time_t sec, suseconds_t usec);
t_timeval	zs_get_timeout(t_zs *this);

/*
** +--------+
** | Client |
** +--------+
*/

typedef	enum
  {
    ZCT_UNKNOWN,
    ZCT_GRAPHIC,
    ZCT_PLAYER,
    ZCT_RMT
  }		t_zct;

struct		s_zc
{
  /*
  ** Client only
  */
  t_zh		*hooks;
  fd_set	rfds;
  fd_set	wfds;
  t_timeval	timeout;
  bool		has_to_stop;
  t_list	*cmd_fptrs;
  t_list	*stdin;
  RSA		*pubkey;

  /*
  ** Server only
  */
  t_zct		type;
  bool		has_to_disconnect;
  t_list	*commands;

  /*
  ** Common
  */
  t_socket	*socket;
  t_list	*pckts_rcvd;
  t_list	*pckts_to_snd;
};

/*
** [Con|Des]structors
*/
t_zc		*zc_new(void);
int		zc_ctor(t_zc *this);
void		zc_delete(t_zc *this);
void		zc_dtor(t_zc *zc);

/*
** Actions
*/
void		zc_main(t_zc *this);
int		zc_connect(t_zc *this, const char *host, int port);
void		zc_disconnect(t_zc *this);
void		zc_disable_timeout(t_zc *this);

/*
** [G/S]etters
*/
void		zc_set_timeout(t_zc *this, time_t sec, suseconds_t usec);
t_timeval	zc_get_timeout(t_zc *this);

/*
** For server operations only
*/
t_zct		zc_get_type(t_zc *this);
void		zc_set_type(t_zc *this, t_zct type);

/*
** +-------+
** | Tools |
** +-------+
*/

/*
** RSA key pairing creation
*/
RSA		*zt_rsa_new(const char *key, bool is_public);
void		zt_rsa_delete(RSA *rsa);

G_END_DECLS

/*
** +-------------------+
** | Separated headers |
** +-------------------+
*/

# include	"zappy_hooks.h"
# include	"zappy_commands.h"

#endif /* !ZAPPY_H_*/
