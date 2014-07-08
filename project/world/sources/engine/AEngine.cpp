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
#include "Ressources.hh"
#include "Binder.hh"
#include "GUIManager.hh"

using namespace core;
using namespace gui;

AEngine::AEngine()
{
    _binder = (Binder::getInstance());
    
//    _eventQueue = _binder->createNetworkEventQueue();
//    _commandQueue = _binder->createNetworkEventQueue();
//    _networkThread = _binder->createNetworkThread(_eventQueue, _commandQueue);
//    _networkThread->start();

//    GUIManager _guiclass(device, driver, env);

     video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    if (driverType==video::EDT_COUNT)
    {
	std::cout << "WARNING : invalid driver type, Software choose by default." << std::endl;
        driverType = video::EDT_SOFTWARE;
    }
    
    //        irr::SIrrlichtCreationParameters params;
    //    params.DriverType=video::EDT_OPENGL;
    //    params.WindowSize=dimension2d<u32>(640, 480);
    //    _device = createDeviceEx(params);
    _device = createDevice(driverType, dimension2d<u32>(800, 600),
    	    16, false, false, false, 0);
    if (!_device)
	throw std::string("Can't create Irrlicht Device.");
    _driver = _device->getVideoDriver();
    _smgr = _device->getSceneManager();
    _env = _device->getGUIEnvironment();
    _fs = _device->getFileSystem();

    EventContext context;
    context.device = _device;
    context.engine = this;
    _eventReceiver = _binder->createEventReceiver(context);
    _device->setEventReceiver(_eventReceiver);
}

AEngine::~AEngine()
{
//    delete _eventQueue;
//    delete _commandQueue;
//    delete _networkThread;
    _device->drop();
}

bool AEngine::init()
{
    Ressources::getInstance(_smgr, "./world/assets/irrlicht");
    
    //ASSETS
    _driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);
    
    //WINDOW
    _device->setWindowCaption(L"Zappy !!!");
    //_device->setResizable(true);
    
    // FONT
    //    IGUISkin* skin = _env->getSkin();
    //    IGUIFont* font = _env->getFont("../../media/fonthaettenschweiler.bmp");
    //    if (font)
    //	skin->setFont(font);
    //    skin->setFont(_env->getBuiltInFont(), EGDF_TOOLTIP);
    
    //    _mapViewer = _binder->createMapViewer(_env, _smgr);//TODO : deplacer dans WorldEngine
    _guiManager = new GUIManager(_env, 800, 600);
    _mapViewer = new MapViewer(_env, _smgr);//TODO : deplacer dans WorldEngine
    //    /*_mapToolbar = */_binder->createMenuToolbar(_env, _smgr);//TODO : deplacer dans WorldEngine
    
    return true;
}
bool AEngine::update()
{
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
//	while (!_eventQueue->isEmpty())
//	    this->callHandler(_eventQueue->pop());
	if (_device->isWindowActive())
	    this->update();
	else
	    _device->yield();
    }
    return true;
}

irr::IrrlichtDevice* AEngine::getDevice() const
{
    return _device;
}



/* EVENT HANDLERS */

bool AEngine::callHandler(t_data* data)
{
    std::cout << "EVENT RECEIVED ..." << std::endl;
    if (data->game_element_type == ENGINE_CLASS
	    || data->game_element_type == MAP_CLASS)
    {
	switch (data->event_type)
	{
	    case MAP_SIZE_EVENT:
		_mapViewer->createGround(data->infos->x, data->infos->y);
		break;
	    case CONNECTED_EVENT:
		std::cout << "Connected event not implemented..." << std::endl;
    		_mapViewer->createGround(30,20);//debug
		break;
	    default:
		std::cout << "UNKNOWN SERVER EVENT !" << std::endl;
		break;
	}
    }
    //    else
    //	_mapViewer->callHandler(data);
    //TODO : recuperer le mapObject au lieu du mapViewer
    return false;
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




