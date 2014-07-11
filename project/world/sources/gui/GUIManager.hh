/* 
 * File:   GUIManager.hh
 * Author: marie
 *
 * Created on July 8, 2014, 2:23 PM
 */

#ifndef GUIMANAGER_HH
#define	GUIMANAGER_HH

#include    <irrlicht.h>
#include    "INodeObject.hh"
//#include    "Compass.hh"

using namespace irr;

class GUIManager
{
public:
    GUIManager(gui::IGUIEnvironment* env, posi_t const& winSize);
    GUIManager(const GUIManager& orig);
    virtual ~GUIManager();
    
    void updateDirection(f32 angle);
    void updateNodeInformation(INodeObject const* lastNodeClicked);
private:
    gui::IGUIEnvironment*   _env;
    video::IVideoDriver*    _driver;
//    Compass*	_compass;
    int _x;
    int _y;

    gui::IGUIListBox* _information;
    //...
};

#endif	/* GUIMANAGER_HH */

