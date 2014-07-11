/*
 ** Binder.hh for zappy in /home/marie/modules/unix/zappy/zappy/project/world/sources
 **
 ** Made by Marie Lefebvre
 ** Login   <lefebv_z@epitech.eu>
 **
 ** Started on  Mon May  19 14:33:16 2014 Marie Lefebvre
 ** Last update Mon May  19 15:15:52 2014 Marie Lefebvre
 */

#ifndef		BINDER_HH_
# define	BINDER_HH_
//
//#include	<string>
//#include	"IEngine.hh"
//#include	"IThread.hh"
//#include	"ISafeQueue.hh"
//#include	"INodeObject.hh"
//
//using namespace irr;
//
//TODO : faire une factory pour les Objects et une pour les GUIElem

//class Binder
//{
//public:
////    static Binder* getInstance(int winW = 800, int winH = 600,
////	    bool realUserMode = false);
//    static Binder* getInstance(int ac = 0, char **av = nullptr);
//    
//    IEngine*		    createEngine() const;
//    IEventReceiver*	    createEventReceiver(EventContext const& context) const;
//    ISafeQueue<t_data *>*   createNetworkEventQueue() const;
//    IThread*		    createNetworkThread(ISafeQueue<t_data *>* eventQueue, ISafeQueue<t_data *>* commandQueue) const;
//    
//    /* GUI */
//    gui::IGUIElement*	    createMapViewer(gui::IGUIEnvironment* env,
//					    scene::ISceneManager* smgr) const;
//    gui::IGUIElement*	    createMenuToolbar(gui::IGUIEnvironment* env,
//					    scene::ISceneManager* smgr) const;
//    
//    /* SCENE */
//    template<GameElementType>
//    INodeObject*	createGameElementObject(scene::ISceneManager* smgr,
//				INodeObject* parent) const
//    {
//	(void)smgr;
//	(void)parent;
//	//unknow template
//	return nullptr;
//    }
//
////    INodeObject*	createMapObject(scene::ISceneManager* smgr,
////				INodeObject* parent) const;
////    INodeObject*	createPlayerObject(scene::ISceneManager* smgr,
////				INodeObject* parent) const;
////    INodeObject*	createRessourceObject(scene::ISceneManager* smgr,
////				INodeObject* parent) const;
//    
//private:
////    Binder(int winW = 800, int winH = 600, bool realUserMode = false);
//    Binder(int ac, char **av);
//    ~Binder();
//    
//    int		_winW, _winH;
//    bool	_realUserMode;
//    std::string	_path;
//};

#endif