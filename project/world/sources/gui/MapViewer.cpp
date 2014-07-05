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
: IGUIMeshViewer(env, nullptr, GUI_ID_MAP,
	rect<s32>(vector2di(42, 42), vector2di(42, 42))),
_smgr(smgr)
{
    _mapObject = static_cast<AAnimatedMeshObject*>((Binder::getInstance())->createMapObject(_smgr, nullptr));
    _mapObject->init();// TODO : appeler le init autre part ?

    /*
     To look at the mesh, we place a camera into 3d space at the position
     (0, 30, -40). The camera looks from there to (0,5,0), which is
     approximately the place where our md2 model is.
     */
    smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
    //    smgr->addLightSceneNode(smgr->getRootSceneNode(), vector3df(0,30,0), SColor(0,255,0,0), 1000);


//    //la map est l'object racine donc son parent est null
////    smgr->addCameraSceneNode(0, vector3df(0,30,-400), vector3df(0,5,0));// TODO : deplacer dans CameraManager
//    auto camera = smgr->addCameraSceneNodeFPS();
//
////    	camera->setPosition(core::vector3df(2700*2,255*2,2600*2));
//    	camera->setPosition(core::vector3df(0,1000,0));
//	camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
//	camera->setFarValue(42000.0f);
//
//	//    smgr->addLightSceneNode();
//        /*scene::ILightSceneNode* light1 =*/
////	    smgr->addLightSceneNode(0, core::vector3df(0,1000,0),
////	    video::SColorf(0.5f, 1.0f, 0.5f, 0.0f), 1200.0f);
//	    smgr->addLightSceneNode(0, core::vector3df(0,1000,0),
//	    video::SColorf(1.0f, 1.0f, 1.0f, 0.0f), 1200.0f);
}

MapViewer::MapViewer(const MapViewer& orig)
: IGUIMeshViewer(orig.Environment, 0, GUI_ID_MAP, orig.AbsoluteRect)
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
