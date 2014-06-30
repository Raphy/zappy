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

# include	"WorldEngine.hh"
# include	"MapViewer.hh"
# include	"MapObject.hh"

using namespace irr;

class Binder
{
public:
    static Binder * getInstance(int winW = 800, int winH = 600,
	    bool realUserMode = false);
    
    //retournera GameEngine au lieu de WorldEngine si realUserMode est activé
    IEngine*		    createEngine() const { return new WorldEngine(); }

    /* GUI */
    gui::IGUIMeshViewer*    createMapViewer(gui::IGUIEnvironment* env, scene::ISceneManager* smgr) const
    { return new MapViewer(env, smgr); }

    /* SCENE */
//    scene::ISceneNode*	    createMapNode(scene::ISceneNode* parent, scene::ISceneManager* smgr) const
//    { return new MapNode(parent, smgr); }
    IObject*	createMapObject(scene::ISceneManager* smgr, IObject* parent) const
    { return new MapObject(smgr, parent); }

private:
    Binder(int winW = 800, int winH = 600, bool realUserMode = false);
    ~Binder();
    
    int		_winW, _winH;
    bool	_realUserMode;
};

#endif