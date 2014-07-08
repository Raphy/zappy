/* 
 * File:   PersoObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include <iostream>
#include "AnimatedPersoObject.hh"

using namespace video;
using namespace scene;
using namespace core;

AnimatedPersoObject::AnimatedPersoObject(scene::ISceneManager* smgr, INodeObject* parent)
: AAnimatedMeshObject(smgr, parent)
{
}

AnimatedPersoObject::AnimatedPersoObject(AnimatedPersoObject const& orig)
: AGameElement(static_cast<AGameElement const&>(orig)),
	AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
{
}

AnimatedPersoObject::~AnimatedPersoObject()
{
}

bool    AnimatedPersoObject::init()
{
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
	//	node->setMD2Animation(EMAT_ATTACK);
	//	node->setMD2Animation(EMAT_JUMP);
	//	node->setMD2Animation(EMAT_RUN);

	vector3df extent= node->getTransformedBoundingBox().getExtent();
	node->setScale(vector3df(1.0 / extent.X, 1.0 / extent.Y, 1.0 / extent.Z));
	
	vector3df pos = node->getPosition();
	vector3df new_pos(pos.X,pos.Y + 0.5,pos.Z);
	
	node->setPosition(new_pos);
	
	node->setMaterialTexture(0, _assets->getTexture(PERSO, TEXTURE, 0));
	return true;
    }    
    return false;
}
