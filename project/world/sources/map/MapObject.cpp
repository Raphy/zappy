/* 
 * File:   MapObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:34 PM
 */

#include <algorithm>
#include <iostream>
#include "MapObject.hh"
#include "Ressources.hh"

using namespace video;
using namespace scene;
using namespace core;

MapObject::MapObject(scene::ISceneManager* smgr, IObject* parent)
: AAnimatedMeshObject(smgr, parent), _selector(nullptr)
{
    _persos.push_back(_binder->createPersoObject(smgr, this));
}

MapObject::MapObject(const MapObject& orig)
: AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig)), _selector(nullptr)
{
}

MapObject::~MapObject()
{
    if (_selector)
	_selector->drop();
}

bool    MapObject::init()
{
    //    createGround(20,20);//test
    
    std::for_each(_persos.begin(), _persos.end(), [](IObject* perso){
	perso->init();
    });
    return true;
}

bool MapObject::createGround(int x, int y)
{
    //    std::string const& heightmap = _ressources->getFileName(MAP, HEIGHT_MAP, 0);
    //    std::string const& heightmap = "ground/normal.tga";
    std::string const& heightmap = "heightmap.bmp";
    ITerrainSceneNode* node = _smgr->addTerrainSceneNode(heightmap.c_str(), getParentNode(), NODE_ID_MAP,
	    core::vector3df(x/2.0, 0, y/2.0),		// position
	    core::vector3df(0.f, 0.f, 0.f),		// rotation
	    core::vector3df(1.f, 1.f, 1.f),	// scale
	    //core::vector3df(x, 1.f, y),	// scale
	    video::SColor ( 255, 255, 255, 0 ),	// vertexColor
	    5,					// maxLOD
	    scene::ETPS_17,				// patchSize
	    4					// smoothFactor
	    );
    _node = node;
    if (!_node)
	return false;
    
    vector3df extent = node->getTransformedBoundingBox().getExtent();
    std::cout << extent.X << std::endl;
    std::cout << extent.Y << std::endl;
    std::cout << extent.Z << std::endl;
    node->setScale(vector3df(1.0 / (float)extent.X, 1.0, 1.0 / (float)extent.Z));
    node->setScale(vector3df(x, 1.f, y));

    _node->setMaterialFlag(EMF_LIGHTING, true);
    ////    _node->setMaterialFlag(EMF_FOG_ENABLE, true);
    ////    _node->setMaterialType(video::EMT_DETAIL_MAP);
    _node->setMaterialTexture(0, _ressources->getTexture(MAP, TEXTURE, 0));
    _node->setMaterialTexture(1, _ressources->getTexture(MAP, TEXTURE, 1));        
    _node->getMaterial(0).getTextureMatrix(0).setTextureScale(x,y);
    
    //ajouter mur invisible
    
    _selector = _smgr->createTerrainTriangleSelector(node);
    if (!_selector)
	return false;
    node->setTriangleSelector(_selector);
    return true;
}




bool MapObject::callHandler(t_data * data)
{
    (void)data;
    //    if (data->game_element_type == PERSO_CLASS
    //	    || data->game_element_type == RESSOURCE_CLASS
    //	    || data->game_element_type == EGG_CLASS)
    //	this->(*(data->realptr))(/*??*/);// ex : setLevel
    //    else
    //	_perso->callHandler(data);
    //TODO : recuperer le mapObject au lieu du mapViewer
    return false;
}
