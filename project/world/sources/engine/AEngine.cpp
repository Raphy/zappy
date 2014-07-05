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

using namespace core;
using namespace gui;

AEngine::AEngine()
{
    _eventQueue = _binder->createNetworkEventQueue();
    _commandQueue = _binder->createNetworkEventQueue();
    _networkThread = _binder->createNetworkThread(_eventQueue, _commandQueue);
    _networkThread->start();

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
    _binder = (Binder::getInstance());
}

AEngine::~AEngine()
{
    delete _eventQueue;
    delete _commandQueue;
    delete _networkThread;
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

    _mapViewer = _binder->createMapViewer(_env, _smgr);//TODO : deplacer dans WorldEngine
    /*_mapToolbar = */_binder->createMenuToolbar(_env, _smgr);//TODO : deplacer dans WorldEngine
		      
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
//	if (!_eventQueue->isEmpty())
//	    this->callHandler(_eventQueue->pop());
	if (_device->isWindowActive())
	    this->update();
	else
	    _device->yield();
    }
    return true;
}

//typedef bool (AEngine::*engine_handler_t)(t_infos *);
typedef bool (/*AEngine::*/*engine_handler_t)(/*t_infos **/);

bool AEngine::callHandler(t_data* data)
{
    if (data->game_element_type == ENGINE_CLASS
	    || data->game_element_type == MAP_CLASS)
    {
	engine_handler_t ptr = reinterpret_cast<engine_handler_t>(data->realptr);
	(void)ptr;
	//(this->*ptr)(/*data->infos*/);// ex : setLevel(t_infos *infos)
    }
//    else
//	_mapViewer->callHandler(data);
    //TODO : recuperer le mapObject au lieu du mapViewer
    return false;
}




/* SETTINGS */


bool AEngine::setCameraMode(Ids id)
{
    std::cout << "CameraMode not implemented " << id << std::endl;
    return false;
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
    std::cout << "CameraMode not implemented " << std::endl;
    return GUI_ID_UNDEFINED;
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




