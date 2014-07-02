/* 
 * File:   PersoObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include <iostream>
#include "PersoObject.hh"

using namespace video;

PersoObject::PersoObject(scene::ISceneManager* smgr, IObject* parent)
: AAnimatedMeshObject(smgr, parent)
{
}

PersoObject::PersoObject(PersoObject const& orig)
: AGameElement(static_cast<AGameElement const&>(orig)),
    AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
{
}

PersoObject::~PersoObject()
{
}

bool    PersoObject::init()
{
////    _smgr->getSceneNodeFactory(0)->addSceneNode(scene::ESNT_SPHERE, getParentNode());
//    _node = _smgr->addMeshSceneNode(_ressources->getMesh(PERSO, MESH));
//
//    std::cout << "perso init..." << std::endl;
//
//    if (_node)
//    {
//        _node->setScale(core::vector3df(20,20,20));
//	_node->setMaterialFlag(EMF_LIGHTING, true);
//	_node->setMaterialFlag(EMF_FOG_ENABLE, true);
////	_node->setMD2Animation(scene::EMAT_STAND);
//	_node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE));
//    } 
 
    return true;
}
