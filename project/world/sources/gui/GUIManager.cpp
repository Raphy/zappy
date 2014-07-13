/* 
 * File:   GUIManager.cpp
 * Author: marie
 * 
 * Created on July 8, 2014, 2:23 PM
 */

#include <iostream>
#include "GUIManager.hh"
#include "IEngine.hh"
#include "enums.hh"
#include "TeamManager.hh"
//#include "Compass.hh"

using namespace irr;
using namespace gui;
using namespace core;
using namespace video;

GUIManager::GUIManager(IGUIEnvironment* env, IEngine* engine, posi_t const& winSize)
: _env(env), _driver(env->getVideoDriver()), _engine(engine), _x(winSize.first), _y(winSize.second)
{
}

//GUIManager::GUIManager(GUIManager const& orig)
//{
//}

GUIManager::~GUIManager()
{
    //    delete _compass;
}

bool GUIManager::init()
{
    std::cout << "init gui with size x = " << _x * 2.0/3.0 << " and y = " << _y * 1.0/4.0 << std::endl;
    std::cout << "init gui with size x = " << _x << " and y = " << _y << std::endl;
    //    IGUIToolBar* menu = _env->addToolBar(nullptr, GUI_ID_MENU);
    
    /* MENU */
        
    recti   help_rect;
    help_rect.UpperLeftCorner.X = _x * (1./5.) * (2./3.);
    help_rect.UpperLeftCorner.Y = _y * (1./3.) * (3./4.);
    help_rect.LowerRightCorner.X = _x * (4./5.) * (2./3.);
    help_rect.LowerRightCorner.Y = _y * (2./3.) * (3./4.);
    _help = _env->addWindow(help_rect, false, L"Help", nullptr, GUI_ID_HELP);
    
    _env->addStaticText(L"F3 - FPS/Classic Camera",
	    recti(0,30,help_rect.LowerRightCorner.X,50), false, true, _help, -1/**/);
    
    _menu = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_MENU, true);
    _menu->setRelativePosition(recti((_x * 2./3.), 0, _x, (_y * 1./5.)));
    //    _menu->setItemOverrideColor(0, SColor(255, 0, 0, 100));
        
    _camera = _env->addComboBox(recti(200,5, 200 + 100, 5 + 20), _menu, GUI_ID_MENU_CAMERA_CHOICE);
    _camera->addItem(L"Classic", GUI_ID_MENU_CAMERA_CLASSIC_BUTTON);
    _camera->addItem(L"FPS", GUI_ID_MENU_CAMERA_FPS_BUTTON);
    
    
    /* TEAMS */
    
    _teams = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_TEAM_INFO, true);
    _teams->setRelativePosition(recti(0, (_y * 3./4.), (_x * 2./3.), _y));

    TeamManager const* teamManager = _engine->getTeamManager();
    std::map<std::string, TeamManager::Team> const& infos = teamManager->getTeamsInfo();

    for (std::pair<std::string, TeamManager::Team>&& info : infos) {
	(void)infos;
	_teams->addItem(L"toto");
//	teams->addItem(info.first);
    }
        
    /* INFORMATION */
    
    _information = _env->addListBox(recti(0,0,0,0), nullptr, GUI_ID_INFORMATION, true);
    _information->setRelativePosition(recti((_x * 2./3.), (_y * 1./5.), _x, _y));
    
    return true;
}

bool GUIManager::update()
{
    TeamManager const* teamManager = _engine->getTeamManager();
    std::map<std::string, TeamManager::Team> const& infos = teamManager->getTeamsInfo();
    
    _teams->clear();

    for (std::pair<std::string, TeamManager::Team>&& info : infos) {
	(void)infos;
	_teams->addItem(L"toto");
//	teams->addItem(info.first);
    }
    return true;
}



void GUIManager::updateDirection(f32 angle)
{
    (void)angle;
    ////    _compass->updateDirection(angle);
    //    _compass->SetCompassHeading(angle);
}

void GUIManager::updateNodeInformation(const INodeObject* node)
{
    (void)node;
    //if node != currentNode
    _information->clear();
    //...
    //_classNames[node->getId()];
    
    //sinon juste update info
}
