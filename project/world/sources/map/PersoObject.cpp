/* 
 * File:   PersoObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include <iostream>
#include "PersoObject.hh"

using namespace video;
using namespace scene;
using namespace core;

PersoObject::PersoObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AAnimatedMeshObject(smgr, parent, pos)
{
}

//PersoObject::PersoObject(PersoObject const& orig)
//: AGameElement(static_cast<AGameElement const&>(orig)),
//    AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
//{
//}

PersoObject::~PersoObject()
{
}

bool    PersoObject::init()
{
//    IMesh* mesh = _assets->getMesh(PERSO, MESH, 0);
//    if (!mesh)
//	return false;
//
//    IMeshSceneNode* node = _smgr->addMeshSceneNode(mesh);
//    _node = node;
//    if (node)
//    {
//	node->setMaterialFlag(EMF_LIGHTING, true);
////	node->setMaterialFlag(EMF_FOG_ENABLE, true);
//	    node->setMaterialTexture(0, _assets->getTexture(PERSO, TEXTURE, 0));
////	for (int i = 0; i < 9; i++)//TODO : comment faire pour ne pas mettre le nombre de textures en dur
////	{
////	    node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE, 0));
////	}
//
//	this->scaleOnCase();
//	this->updateNodePosition();
//	return true;
//    }    

    IAnimatedMesh* mesh = static_cast<IAnimatedMesh*>(_assets->getMesh(PERSO, MESH, 0));
    if (!mesh)
	return false;
    
    IAnimatedMeshSceneNode* node = _smgr->addAnimatedMeshSceneNode(mesh);
    _node = node;
    if (node)
    {
	node->setMaterialFlag(EMF_LIGHTING, true);
	//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	node->setMD2Animation(EMAT_STAND);

	this->scaleOnCase();
	this->updateNodePosition();
	node->setMaterialTexture(0, _assets->getTexture(PERSO, TEXTURE, 0));
	return true;
    }    
    return false;
}

int PersoObject::getIndex() const
{
    return _index;
}
void PersoObject::setIndex(int index)
{
    this->_index = index;
}
