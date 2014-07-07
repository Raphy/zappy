/* 
 * File:   MapViewer.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 6:03 PM
 */

#include "MapViewer.hh"
#include "enums.hh"
#include "Binder.hh"

using namespace core;

//TODO : taille dynamique
MapViewer::MapViewer(gui::IGUIEnvironment* env, scene::ISceneManager* smgr)
: IGUIMeshViewer(env, nullptr, GUI_ID_MAP,
	rect<s32>(vector2di(42, 42), vector2di(42, 42))),
	_smgr(smgr), _cameraManager(smgr)
{
    //    _mapObject = static_cast<AAnimatedMeshObject*>((Binder::getInstance())->createMapObject(_smgr, nullptr));
    _mapObject = new MapObject(_smgr, nullptr);
    _mapObject->init();// TODO : appeler le init autre part ?
    _cameraManager.init(20,20);//??
}

MapViewer::MapViewer(const MapViewer& orig)
: IGUIMeshViewer(orig.Environment, 0, GUI_ID_MAP, orig.AbsoluteRect), _cameraManager(orig.getSceneManager())
{
}

MapViewer::~MapViewer()
{
    //    delete _mapObject;
}

void MapViewer::setMaterial(const video::SMaterial &material)
{ 
    _material = material;
}
void MapViewer::setMesh(scene::IAnimatedMesh *mesh)
{
    _mapObject->getAnimatedMeshNode()->setMesh(static_cast<scene::SAnimatedMesh *>(mesh));
}

bool MapViewer::createGround(int x, int y)
{
    if (!_cameraManager.init(x,y)
	    || !_mapObject->createGround(x,y))
	return false;
    return _cameraManager.addCollision(_mapObject->getSelector());
}
