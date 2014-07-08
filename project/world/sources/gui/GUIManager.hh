/* 
 * File:   GUIManager.hh
 * Author: marie
 *
 * Created on July 8, 2014, 2:23 PM
 */

#ifndef GUIMANAGER_HH
#define	GUIMANAGER_HH

#include    <irrlicht.h>

class GUIManager
{
public:
    GUIManager(irr::gui::IGUIEnvironment* env, int x, int y);
    GUIManager(const GUIManager& orig);
    virtual ~GUIManager();
private:
    irr::gui::IGUIEnvironment* _env;
    int _x;
    int _y;
};

#endif	/* GUIMANAGER_HH */

