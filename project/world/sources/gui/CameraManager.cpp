/* 
 * File:   CameraManager.cpp
 * Author: marie
 * 
 * Created on July 6, 2014, 11:16 PM
 */

#include "CameraManager.hh"

using namespace irr;
using namespace core;
using namespace video;

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
    _camera[FPS]->setPosition(core::vector3df(0, 30, -200));
    _camera[FPS]->setTarget(core::vector3df(0, 5, 0));
    _camera[FPS]->setFarValue(42000.0f);
    _light[FPS] = _smgr->addLightSceneNode(_camera[FPS], vector3df(0, 30, 0), SColor(255, 255, 255, 0), 1000);

    _camera[STATIC] = _smgr->addCameraSceneNode(0, vector3df(0, 30, -200), vector3df(0, 5, 0));
    _light[STATIC] = _smgr->addLightSceneNode(_camera[STATIC], vector3df(0, 30, 0), SColor(255, 255, 255, 0), 1000);

    for (int i = 0; i < CAMERA_MODE_COUNT; i++)
    {
	_camera[i]->setVisible(false);
	_light[i]->setVisible(false);
    }
    _currentMode = FPS;

    return setCameraMode(GUI_ID_MENU_CAMERA_CLASSIC_BUTTON);
}

bool CameraManager::setCameraMode(Ids id)
{
    _camera[_currentMode]->setVisible(false);
    _light[_currentMode]->setVisible(false);
    //retrouver mode dans _guiIds
    _currentMode = FPS;
    _node = _camera[_currentMode];
    _camera[_currentMode]->setVisible(true);
    _light[_currentMode]->setVisible(true);
    return true;
}

Ids CameraManager::getCameraMode()
{
    return _guiIds[_currentMode];
}
