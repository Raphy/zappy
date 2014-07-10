/* 
 * File:   MapViewer.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 6:03 PM
 */

#include <iostream>
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
    _smgr->addBillboardTextSceneNode(nullptr, L"(0,0)", nullptr, dimension2df(1.f,1.f), vector3df(0.f,3.f,0.f));
    _smgr->addBillboardTextSceneNode(nullptr, L"(10,20)", nullptr, dimension2df(1.f,1.f), vector3df(10.f,3.f,20.f));
    _smgr->addBillboardTextSceneNode(nullptr, L"(0,20)", nullptr, dimension2df(1.f,1.f), vector3df(0.f,3.f,20.f));
    _smgr->addBillboardTextSceneNode(nullptr, L"(10,0)", nullptr, dimension2df(1.f,1.f), vector3df(10.f,3.f,0.f));
    
    _mapObject = new MapObject(_smgr, nullptr);
    _mapObject->init();// TODO : appeler le init autre part ?
    _cameraManager.init(10,20);//??
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

bool MapViewer::callHandler(t_data* data)
{
    std::cout << "MAP VIEWER EVENT RECEIVED ..." << std::endl;
    if (data->game_element_type == MAP_CLASS)
    {
	t_infos * infos = data->infos;
	switch (data->event_type)
	{
	    case PERSO_CONNECTION_EVENT:
		return _mapObject->addPerso(infos->pos, infos->player_id, infos->orientation,
			infos->level, infos->team_name);
	    case CASE_CONTENT_EVENT:
		return _mapObject->setCaseContent(infos->pos, infos->quantity);
	    default:
		break;
	}
    }
    return _mapObject->callHandler(data);
}



bool MapViewer::createGround(int x, int y)
{
    if (!_cameraManager.init(x,y)
	    || !_mapObject->createGround(x,y))
	return false;
    return _cameraManager.addCollision(_mapObject->getSelector());
}

bool MapViewer::setCameraMode(Ids id)
{
    return _cameraManager.setCameraMode(id);
}
Ids MapViewer::getCameraMode()
{
    return _cameraManager.getCameraMode();
}
