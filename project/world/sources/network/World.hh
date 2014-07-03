//    /* 
// * File:   World.hh
// * Author: marie
// *
// * Created on July 3, 2014, 4:40 PM
// */
//
//#ifndef WORLD_HH
//#define	WORLD_HH
//
////extern "C"
////{
////    #include	"zappy.h"
////}
//
//# ifndef	RET_ERROR
//#  define	RET_ERROR	-1
//# endif /* !RET_ERROR */
//
//# ifndef	RET_SUCCESS
//#  define	RET_SUCCESS	0
//# endif /* !RET_SUCCESS */
//
//# ifndef	RET_FAILURE
//#  define	RET_FAILURE	1
//# endif /* !RET_FAILURE */
//
///*
//** +--------------+
//** | Evenemential |
//** +--------------+
//*/
//
//typedef	enum
//  {
//    ZHT_UNKNOWN,
//    ZHT_ERRNO,
//    ZHT_CALLBACK,
//    ZHT_CLIENT_CONNECTED,
//    ZHT_CLIENT_DISCONNECTED,
//    ZHT_TIMEOUT,
//    ZHT_STDIN,
//    ZHT_CMD_MIN,
//    ZHT_CMD_UNKNOWN,
//    ZHT_CMD_WELCOME,
//    ZHT_CMD_TEAM_NAME,
//    ZHT_CMD_GRAPHIC,
//    ZHT_CMD_RMT,
//    ZHT_CMD_MAX,
//    ZHT_RMT_MIN,
//    ZHT_RMT_PUBKEY,
//    ZHT_RMT_STOP,
//    ZHT_RMT_MAX,
//    ZHT_MAX
//  }		t_zht;
//
//typedef	struct
//{
//  t_zht		type;
//  void		(*handler)();
//  void		*data;
//}		t_zh;
//
///*
//** +----------+
//** | Typedefs |
//** +----------+
//*/
//
//typedef	struct s_zs		t_zs;
//typedef	struct s_zc		t_zc;
//typedef	struct timeval		t_timeval;
//
//typedef	enum
//  {
//    ZCT_UNKNOWN,
//    ZCT_GRAPHIC,
//    ZCT_PLAYER,
//    ZCT_RMT
//  }		t_zct;
//
//struct		s_zc
//{
//  /*
//  ** Client only
//  */
//  t_zh		*hooks;
////  fd_set	rfds;
////  fd_set	wfds;
////  t_timeval	timeout;
//  bool		has_to_stop;
////  t_list	*cmd_fptrs;
////  t_list	*stdin;
//  char		*pubkey;
////  RSA		*key_decrypt;
//
//  /*
//  ** Server only
//  */
////  t_zct		type;
////  bool		has_to_disconnect;
////  t_list	*commands;
////  RSA		*key_encrypt;
////
////  /*
////  ** Common
////  */
////  t_socket	*socket;
////  t_list	*pckts_rcvd;
////  t_list	*pckts_to_snd;
//};
//
///*
//** [Con|Des]structors
//*/
//t_zc		*zc_new(void);
//int		zc_ctor(t_zc *_this);
//void		zc_delete(t_zc *_this);
//void		zc_dtor(t_zc *zc);
//
//
////class World
////{
////public:
////    World();
////    World(const World& orig);
////    virtual ~World();
////private:
////
////};
//
//
////typedef	void	(t_zch_basic)(t_zc *zc, void *data);
////typedef	void	(t_zch_str_basic)(t_zc *zc, const char *str, void *data);
////typedef	void	(t_zch_errno)(t_zc *zc, int err, const char *msg, void *data);
////typedef	void	(t_zch_callback)(t_zc *zc, t_zht type, void *data);
//
////void		zc_hook_errno(t_zc *self, t_zch_errno h, void *d);
////void		zc_hook_callback(t_zc *self, t_zch_callback h, void *d);
//
//typedef	struct
//{
//  t_zc		*zc;
//}		t_world;
//
//int		world_ctor(t_world *self, t_zc *zc);
//void		world_dtor(t_world *self);
//
//void		world_set_handlers(t_world *self);
//
//void		world_errno_handler(t_zc *, int , const char *, void *);
//void		world_connected_handler(t_zc *, void *);
//void		world_disconnected_handler(t_zc *, void *);
//void		world_timeout_handler(t_zc *, void *);
//void		world_callback_handler(t_zc *, t_zht, void *);
//void		world_stdin_handler(t_zc *, const char *, void *);
//void		world_cmd_welcome_handler(t_zc *, void *);
//void		world_rmt_pubkey_handler(t_zc *, const char *, void *);
//
//
//#endif	/* WORLD_HH */
//
