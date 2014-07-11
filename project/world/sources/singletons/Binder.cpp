/*
 ** Binder.cpp for zappy in /home/marie/modules/unix/zappy/zappy/project/world/sources
 **
 ** Made by Marie Lefebvre
 ** Login   <lefebv_z@epitech.eu>
 **
 ** Started on  Mon May  19 14:38:40 2014 Marie Lefebvre
 ** Last update Mon May  19 14:43:04 2014 Marie Lefebvre
 */

//#include <sstream>
//#include "Binder.hh"
//#include "WorldEngine.hh"
//#include "World.hh"
//#include "SafeQueue.hh"
//#include "MapViewer.hh"
////#include "MenuToolBar.hh"
//#include "MapObject.hh"
//#include "AnimatedPersoObject.hh"
//#include "PersoObject.hh"
//#include "RessourceObject.hh"
//#include "MyEventReceiver.hh"
//
////Binder* Binder::getInstance(int winW, int winH,
////	bool realUserMode)
////{
////    static Binder instance(winW, winH, realUserMode);
////    return (&instance);
////}
//Binder* Binder::getInstance(int ac, char **av)
//{
//    static Binder instance(ac, av);
//    return (&instance);
//}
//
////Binder::Binder(int winW, int winH, bool realUserMode)
////: _winW(winW), _winH(winH), _realUserMode(realUserMode)
////{}
//Binder::Binder(int ac, char **av)
//: _winW(800), _winH(600), _realUserMode(false)
//{
//    if (ac != 2 && ac != 4)
//	throw std::string("Bad options.\nUsage : ./world assetsFolder [windowWidth windowHeight]");
//    _path = av[1];
//    if (ac == 4)
//    {
//	std::stringstream str;
//	str << av[2];
//	str >> _winW;
//	str << av[3];
//	str >> _winH;
//	//TODO : recuperer la taille de l'ecran
//	if (_winW < 1 || _winW > 1000 || _winH < 1 || _winH > 800)
//	    throw std::string("Bad window size.");
//    }
//}
//Binder::~Binder()
//{}
//
//
//IEngine*	Binder::createEngine() const
//{
//    IEngine* engine = new WorldEngine();
//    Assets::getInstance(engine->getDevice()->getSceneManager(), _path);
//    //    Ressources::getInstance(engine->getDevice()->getSceneManager(), "./world/assets/irrlicht");
//    return engine;
//}
//
//IEventReceiver* Binder::createEventReceiver(EventContext const& context) const
//{
//    return new MyEventReceiver(context);
//}
//
//IThread* Binder::createNetworkThread(ISafeQueue<t_data *>* eventQueue, ISafeQueue<t_data *>* commandQueue) const
//{
//    return new World(eventQueue, commandQueue);
//}
//
//ISafeQueue<t_data *>* Binder::createNetworkEventQueue() const
//{
//    return new SafeQueue<t_data *>();
//}
//
//
///* GUI */
//gui::IGUIElement*    Binder::createMapViewer(gui::IGUIEnvironment* env,
//	scene::ISceneManager* smgr) const
//{
////    return new MapViewer(env, smgr);
//    return nullptr;
//}
//gui::IGUIElement*	    Binder::createMenuToolbar(gui::IGUIEnvironment* env,
//	scene::ISceneManager* smgr) const
//{
//    (void) smgr;
//    (void) env;
//    //    return new MenuToolBar(env);
//    return nullptr;
//}
//
///* SCENE */
////    scene::ISceneNode*	    createMapNode(scene::ISceneNode* parent, scene::ISceneManager* smgr) const
////    { return new MapNode(parent, smgr); }
////INodeObject*	Binder::createMapObject(scene::ISceneManager* smgr,
////	INodeObject* parent) const
////{
////    return new MapObject(smgr, parent);
////}
////INodeObject*	Binder::createPersoObject(scene::ISceneManager* smgr,
////	INodeObject* parent) const
////{
////    return new AnimatedPersoObject(smgr, parent);
////    //    return new PersoObject(smgr, parent);
////}
////INodeObject*	Binder::createRessourceObject(scene::ISceneManager* smgr,
////	INodeObject* parent) const
////{
////    return new RessourceObject(smgr, parent);
////    //    return new PersoObject(smgr, parent);
////}
//
//template <>
//INodeObject*	Binder::createGameElementObject<MAP>(scene::ISceneManager* smgr,
//	INodeObject* parent) const
//{
//    return new MapObject(smgr, parent);
//}
//template <>
//INodeObject*	Binder::createGameElementObject<PERSO>(scene::ISceneManager* smgr,
//	INodeObject* parent) const
//{
//    return new AnimatedPersoObject(smgr, parent);
//    //    return new PersoObject(smgr, parent);
//}
//template <>
//INodeObject*	Binder::createGameElementObject<RESSOURCE>(scene::ISceneManager* smgr,
//	INodeObject* parent) const
//{
//    return new RessourceObject(smgr, parent);
//}
