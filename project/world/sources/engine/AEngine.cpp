/* 
 * File:   AEngine.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 12:54 PM
 */

#include <string>
#include "AEngine.hh"
#include "Ressources.hh"
#include "Binder.hh"

AEngine::AEngine()
{
    irr::SIrrlichtCreationParameters params;
    params.DriverType=video::EDT_OPENGL;
    params.WindowSize=core::dimension2d<u32>(640, 480);
    _device = createDeviceEx(params);
    //    _device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640, 480),
    //	    16, false, false, false, 0);
    if (!_device)
	throw std::string("Can't create Irrlicht Device.");
    _driver = _device->getVideoDriver();
    _smgr = _device->getSceneManager();
    _env = _device->getGUIEnvironment();
    _fs = _device->getFileSystem();
}

AEngine::~AEngine()
{
    _device->drop();
}

bool AEngine::init()
{
    Ressources* ressources = Ressources::getInstance(_smgr, "./world/assets/irrlicht");
    (Binder::getInstance())->createMapViewer(_env, _smgr);
    _driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);
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
	if (_device->isWindowActive())
	    this->update();
	else
	    _device->yield();
    }
    return true;
}