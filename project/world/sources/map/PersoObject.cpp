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
: AMeshObject(smgr, parent)
{
}

PersoObject::PersoObject(PersoObject const& orig)
: AGameElement(static_cast<AGameElement const&>(orig)),
    AMeshObject(static_cast<AMeshObject const&>(orig))
{
}

PersoObject::~PersoObject()
{
}

bool    PersoObject::init()
{
    std::cout << "perso init..." << std::endl;

    IMesh* mesh = _ressources->getMesh(PERSO, MESH, 0);
    if (!mesh)
	return false;

    IMeshSceneNode* node = _smgr->addMeshSceneNode(mesh);
    _node = node;
    if (node)
    {
	node->setMaterialFlag(EMF_LIGHTING, false);
//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	    node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE, 0));
//	for (int i = 0; i < 9; i++)//TODO : comment faire pour ne pas mettre le nombre de textures en dur
//	{
//	    node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE, 0));
//	}
	return true;
    }    
    return false;
}
