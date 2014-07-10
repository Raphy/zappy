/* 
 * File:   CameraManager.hh
 * Author: marie
 *
 * Created on July 6, 2014, 11:16 PM
 */

#ifndef CAMERAMANAGER_HH
#define	CAMERAMANAGER_HH

#include    <irrlicht.h>
#include    "ANodeObject.hh"

using namespace irr;

enum CameraMode
{
    STATIC = 0,
    //		CLASSIC,
    FPS,
    //		TPS,
    CAMERA_MODE_COUNT
};

class CameraManager : ANodeObject
{
public:
    CameraManager(scene::ISceneManager* smgr, gui::ICursorControl* cursor);
    virtual ~CameraManager();
    
    bool    init(int x = 10, int y = 10);
    bool    setCameraMode(Ids id);
    Ids	    getCameraMode();

    scene::ICameraSceneNode const *	    getCurrentCamera() const { return _camera[_currentMode]; }

    bool    addCollision(scene::ITriangleSelector* selector);

private:	    
//    scene::ISceneManager*	    _smgr;
    video::IVideoDriver*	    _driver;
    gui::ICursorControl*	    _cursor;
//    Assets*			    _ressources;

    Ids				    _guiIds[CAMERA_MODE_COUNT];
    CameraMode			    _currentMode;
    scene::ICameraSceneNode*   _camera[CAMERA_MODE_COUNT];
    scene::ILightSceneNode*    _light[CAMERA_MODE_COUNT];
};

#endif	/* CAMERAMANAGER_HH */

