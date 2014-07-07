/* 
 * File:   CameraManager.cpp
 * Author: marie
 * 
 * Created on July 6, 2014, 11:16 PM
 */

#include <iostream>
#include "CameraManager.hh"

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;

CameraManager::CameraManager(scene::ISceneManager* smgr)
: _smgr(smgr)
{
    _guiIds[STATIC] = GUI_ID_MENU_CAMERA_CLASSIC_BUTTON;
    //	    _guiIds[CLASSIC] = GUI_ID_MENU_CAMERA_CLASSIC_BUTTON;
    _guiIds[FPS] = GUI_ID_MENU_CAMERA_FPS_BUTTON;
    //	    _guiIds[TPS] = GUI_ID_MENU_CAMERA_TPS_BUTTON;
}
CameraManager::~CameraManager()
{
}

bool CameraManager::init(int x, int y)
{
    _camera[FPS] = _smgr->addCameraSceneNodeFPS();
    _camera[FPS]->setPosition(vector3df(x/2.0, (x+y)/2.0, y/2.0));
    _camera[FPS]->setPosition(vector3df(10, 50, 10));
    //    _camera[FPS]->setPosition(vector3df(x/2.0, 10, y/2.0));
    _camera[FPS]->setTarget(vector3df(x/2.0, 0, y/2.0));
    _camera[FPS]->setFarValue(4000.0f);
    _light[FPS] = _smgr->addLightSceneNode(_camera[FPS], vector3df(0, 30, 0), SColor(255, 255, 255, 0), 1000);
    
    auto animators = _camera[FPS]->getAnimators();
    ISceneNodeAnimatorCameraFPS * anim = static_cast<ISceneNodeAnimatorCameraFPS *>(*(animators.begin()));
    std::cout << "move speed : " << anim->getMoveSpeed() << std::endl;
    anim->setMoveSpeed(0.01);
    
    _camera[STATIC] = _smgr->addCameraSceneNode();
    _camera[STATIC]->setPosition(vector3df(x/2.0, (x+y)/2.0, y/2.0));
    _camera[STATIC]->setTarget(vector3df(x/2.0, 0, y/2.0));
    _camera[STATIC]->setFarValue(4000.0f);
    _light[STATIC] = _smgr->addLightSceneNode(_camera[STATIC], vector3df(0, 30, 0), SColor(255, 255, 255, 0), 1000);
    
    for (int i = 0; i < CAMERA_MODE_COUNT; i++)
    {
	_camera[i]->setVisible(false);
	_light[i]->setVisible(false);
    }
    _currentMode = FPS;
    
    return setCameraMode(GUI_ID_MENU_CAMERA_FPS_BUTTON);
}

bool CameraManager::setCameraMode(Ids id)
{
    //desactive actual camera
    _camera[_currentMode]->setVisible(false);
    _camera[_currentMode]->setInputReceiverEnabled(false);
    _light[_currentMode]->setVisible(false);
    
    //change current mode
    _currentMode = FPS;//TODO : retrouver mode dans _guiIds
    _node = _camera[_currentMode];
    
    //active new camera
    _camera[_currentMode]->setVisible(true);
    _camera[_currentMode]->setInputReceiverEnabled(true);
    _light[_currentMode]->setVisible(true);
    _smgr->setActiveCamera(_camera[_currentMode]);
    return true;
}

Ids CameraManager::getCameraMode()
{
    return _guiIds[_currentMode];
}

bool CameraManager::addCollision(scene::ITriangleSelector* selector)
{
    for (int i = 0; i < CAMERA_MODE_COUNT; i++)
    {
	scene::ISceneNodeAnimator* anim = _smgr->createCollisionResponseAnimator(
		selector, _camera[i], core::vector3df(30,5,30),
		core::vector3df(0,0,0), core::vector3df(0,0,0));
	_camera[i]->addAnimator(anim);
	anim->drop();  // And likewise, drop the animator when we're done referring to it.
    }
    return true;
}
