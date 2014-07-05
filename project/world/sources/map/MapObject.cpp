/* 
 * File:   MapObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:34 PM
 */

#include <algorithm>
#include "MapObject.hh"
#include "Ressources.hh"

using namespace video;

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
//    std::string const& heightmap = _ressources->getFileName(MAP, HEIGHT_MAP, 0);
//    _node = _smgr->addTerrainSceneNode(heightmap.c_str(), getParentNode(), NODE_ID_MAP,
//	    core::vector3df(0.f, 0.f, 0.f),		// position
//	    core::vector3df(0.f, 0.f, 0.f),		// rotation
//	    core::vector3df(40.f, 4.4f, 40.f),	// scale
//	    video::SColor ( 255, 255, 255, 255 ),	// vertexColor
//	    5,					// maxLOD
//	    scene::ETPS_17,				// patchSize
//	    4					// smoothFactor
//	    );    
//    _node->setMaterialFlag(EMF_LIGHTING, true);
////    _node->setMaterialFlag(EMF_FOG_ENABLE, true);
////    _node->setMaterialType(video::EMT_DETAIL_MAP);
//    _node->setMaterialTexture(0, _ressources->getTexture(MAP, TEXTURE, 0));
//    _node->setMaterialTexture(1, _ressources->getTexture(MAP, TEXTURE, 1));    
    
    std::for_each(_persos.begin(), _persos.end(), [](IObject* perso){
	perso->init();
    });
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
