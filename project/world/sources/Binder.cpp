/*
 ** Binder.cpp for zappy in /home/marie/modules/unix/zappy/zappy/project/world/sources
 **
 ** Made by Marie Lefebvre
 ** Login   <lefebv_z@epitech.eu>
 **
 ** Started on  Mon May  19 14:38:40 2014 Marie Lefebvre
 ** Last update Mon May  19 14:43:04 2014 Marie Lefebvre
 */

#include "Binder.hh"
#include "WorldEngine.hh"
#include "MapViewer.hh"
//#include "MenuToolBar.hh"
#include "MapObject.hh"
#include "PersoObject.hh"

Binder* Binder::getInstance(int winW, int winH,
	bool realUserMode)
{
    static Binder instance(winW, winH, realUserMode);
    return (&instance);
}

Binder::Binder(int winW, int winH, bool realUserMode)
: _winW(winW), _winH(winH), _realUserMode(realUserMode)
{}
Binder::~Binder()
{}


IEngine*	Binder::createEngine() const
{
    return new WorldEngine();
}


/* GUI */
gui::IGUIElement*    Binder::createMapViewer(gui::IGUIEnvironment* env,
	scene::ISceneManager* smgr) const
{
    return new MapViewer(env, smgr);
}
gui::IGUIElement*	    Binder::createMenuToolbar(gui::IGUIEnvironment* env,
				    scene::ISceneManager* smgr) const
{
    (void) smgr;
//    return new MenuToolBar(env);
    return nullptr;
}

/* SCENE */
//    scene::ISceneNode*	    createMapNode(scene::ISceneNode* parent, scene::ISceneManager* smgr) const
//    { return new MapNode(parent, smgr); }
IObject*	Binder::createMapObject(scene::ISceneManager* smgr,
	IObject* parent) const
{
    return new MapObject(smgr, parent);
}
IObject*	Binder::createPersoObject(scene::ISceneManager* smgr,
	IObject* parent) const
{
    return new PersoObject(smgr, parent);
}

