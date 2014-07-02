/* 
 * File:   MenuToolBar.cpp
 * Author: marie
 * 
 * Created on July 2, 2014, 3:23 PM
 */

#include "MenuToolBar.hh"
#include "ids.hh"

using namespace core;
using namespace gui;

// TODO : remplir l'enum id avec tous les controls

//IGUIToolBar (IGUIEnvironment *environment, IGUIElement *parent, s32 id, core::rect< s32 > rectangle)
MenuToolBar::MenuToolBar(IGUIEnvironment *env, IGUIElement *parent, s32 id, core::rect<s32> rectangle)
: IGUIToolBar(env, parent, id, rectangle)
{
//   Environment->addButton(core::rect<s32>(core::vector2di(0,0), core::vector2di(10,10)));
//   Environment->addCheckBox(true, core::rect<s32>(core::vector2di(0,0), core::vector2di(10,10)), nullptr, -1, "CameraFPS");

//    Environment->addButton(rect<s32>(10,240,110,240 + 32), 0, GUI_ID_MENU_CAMERA_CLASSIC_BUTTON,
//    L"Classic Camera", L"Switch to classic camera");
//    Environment->addButton(rect<s32>(10,280,110,280 + 32), 0, GUI_ID_NEW_WINDOW_BUTTON,
//    L"New Window", L"Launches a new Window");
//    Environment->addButton(rect<s32>(10,320,110,320 + 32), 0, GUI_ID_FILE_OPEN_BUTTON,
//    L"File Open", L"Opens a file");
}

MenuToolBar::MenuToolBar(MenuToolBar const& orig)
: IGUIToolBar(static_cast<IGUIToolBar const&>(orig))
{
}

MenuToolBar::~MenuToolBar()
{
}

