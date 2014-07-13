/* 
 * File:   AEngine.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 12:54 PM
 */

#include <string>
#include <iostream>
#include <driverChoice.h>
#include "AEngine.hh"
#include "SafeQueue.hh"
#include "MyEventReceiver.hh"
#include "GUIManager.hh"
#include "RessourceObject.hh"

using namespace core;
using namespace gui;
using namespace scene;

AEngine::AEngine()
{
    _eventQueue = new SafeQueue<t_data *>();
    _commandQueue = new SafeQueue<t_data *>();
    _networkThread = new World(_eventQueue, _commandQueue);
    _networkThread->start();
    
    //    video::E_DRIVER_TYPE params.DriverType=driverChoiceConsole();
    //    if (params.DriverType==video::EDT_COUNT)
    //    {
    //	std::cout << "WARNING : invalid driver type, Software choose by default." << std::endl;
    //        params.DriverType = video::EDT_SOFTWARE;
    //    }
    _helper = Helper::getInstance();
    _winSize = _helper->getWinSize();
    
    irr::SIrrlichtCreationParameters params;
    params.DriverType=video::EDT_OPENGL;
    params.WindowSize=dimension2d<u32>(_winSize.first, _winSize.second);
    _device = createDeviceEx(params);
    if (!_device)
	throw std::string("Can't create Irrlicht Device.");
    _driver = _device->getVideoDriver();
    _smgr = _device->getSceneManager();
    _env = _device->getGUIEnvironment();
    _fs = _device->getFileSystem();
    _cursor = _device->getCursorControl();
    
    _fps = -1;
    
    EventContext context;
    context.device = _device;
    context.engine = this;
    _eventReceiver = new MyEventReceiver(context);
    _device->setEventReceiver(_eventReceiver);
    
    _guiManager = nullptr;
    _mapViewer = nullptr;
}

AEngine::~AEngine()
{
    delete _eventQueue;
    delete _commandQueue;
    delete _networkThread;
    
    delete _guiManager;
    delete _mapViewer;
    delete _eventReceiver;
    _device->drop();
}

bool AEngine::init()
{
    _assets = Assets::getInstance();
    
    //ASSETS
    _driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);
    
    //WINDOW
    this->updateFPS();
    
    // FONT
    //    std::string font_path("bigfont.png");
    //    if (_fs->existFile(font_path.c_str()))
    //    {
    //	std::cout << "	Font loaded !" << std::endl;
    //	IGUISkin* skin = _env->getSkin();
    //	IGUIFont* font = _env->getFont(font_path.c_str());
    //	if (font)
    //	    skin->setFont(font);
    //	skin->setFont(_env->getBuiltInFont(), EGDF_TOOLTIP);
    //	//	skin->drop();
    //    }
    _mapViewer = new MapViewer(_env, _smgr, _cursor);
    _teamManager = new TeamManager(_mapViewer->getMapObject());
    _guiManager = new GUIManager(_env, this, _winSize);
    
    _mapViewer->init();//TODO : checker retour
    _guiManager->init();
    
    //    _mapViewer->createGround(20,30);//debug
    
    return true;
}
bool AEngine::update()
{
    //BRJ correct way to get heading posted by Vitek
    //    ICameraSceneNode const * camera = _mapViewer->getCameraManager().getCurrentCamera();
    //    if (camera)
    //    {
    //        core::vector3df fore(0, 0, 1);
    //	camera->getAbsoluteTransformation().rotateVect(fore);
    //	core::vector3df rot1 = fore.getHorizontalAngle();
    //	_guiManager->updateDirection(rot1.Y);
    //	//	pgCompass->SetCompassHeading( rot1.Y );
    //    }
    _mapViewer->update();
    _guiManager->update();
    this->updateFPS();
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _smgr->drawAll();
    _env->drawAll();
    _driver->endScene();
    return true;
}
bool AEngine::mainLoop()
{
    while (_device->run())
    {
	while (!_eventQueue->isEmpty())
	{
	    t_data * data = _eventQueue->pop();
	    this->handlerRelay(data);
	    delete data;
	}
	if (_device->isWindowActive())
            this->update();
	else
	    _device->yield();
    }
    return true;
}
void AEngine::updateFPS()
{
    int fps = _driver->getFPS();
    if (fps != _fps)
    {
	_fps = fps;
	core::stringw str = L"Zappy ! [";
	str += _driver->getName();
	str += "] FPS:";
	str += fps;
	_device->setWindowCaption(str.c_str());	
    }
}

/* GETTERS */

irr::IrrlichtDevice* AEngine::getDevice() const
{
    return _device;
}
const TeamManager* AEngine::getTeamManager() const
{
    return _teamManager;
}



/* EVENT HANDLERS */

bool AEngine::handlerRelay(t_data* data)
{
    t_infos * infos = data->infos;
    
    switch(data->game_element_type)
    {
	case ENGINE_CLASS:
	    if (!data->engine_handler_ptr)
		break;
	    return (this->*(data->engine_handler_ptr))(infos);
	case MAP_VIEWER_CLASS:
	    if (!data->mapviewer_handler_ptr)
		break;
	    return (_mapViewer->*(data->mapviewer_handler_ptr))(infos);
	case TEAM_MANAGER_CLASS:
	    if (!data->teammanager_handler_ptr)
		break;
	    return (_teamManager->*(data->teammanager_handler_ptr))(infos);
	default:
	    break;
    }
    return _mapViewer->handlerRelay(data);
}

void AEngine::sendCommand(t_data* data)
{
    _commandQueue->push(data);
}



/* SETTINGS */


bool AEngine::setCameraMode(Ids id)
{
    return _mapViewer->setCameraMode(id);
}
bool AEngine::setTheme(Ids id)
{
    std::cout << "Theme not implemented " << id << std::endl;
    return false;
}
bool AEngine::setTimeUnit(int value)
{
    std::cout << "TimeUnit not implemented " << value << std::endl;
    return false;
}
bool AEngine::setVolume(int value)
{
    std::cout << "Volume not implemented " << value << std::endl;
    return false;
}
bool AEngine::setMuteStatus(bool mute)
{
    std::cout << "Mute not implemented " << mute << std::endl;
    return false;
}
void AEngine::setLastNodeClicked(const scene::ISceneNode* node,
	core::vector3df point, core::triangle3df triangle)
{
    (void)triangle;
    MapObject const* mapObj = _mapViewer->getMapObject();
    if (mapObj)
    {
	if (node->getID() == NODE_ID_MAP)
	{
	    posi_t pos = _helper->worldToMapCoordinates(point);
	    _lastNodeClicked = mapObj->getCaseObjectFromPos(pos);
	    std::cout << "Case " << pos.first << " " << pos.second << " selected !" << std::endl;
	}
	else
	{
	    _lastNodeClicked = mapObj->getObjectFromNode(node);
	}
    }
}

Ids AEngine::getCameraMode() const
{
    return _mapViewer->getCameraMode();
}
Ids AEngine::getTheme() const
{
    std::cout << "Theme not implemented " << std::endl;
    return GUI_ID_UNDEFINED;
}
int AEngine::getTimeUnit() const
{
    std::cout << "TimeUnit not implemented " << std::endl;
    return -1;
}
int AEngine::getVolume() const
{
    std::cout << "Volume not implemented " << std::endl;
    return -1;
}
bool AEngine::getMuteStatus() const
{
    std::cout << "MuteStatus not implemented " << std::endl;
    return false;
}
const INodeObject* AEngine::getLastNodeClicked() const
{
    return _lastNodeClicked;
}

/* HANDLERS */


bool AEngine::errnoHandler(t_infos* infos)
{
    (void) infos;
    //TODO
    std::cout << "errno !" << std::endl;
    return true;
}

bool AEngine::disconnectedHandler(t_infos* infos)
{
    (void) infos;
    std::cout << "Successful disconnection !" << std::endl;
    return true;
}

bool AEngine::connectedHandler(t_infos* infos)
{
    (void) infos;
    std::cout << "Successful connection to server !" << std::endl;
    return true;
}

