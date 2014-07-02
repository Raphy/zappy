/* 
 * File:   PersoObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include "PersoObject.hh"

PersoObject::PersoObject(scene::ISceneManager* smgr, IObject* parent)
: AAnimatedMeshObject(smgr, parent)
{
}

PersoObject::PersoObject(PersoObject const& orig)
: AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
{
}

PersoObject::~PersoObject()
{
}

bool    PersoObject::init()
{
//    std::string const& heightmap = _ressources->getMapHeightFile();
//    _smgr->addTerrainSceneNode(heightmap.c_str(), getParentNode(), NODE_ID_MAP);

    _smgr->getSceneNodeFactory(0)->addSceneNode(scene::ESNT_SPHERE, getParentNode());
    
    return true;
}
