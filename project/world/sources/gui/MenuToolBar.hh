/* 
 * File:   MenuToolBar.hh
 * Author: marie
 *
 * Created on July 2, 2014, 3:23 PM
 */

#ifndef MENUTOOLBAR_HH
#define	MENUTOOLBAR_HH

#include    <irrlicht.h>

using namespace irr;

class MenuToolBar : public gui::IGUIToolBar
{
public:
    MenuToolBar(gui::IGUIEnvironment *env, gui::IGUIElement *parent, s32 id, core::rect<s32> rectangle);
    MenuToolBar(MenuToolBar const& orig);
    virtual ~MenuToolBar();
private:

};

#endif	/* MENUTOOLBAR_HH */

