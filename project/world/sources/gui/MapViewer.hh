/* 
 * File:   MapViewer.hh
 * Author: marie
 *
 * Created on June 30, 2014, 6:03 PM
 */

#ifndef MAPVIEWER_HH
#define	MAPVIEWER_HH

#include <irrlicht.h>
#include "AAnimatedMeshObject.hh"
#include "CameraManager.hh"
#include "MapObject.hh"

using namespace irr;

class MapViewer : public gui::IGUIMeshViewer
{
public:
    MapViewer(gui::IGUIEnvironment* env, scene::ISceneManager* smgr);
    MapViewer(const MapViewer& orig);
    virtual ~MapViewer();
    
    scene::ISceneManager* getSceneManager() const { return _smgr; }
    
    virtual void setMaterial (const video::SMaterial &material);
    virtual void setMesh (scene::IAnimatedMesh *mesh);    
    
    virtual const video::SMaterial & getMaterial () const { return _material; }
    virtual scene::IAnimatedMesh * getMesh () const { return _mapObject->getAnimatedMeshNode()->getMesh(); }

    bool    createGround(int x, int y);
//    bool    callHandlerCreateMap(int x, int y);
    
private:
    scene::ISceneManager*	_smgr;
    video::SMaterial		_material;
//    AAnimatedMeshObject*	_mapObject;
    MapObject*	_mapObject;
    CameraManager		_cameraManager;
};

#endif	/* MAPVIEWER_HH */

