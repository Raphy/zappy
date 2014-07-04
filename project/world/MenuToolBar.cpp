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
MenuToolBar::MenuToolBar(IGUIEnvironment *env)
: IGUIToolBar(env, nullptr, GUI_ID_MENU, rect<s32>(vector2di(10,10), vector2di(10,10)))
{
//   Environment->addButton(core::rect<s32>(core::vector2di(0,0), core::vector2di(10,10)));
//   Environment->addCheckBox(true, core::rect<s32>(core::vector2di(0,0), core::vector2di(10,10)), nullptr, -1, "CameraFPS");

//    Environment->addButton(rect<s32>(10,240,110,240 + 32), 0, GUI_ID_MENU_CAMERA_CLASSIC_BUTTON,
//    L"Classic Camera", L"Switch to classic camera");
//    Environment->addButton(rect<s32>(10,280,110,280 + 32), 0, GUI_ID_NEW_WINDOW_BUTTON,
//    L"New Window", L"Launches a new Window");
//    Environment->addButton(rect<s32>(10,320,110,320 + 32), 0, GUI_ID_FILE_OPEN_BUTTON,
//    L"File Open", L"Opens a file");

    //! Adds a button to the tool bar
//		virtual IGUIButton* addButton(s32 id=-1, const wchar_t* text=0,const wchar_t* tooltiptext=0,
//			video::ITexture* img=0, video::ITexture* pressedimg=0,
//			bool isPushButton=false, bool useAlphaChannel=false) = 0;

}

MenuToolBar::MenuToolBar(MenuToolBar const& orig)
: IGUIToolBar(static_cast<IGUIToolBar const&>(orig))
{
}

MenuToolBar::~MenuToolBar()
{
}

