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
    MenuToolBar(gui::IGUIEnvironment *env);
    MenuToolBar(MenuToolBar const& orig);
    virtual ~MenuToolBar();
private:

};

#endif	/* MENUTOOLBAR_HH */

