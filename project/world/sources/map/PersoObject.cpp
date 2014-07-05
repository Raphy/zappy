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
	node->setMD2Animation(scene::EMAT_STAND);
	node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE, 0));
	return true;
    }    
    return false;
}
