/* 
 * File:   GUIManager.hh
 * Author: marie
 *
 * Created on July 8, 2014, 2:23 PM
 */

#ifndef GUIMANAGER_HH
#define	GUIMANAGER_HH

#include    <irrlicht.h>
//#include    "Compass.hh"

using namespace irr;

class GUIManager
{
public:
    GUIManager(gui::IGUIEnvironment* env, int x, int y);
    GUIManager(const GUIManager& orig);
    virtual ~GUIManager();
    
    void updateDirection(f32 angle);
private:
    gui::IGUIEnvironment* _env;
//    Compass*	_compass;
    int _x;
    int _y;
};

#endif	/* GUIMANAGER_HH */

