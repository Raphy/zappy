///* 
// * File:   World.cpp
// * Author: marie
// * 
// * Created on July 3, 2014, 4:40 PM
// */
//
//#include <cerrno>
//#include "World.hh"
//
////World::World()
////{
////}
////
////World::World(World const& orig)
////{
////}
////
////World::~World()
////{
////}
//
//
//static int	init_zappy(t_zc *zc, char *host, int port)
//{
//  if (zc_ctor(zc) == RET_FAILURE)
//    {
////      fprintf(stderr, "Initialization failed: %s\n",
////	      errno == 0 ? "Unknown error" : strerror(errno));
//      return (RET_FAILURE);
//    }
////  printf("Connecting to %s %d...\n", host, port);
////  if (zc_connect(zc, host, port) == RET_FAILURE)
//    {
////      printf("Connection failed!\n");
//      return (RET_FAILURE);
//    }
//  return (RET_SUCCESS);
//}
//
//static int	init_world(t_world *world, t_zc *zc)
//{
//  if (world_ctor(world, zc) == RET_FAILURE)
//    return (RET_FAILURE);
//  world_set_handlers(world);
//  return (RET_SUCCESS);
//}
//
//int		main(int argc, char **argv)
//{
//  t_zc		zc;
//  t_world	world;
//
////  if (argc != 3)
////    exit(printf("Usage: %s [host] [port]\n", argv[0]));
////  if (init_zappy(&zc, argv[1], atoi(argv[2])) == RET_FAILURE ||
////      init_world(&world, &zc) == RET_FAILURE)
////    {
////      world_dtor(&world);
////      zc_dtor(&zc);
////      return (1);
////    }
////  zc_main(&zc);
//  zc_dtor(&zc);
//  world_dtor(&world);
//  return (0);
//}
//
//
//void		world_set_handlers(t_world *self)
//{
////  zc_hook_errno(self->zc, &world_errno_handler, self);
////  zc_hook_connected(self->zc, &world_connected_handler, self);
////  zc_hook_disconnected(self->zc, &world_disconnected_handler, self);
////  zc_hook_timeout(self->zc, &world_timeout_handler, self);
//}
//
//void		world_dtor(t_world *self)
//{
//  if (self == nullptr)
//    return ;
//}
//
//int		world_ctor(t_world *self, t_zc *zc)
//{
//  if (self == nullptr)
//    return (RET_FAILURE);
//  self->zc = zc;
//  return (RET_SUCCESS);
//}
