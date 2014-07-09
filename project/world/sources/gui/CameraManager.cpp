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
: ANodeObject(smgr, nullptr), _driver(smgr->getVideoDriver())
//: _smgr(smgr), _driver(_smgr->getVideoDriver()), _ressources(Assets::getInstance())
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
    // create skybox and skydome
    _driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
    /*scene::ISceneNode* skybox = */_smgr->addSkyBoxSceneNode(
            _assets->getTexture(SKYBOX, TEXTURE, 0),
            _assets->getTexture(SKYBOX, TEXTURE, 1),
            _assets->getTexture(SKYBOX, TEXTURE, 2),
            _assets->getTexture(SKYBOX, TEXTURE, 3),
            _assets->getTexture(SKYBOX, TEXTURE, 4),
            _assets->getTexture(SKYBOX, TEXTURE, 5));
    //        scene::ISceneNode* skydome = _smgr->addSkyDomeSceneNode(_ressources->getTexture(SKYBOX, TEXTURE, 6),16,8,0.95f,2.0f);
    _driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
        
    //init all cameras
    _camera[FPS] = _smgr->addCameraSceneNodeFPS();
    _light[FPS] = _smgr->addLightSceneNode(_camera[FPS], vector3df(0, 30, 0), SColor(255, 255, 255, 0), 1000);
    ISceneNodeAnimatorCameraFPS * anim = static_cast<ISceneNodeAnimatorCameraFPS *>(*(_camera[FPS]->getAnimators().begin()));
    anim->setMoveSpeed(0.01);
    
    _camera[STATIC] = _smgr->addCameraSceneNode();
    _light[STATIC] = _smgr->addLightSceneNode(_camera[STATIC], vector3df(0, 30, 0), SColor(255, 255, 255, 0), 1000);
    
    for (int i = 0; i < CAMERA_MODE_COUNT; i++)
    {
	_camera[i]->setPosition(vector3df(x/2.0, (x+y)/2.0, y/2.0));
	_camera[i]->setTarget(vector3df(x/2.0, 0, y/2.0));
	_camera[i]->setFarValue(4000.0f);
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
    if (id == GUI_ID_MENU_CAMERA_CLASSIC_BUTTON)
	_currentMode = STATIC;
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
	anim->drop();
    }
    return true;
}
