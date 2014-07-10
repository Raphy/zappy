/* 
 * File:   GUIManager.cpp
 * Author: marie
 * 
 * Created on July 8, 2014, 2:23 PM
 */

#include <iostream>
#include "GUIManager.hh"
#include "enums.hh"
//#include "Compass.hh"

using namespace irr;
using namespace gui;
using namespace core;
using namespace video;

GUIManager::GUIManager(IGUIEnvironment* env, int x, int y)
: _env(env), _driver(env->getVideoDriver()), _x(x), _y(y)
{
    std::cout << "init gui with size x = " << _x * 2.0/3.0 << " and y = " << _y * 1.0/4.0 << std::endl;
    std::cout << "init gui with size x = " << _x << " and y = " << _y << std::endl;
    //    IGUIToolBar* menu = _env->addToolBar(nullptr, GUI_ID_MENU);
    
    /* MENU */
    
    //    IGUIElement* compass = new Compass(_env, nullptr, recti(0,0,(_x * 1./4.),(_y * 1./4.)));
    
    //    IGUIElement* compass = new Compass(recti(0,0,(_x * 1./4.),(_y * 1./4.)), _env, nullptr);
    
    //       core::rect<s32> gCompassRect;
    //   gCompassRect.UpperLeftCorner.X = 0;
    //   gCompassRect.UpperLeftCorner.Y = 0;
    //   gCompassRect.LowerRightCorner.X = (_x * 1./4.);
    //   gCompassRect.LowerRightCorner.Y = (_y * 1./4.);
    //   gui::IGUIElement* pgRootGuiElement = env->getRootGUIElement();
    //
    //   _compass = new VxCompass( gCompassRect, env, pgRootGuiElement );
    ////    IGUIElement* compass = new Compass(_env, nullptr, gCompassRect);
    //    video::ITexture * pgCompassBodyTexture =   env->getVideoDriver()->getTexture("../media/compass/compass_body.tga");
    //   video::ITexture * pgCompassNeedleTexture =   env->getVideoDriver()->getTexture("../media/compass/compass_needle.tga");
    //
    //   _compass->SetCompassBodyTexture( pgCompassBodyTexture );
    //   _compass->SetCompassNeedleTexture( pgCompassNeedleTexture );
    
    recti   help_rect;
    help_rect.UpperLeftCorner.X = _x * (1./5.) * (2./3.);
    help_rect.UpperLeftCorner.Y = _y * (1./3.) * (3./4.);
    help_rect.LowerRightCorner.X = _x * (4./5.) * (2./3.);
    help_rect.LowerRightCorner.Y = _y * (2./3.) * (3./4.);
    IGUIWindow* help = _env->addWindow(help_rect, false, L"Help", nullptr, -1/*GUI_ID_HELP*/);
    
    _env->addStaticText(L"F3 - FPS/Classic Camera", recti(0,30,help_rect.LowerRightCorner.X,50), false, true, help, -1/**/);
    
    IGUIListBox* menu = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_MENU, true);
    menu->setRelativePosition(recti((_x * 2./3.), 0, _x, (_y * 1./5.)));
    //    menu->setItemOverrideColor(0, SColor(255, 0, 0, 100));
    
    IGUISpinBox* sound = _env->addSpinBox(L"5", recti(0,0,0,0), true, menu, GUI_ID_MENU_SOUND_CHOICE);
    sound->setRelativePosition(recti(10,5,10 + 100,5 + 20));
    sound->setName("Sound Volume");
    sound->setRange(0,10);
    
    IGUIComboBox* camera = _env->addComboBox(recti(200,5, 200 + 100, 5 + 20), menu, GUI_ID_MENU_CAMERA_CHOICE);
    camera->addItem(L"Classic", GUI_ID_MENU_CAMERA_CLASSIC_BUTTON);
    camera->addItem(L"FPS", GUI_ID_MENU_CAMERA_FPS_BUTTON);
    
    
    /* TEAMS */
    
    IGUIListBox* teams = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_TEAM_INFO, true);
    teams->setRelativePosition(recti(0, (_y * 3./4.), (_x * 1./3.), _y));
    
    
    /* CHATS/EVENT */
    
    IGUIListBox* chat = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_CHAT_EVENT, true);
    chat->setRelativePosition(recti((_x * 1./3.), (_y * 3./4.), (_x * 2./3.), _y));
    chat->setAutoScrollEnabled(true);
    for (int i = 0; i < 100; i++)
    {
	chat->addItem(L"elem...");
    }
    
    
    
    /* INVENTORY */
    
    IGUIListBox* inventory = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_INVENTORY, true);
    inventory->setRelativePosition(recti((_x * 2./3.), (_y * 1./5.), _x, _y));
    
    
}

//GUIManager::GUIManager(GUIManager const& orig)
//{
//}

GUIManager::~GUIManager()
{
    //    delete _compass;
}

void GUIManager::updateDirection(f32 angle)
{
    ////    _compass->updateDirection(angle);
    //    _compass->SetCompassHeading(angle);
}
