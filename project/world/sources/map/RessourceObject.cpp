/* 
 * File:   RessourceObject.cpp
 * Author: marie
 * 
 * Created on July 8, 2014, 6:47 PM
 */

#include "RessourceObject.hh"

using namespace video;
using namespace scene;
using namespace core;

RessourceObject::RessourceObject(scene::ISceneManager* smgr, INodeObject* parent)
: AMeshObject(smgr, parent)
{
}

RessourceObject::RessourceObject(RessourceObject const& orig)
: AGameElement(static_cast<AGameElement const&>(orig)),
    AMeshObject(static_cast<AMeshObject const&>(orig))
{
}

RessourceObject::~RessourceObject()
{
}

bool    RessourceObject::init()
{
//    IMesh* mesh = _ressources->getMesh(PERSO, MESH, 0);
//    if (!mesh)
//	return false;

//    ISceneNode* node = _smgr->addCubeSceneNode(1.f, getParentNode());
    ISceneNode* node = _smgr->addSphereSceneNode(1.0f, 16, getParentNode());
    _node = node;
    if (node)
    {
//	node->setMaterialFlag(EMF_LIGHTING, true);
//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
//	node->setMaterialTexture(0, _assets->getTexture(RESSOURCE, TEXTURE, 0));

	this->scaleOnCase();
	this->updateNodePosition();
	return true;
    }    
    return false;
}
