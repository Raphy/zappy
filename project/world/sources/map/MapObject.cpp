/* 
 * File:   MapObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:34 PM
 */

#include <algorithm>
#include "MapObject.hh"
#include "Ressources.hh"
//bool loadTheNode(IrrlichtDevice* device, IVideoDriver* driver, ISceneManager* smgr)
//{
//    IAnimatedMesh* mesh = smgr->getMesh("../media/sydney.md2");
//    if (!mesh)
//    {
//	//device->drop();
//	return false;
//    }
//    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );
//    
//    if (node)
//    {
//	node->setMaterialFlag(EMF_LIGHTING, true);
//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
//	node->setMD2Animation(EMAT_STAND);
//	node->setMaterialTexture( 0, driver->getTexture("../media/sydney.bmp") );
//    } 
//    return true;
//}

MapObject::MapObject(scene::ISceneManager* smgr, IObject* parent)
: AAnimatedMeshObject(smgr, parent)
{
    _persos.push_back(_binder->createPersoObject(smgr, this));
}

MapObject::MapObject(const MapObject& orig)
: AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
{
}

MapObject::~MapObject()
{
}

bool    MapObject::init()
{
    std::string const& heightmap = _ressources->getFileName(MAP, HEIGHT_MAP, 0);

    std::for_each(_persos.begin(), _persos.end(), [](IObject* perso){
	perso->init();
    });
    
//    std::string const& texture = _ressources->getMapTextureFile();
    _node = _smgr->addTerrainSceneNode(heightmap.c_str(), getParentNode(), NODE_ID_MAP,
	    core::vector3df(0.f, 0.f, 0.f),		// position
		core::vector3df(0.f, 0.f, 0.f),		// rotation
		core::vector3df(40.f, 4.4f, 40.f),	// scale
		video::SColor ( 255, 255, 255, 255 ),	// vertexColor
		5,					// maxLOD
		scene::ETPS_17,				// patchSize
		4					// smoothFactor
	    );
//    _node->setScale(core::vector3df(20.0f, 2.0f, 20.0f));
////    _node->setMaterialTexture(video::MATERIAL_MAX_TEXTURES - 1, _ressources->getMapTexture());
//	_node->setMaterialFlag(video::EMF_LIGHTING, false);
//	_node->setMaterialTexture(0, _ressources->getMapTexture());
//	_node->setMaterialTexture(1, _ressources->getMapTexture());
//	_node->setMaterialType(video::EMT_DETAIL_MAP);
//	(static_cast<scene::ITerrainSceneNode*>(_node))->scaleTexture(1.0f, 20.0f);
//
////	scene::ITerrainSceneNode* terrain = smgr->addTerrainSceneNode(
////		"../media/terrain-heightmap.bmp",
////		0,					// parent node
////		-1,					// node id
////		core::vector3df(0.f, 0.f, 0.f),		// position
////		core::vector3df(0.f, 0.f, 0.f),		// rotation
////		core::vector3df(40.f, 4.4f, 40.f),	// scale
////		video::SColor ( 255, 255, 255, 255 ),	// vertexColor
////		5,					// maxLOD
////		scene::ETPS_17,				// patchSize
////		4					// smoothFactor
////		);
//
//
//	//	terrain->setMaterialTexture(0, _driver->getTexture("../media/terrain-texture.jpg"));
////	terrain->setMaterialTexture(1, _driver->getTexture("../media/detailmap3.jpg"));
	

	return true;
}

