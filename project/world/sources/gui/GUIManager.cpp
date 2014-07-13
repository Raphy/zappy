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
    std::cout << "init gui with size x = " << _x << " and y = " << _y << std::endl;
    //    IGUIToolBar* menu = _env->addToolBar(nullptr, GUI_ID_MENU);
    
    /* MENU */
    
    _help = _env->addWindow(_rectZero, false, L"Help", nullptr, GUI_ID_HELP);
    
    _env->addStaticText(L"F3 - FPS/Classic Camera",
	    recti(0,30,0,50), false, true, _help, -1/**/);
    
    _menu = _env->addListBox(_rectZero, nullptr, GUI_ID_MENU, true);
    
    _camera = _env->addComboBox(_rectZero, _menu, GUI_ID_MENU_CAMERA_CHOICE);
    _camera->addItem(L"Classic", GUI_ID_MENU_CAMERA_CLASSIC_BUTTON);
    _camera->addItem(L"FPS", GUI_ID_MENU_CAMERA_FPS_BUTTON);
    
    /* TEAMS */
    
    //    _teams = _env->addListBox(_rectZero, nullptr, GUI_ID_TEAM_INFO, true);
    
    _teamTable = _env->addTable(_rectZero, nullptr/*, GUI_ID_TEAM_TABLE*/);
    
    //    TeamManager const* teamManager = _engine->getTeamManager();
    //    std::map<std::string, TeamManager::Team> const& infos = teamManager->getTeamsInfo();
    //    
    //    for (std::pair<std::string, TeamManager::Team>&& info : infos) {
    //	const std::string name = info.first;
    //	const std::wstring wname(name.begin(), name.end());
    //	_teams->addItem(wname.c_str());
    //    }
    
    /* INFORMATION */
    
    _information = _env->addListBox(_rectZero, nullptr, GUI_ID_INFORMATION, true);
    
    resize();
    updateTeamsViewer();
    return true;
}

bool GUIManager::update()
{
    dimension2du winSize = _driver->getScreenSize();
    if (_x != winSize.Width || _y != winSize.Height)
    {
	_x = winSize.Width;
	_y = winSize.Height;
        resize();
    }
    updateTeamsViewer();
    return true;
}

void GUIManager::resize()
{
    if (_help)
    {
	recti   help_rect;
	help_rect.UpperLeftCorner.X = _x * (1./5.) * (2./3.);
	help_rect.UpperLeftCorner.Y = _y * (1./3.) * (3./4.);
	help_rect.LowerRightCorner.X = _x * (4./5.) * (2./3.);
	help_rect.LowerRightCorner.Y = _y * (2./3.) * (3./4.);
        _help->setRelativePosition(help_rect);
    }
    
    _menu->setRelativePosition(recti((_x * 2./3.), 0, _x, (_y * 1./5.)));
    _camera->setRelativePosition(recti(200,5, 200 + 100, 5 + 20));//l'echelle a prendre en compte
    
    _teamTable->setRelativePosition(recti(0, (_y * 3./4.), (_x * 2./3.), _y));
    
    _information->setRelativePosition(recti((_x * 2./3.), (_y * 1./5.), _x, _y));
}

void GUIManager::updateTeamsViewer()
{
    TeamManager const* teamManager = _engine->getTeamManager();
    std::map<std::string, TeamManager::Team> const& infos = teamManager->getTeamsInfo();
    
    _teamTable->clear();
    _teamTable->addColumn(L"Teams");
    _teamTable->addColumn(L"1");
    _teamTable->addColumn(L"2");
    _teamTable->addColumn(L"3");
    _teamTable->addColumn(L"4");
    _teamTable->addColumn(L"5");
    _teamTable->addColumn(L"6");
    _teamTable->addColumn(L"7");
    _teamTable->addColumn(L"8");
    _teamTable->addColumn(L"Food");
    _teamTable->addColumn(L"s1");
    _teamTable->addColumn(L"s2");
    _teamTable->addColumn(L"s3");
    _teamTable->addColumn(L"s4");
    _teamTable->addColumn(L"s5");
    _teamTable->addColumn(L"Egg");
    _teamTable->addRow(0);
    
    //    IGUIWindow * skillWindow = irrGui->addWindow(rect<s32>(30, 100, 330, 600), false, L"Skills");
    //skillWindow->setVisible(false);
    //IGUIStaticText * skillCat1 = irrGui->addStaticText(L"Gathering skills",rect<s32>(10, 30, 290, 45),false,true,skillWindow);
    //skillCat1->setOverrideFont(bigFont);
    //IGUITable * skillTree = irrGui->addTable(rect<s32>(10, 55, 290, 110),skillWindow, -1, false);
    //skillTree->addColumn(L"Name");
    //skillTree->addColumn(L"Skill");
    //skillTree->setColumnWidth(0,220);
    //skillTree->setColumnWidth(1,50);
    //skillTree->setColumnOrdering(0, EGCO_FLIP_ASCENDING_DESCENDING);
    //skillTree->setColumnOrdering(1, EGCO_FLIP_ASCENDING_DESCENDING);
    
    int i = 0;
    for (std::pair<std::string, TeamManager::Team>&& info : infos) {
	const std::string name = info.first;
	const std::wstring wname(name.begin(), name.end());
	if (_teamTable->getRowCount() == i)
	    _teamTable->addRow(i);
	_teamTable->setCellText(i,0, wname.c_str());
	for (int j = 1; j <= Assets::LEVEL_MAX; j++)
	{
	    _teamTable->setCellText(i,j, L"33");
	}
	for (int j = Assets::LEVEL_MAX + 1; j < RESSOURCE_TYPE_COUNT + Assets::LEVEL_MAX; j++)
	{
	    _teamTable->setCellText(i,j, L"42");
	}
	_teamTable->setCellText(i, RESSOURCE_TYPE_COUNT + Assets::LEVEL_MAX, "56");
	
	//	_teams->addItem(wname.c_str());
	i++;
    }
}

//void GUIManager::updateDirection(f32 angle)
//{
//    (void)angle;
//    ////    _compass->updateDirection(angle);
//    //    _compass->SetCompassHeading(angle);
//}

void GUIManager::updateNodeInformation(const INodeObject* node)
{
    (void)node;
    //if node != currentNode
    _information->clear();
    //...
    //_classNames[node->getId()];
    
    //sinon juste update info
}
