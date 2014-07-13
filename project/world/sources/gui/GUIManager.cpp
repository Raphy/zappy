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
#include "PlayerObject.hh"
#include "RessourceObject.hh"
#include "EggObject.hh"
#include "CaseObject.hh"
//#include "Compass.hh"

using namespace irr;
using namespace gui;
using namespace core;
using namespace video;
using namespace scene;

GUIManager::GUIManager(IGUIEnvironment* env, IEngine* engine, posi_t const& winSize)
: _env(env), _driver(env->getVideoDriver()), _engine(engine), _x(winSize.first), _y(winSize.second)
{
    _objDisplayers.insert(std::pair<Ids, displayObjInfo_t>(NODE_ID_PLAYER, &GUIManager::displayPlayerInfo));
    _objDisplayers.insert(std::pair<Ids, displayObjInfo_t>(NODE_ID_RESSOURCE, &GUIManager::displayRessourceInfo));
    _objDisplayers.insert(std::pair<Ids, displayObjInfo_t>(NODE_ID_EGG, &GUIManager::displayEggInfo));
    _objDisplayers.insert(std::pair<Ids, displayObjInfo_t>(NODE_ID_CASE, &GUIManager::displayCaseInfo));
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

std::wstring intToWstring(int nb)
{
    std::stringstream stream;
    stream << nb;
    std::string str;
    stream >> str;
    std::wstring wstr(str.begin(), str.end());
    return wstr;
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
    
    s32 columnCount = _teamTable->getColumnCount();
    float columnSize = (float)_x / (float)(columnCount) * (1.f/3.f);
//    for (s32 i = 0; i < columnCount; i++)
//	_teamTable->setColumnWidth(i, columnSize);
    
    int i = 0;
    for (std::pair<std::string, TeamManager::Team>&& info : infos) {
	const std::string name = info.first;
	const std::wstring wname(name.begin(), name.end());
	if (_teamTable->getRowCount() == i)
	    _teamTable->addRow(i);
	_teamTable->setCellText(i,0, wname.c_str());
	for (int j = 1; j <= Assets::LEVEL_MAX; j++)
	{
	    const std::wstring wlevel = intToWstring(info.second.players_by_level[j - 1]);
	    _teamTable->setCellText(i,j, wlevel.c_str());
	}
	for (int j = Assets::LEVEL_MAX + 1; j < RESSOURCE_TYPE_COUNT + Assets::LEVEL_MAX; j++)
	{
	    const std::wstring wressource = intToWstring(info.second.ressources[j - Assets::LEVEL_MAX - 1]);
	    _teamTable->setCellText(i,j, wressource.c_str());
	}
	const std::wstring wegg = intToWstring(info.second.eggs);
	_teamTable->setCellText(i,columnCount-1, wegg.c_str());
	i++;
    }
}

//void GUIManager::updateDirection(f32 angle)
//{
//    (void)angle;
//    ////    _compass->updateDirection(angle);
//    //    _compass->SetCompassHeading(angle);
//}

bool GUIManager::updateNodeInformation(const INodeObject* obj)
{
    ISceneNode* node = nullptr;
    if (!obj || !(node = obj->getNode())
	    || _currentObj == obj)
	return false;
    _currentObj = obj;

    _information->clear();
    //Check id ?
    (this->*(_objDisplayers[static_cast<Ids>(node->getID())]))(obj);
}

void GUIManager::displayPlayerInfo(const INodeObject* obj)
{
    PlayerObject const* player = static_cast<PlayerObject const*>(obj);
    
    _information->addItem(L"Player");
}
void GUIManager::displayRessourceInfo(const INodeObject* obj)
{
    RessourceObject const* ressource = static_cast<RessourceObject const*>(obj);
    
    _information->addItem(L"Ressource");
}
void GUIManager::displayEggInfo(const INodeObject* obj)
{
    EggObject const* egg = static_cast<EggObject const*>(obj);
    
    _information->addItem(L"Egg");
}
void GUIManager::displayCaseInfo(const INodeObject* obj)
{
    CaseObject const* caseObj = static_cast<CaseObject const*>(obj);
    
    _information->addItem(L"Case");
}
