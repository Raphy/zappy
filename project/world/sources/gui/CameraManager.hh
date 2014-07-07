/* 
 * File:   CameraManager.hh
 * Author: marie
 *
 * Created on July 6, 2014, 11:16 PM
 */

#ifndef CAMERAMANAGER_HH
#define	CAMERAMANAGER_HH

#include    <irrlicht.h>
#include    "AObject.hh"
#include    "Ressources.hh"

using namespace irr;

enum CameraMode
{
    STATIC = 0,
    //		CLASSIC,
    FPS,
    //		TPS,
    CAMERA_MODE_COUNT
};

class CameraManager// : AObject
{
public:
    CameraManager(scene::ISceneManager* smgr);
    virtual ~CameraManager();
    
    bool    init(int x, int y);
    bool    setCameraMode(Ids id);
    Ids	    getCameraMode();

    bool    addCollision(scene::ITriangleSelector* selector);

private:	    
    scene::ISceneManager*	    _smgr;
    video::IVideoDriver*	    _driver;
    Ressources*			    _ressources;

    scene::ISceneNode*	    _node;

    Ids				    _guiIds[CAMERA_MODE_COUNT];
    CameraMode			    _currentMode;
    scene::ICameraSceneNode*   _camera[CAMERA_MODE_COUNT];
    scene::ILightSceneNode*    _light[CAMERA_MODE_COUNT];
};

#endif	/* CAMERAMANAGER_HH */

