/* 
 * File:   EggObject.cpp
 * Author: marie
 * 
 * Created on July 8, 2014, 10:01 PM
 */

#include "EggObject.hh"

using namespace video;
using namespace scene;
using namespace core;

EggObject::EggObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AMeshObject(smgr, parent, pos)
{
}

//EggObject::EggObject(EggObject const& orig)
//: AGameElement(static_cast<AGameElement const&>(orig)),
//    AMeshObject(static_cast<AMeshObject const&>(orig))
//{
//}

EggObject::~EggObject()
{
}

bool    EggObject::init()
{
    IMesh* mesh = _assets->getMesh(EGG, MESH, 0);
    if (!mesh)
	return false;

    ISceneNode* node = _smgr->addCubeSceneNode(1.f, getParentNode());
    _node = node;
    if (node)
    {
	node->setPosition(vector3df(0,0,0));
	node->setMaterialFlag(EMF_LIGHTING, true);
//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	node->setMaterialTexture(0, _assets->getTexture(EGG, TEXTURE, 0));
	return true;
    }    
    return false;
}
