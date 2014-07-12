/* 
 * File:   MapViewer.hh
 * Author: marie
 *
 * Created on June 30, 2014, 6:03 PM
 */

#ifndef MAPVIEWER_HH
#define	MAPVIEWER_HH

#include <irrlicht.h>
#include "IObject.h"
#include "CameraManager.hh"
#include "MapObject.hh"

using namespace irr;

class MapViewer : public gui::IGUIMeshViewer, public IObject, public INetworkEventHandler
{
public:
    MapViewer(gui::IGUIEnvironment* env, scene::ISceneManager* smgr, gui::ICursorControl* cursor);
//    MapViewer(const MapViewer& orig);
    virtual ~MapViewer();

    bool    init();
    bool    update();
    
    scene::ISceneManager* getSceneManager() const { return _smgr; }
    
    virtual void setMaterial (const video::SMaterial &material);
    virtual void setMesh (scene::IAnimatedMesh *mesh);    
    
    virtual const video::SMaterial & getMaterial () const { return _material; }
    virtual scene::IAnimatedMesh * getMesh () const { return _mapObject->getAnimatedMeshNode()->getMesh(); }

    bool    handlerRelay(t_data * data);
    
    bool    createGround(int x, int y);
//    bool    handlerRelayCreateMap(int x, int y);
    
    bool    setCameraMode(Ids id);
    Ids	    getCameraMode();
    CameraManager const& getCameraManager() const { return _cameraManager; }

    bool    mapSizeHandler(t_infos * infos);
    
private:
    scene::ISceneManager*	_smgr;
    gui::ICursorControl*	_cursor;
    video::SMaterial		_material;
//    AAnimatedMeshObject*	_mapObject;
    MapObject*	_mapObject;
    CameraManager		_cameraManager;
};

#endif	/* MAPVIEWER_HH */

