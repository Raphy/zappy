/* 
 * File:   MapViewer.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 6:03 PM
 */

#include "MapViewer.hh"
#include "ids.hh"
#include "Binder.hh"

using namespace core;

//TODO : taille dynamique
MapViewer::MapViewer(gui::IGUIEnvironment* env, scene::ISceneManager* smgr)
: IGUIMeshViewer(env, nullptr, GUI_ID_MAP_VIEWER,
	rect<s32>(vector2di(42, 42), vector2di(42, 42))),
_smgr(smgr)
{
    _mapObject = static_cast<AAnimatedMeshObject*>((Binder::getInstance())->createMapObject(_smgr, nullptr));
    _mapObject->init();
    //la map est l'object racine donc son parent est null
//    smgr->addCameraSceneNode(0, vector3df(0,30,-400), vector3df(0,5,0));// TODO : deplacer dans CameraManager
    auto camera = smgr->addCameraSceneNodeFPS();

    	camera->setPosition(core::vector3df(2700*2,255*2,2600*2));
	camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
	camera->setFarValue(42000.0f);

	//    smgr->addLightSceneNode();
        scene::ILightSceneNode* light1 =
	    smgr->addLightSceneNode(0, core::vector3df(0,0,0),
	    video::SColorf(0.5f, 1.0f, 0.5f, 0.0f), 1200.0f);
}

MapViewer::MapViewer(const MapViewer& orig)
: IGUIMeshViewer(orig.Environment, 0, GUI_ID_MAP_VIEWER, orig.AbsoluteRect)
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
