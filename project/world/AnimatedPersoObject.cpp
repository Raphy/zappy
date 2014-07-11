/* 
 * File:   PlayerObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include <iostream>
#include "AnimatedPlayerObject.hh"

using namespace video;
using namespace scene;
using namespace core;

AnimatedPlayerObject::AnimatedPlayerObject(scene::ISceneManager* smgr, INodeObject* parent)
: AAnimatedMeshObject(smgr, parent)
{
}

AnimatedPlayerObject::AnimatedPlayerObject(AnimatedPlayerObject const& orig)
: AGameElement(static_cast<AGameElement const&>(orig)),
	AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
{
}

AnimatedPlayerObject::~AnimatedPlayerObject()
{
}

bool    AnimatedPlayerObject::init()
{
    IAnimatedMesh* mesh = static_cast<IAnimatedMesh*>(_assets->getMesh(PLAYER, MESH, 0));
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
	node->setMaterialTexture(0, _assets->getTexture(PLAYER, TEXTURE, 0));
	return true;
    }    
    return false;
}
