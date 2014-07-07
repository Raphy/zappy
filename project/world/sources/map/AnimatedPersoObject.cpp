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

AnimatedPersoObject::AnimatedPersoObject(scene::ISceneManager* smgr, IObject* parent)
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
    std::cout << "perso init..." << std::endl;

    IAnimatedMesh* mesh = static_cast<IAnimatedMesh*>(_ressources->getMesh(PERSO, MESH, 0));
    if (!mesh)
	return false;

    IAnimatedMeshSceneNode* node = _smgr->addAnimatedMeshSceneNode(mesh);
    _node = node;
    if (node)
    {
	node->setMaterialFlag(EMF_LIGHTING, false);
//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	node->setMD2Animation(EMAT_STAND);
	node->setMD2Animation(EMAT_ATTACK);
	node->setMD2Animation(EMAT_JUMP);
	node->setMD2Animation(EMAT_RUN);
	node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE, 0));
	return true;
    }    
    return false;
}
