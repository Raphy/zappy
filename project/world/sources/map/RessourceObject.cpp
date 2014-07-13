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

RessourceObject::RessourceObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AMeshObject(smgr, parent, pos), _quantity(0)
{
    _scale = vector3df(1.f / RESSOURCE_TYPE_COUNT);
    _type = RESSOURCE;
}

//RessourceObject::RessourceObject(RessourceObject const& orig)
//: AGameElement(static_cast<AGameElement const&>(orig)),
//    AMeshObject(static_cast<AMeshObject const&>(orig))
//{
//}

RessourceObject::~RessourceObject()
{
}

bool    RessourceObject::init()
{
    //    IMesh* mesh = _ressources->getMesh(PLAYER, MESH, 0);
    //    if (!mesh)
    //	return false;
    assert(_parent);
    assert(this->getParentNode());
    //    ISceneNode* node = _smgr->addCubeSceneNode(1.f, getParentNode());
    ISceneNode* node = _smgr->addSphereSceneNode(1.0f, 16, this->getParentNode(), NODE_ID_RESSOURCE);
    _node = node;
    _alignment = posf_t(0.1,0.1);
    if (node)
    {
	node->setMaterialFlag(EMF_LIGHTING, false);
	//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	node->setMaterialTexture(0, _assets->getTexture(RESSOURCE, TEXTURE, 0));
	
	this->scaleOnCase();
	this->updateNodePosition();
	return true;
    }    
    return false;
}
bool RessourceObject::update()
{
    return true;
}


void RessourceObject::setQuantity(int quantity)
{
    this->_quantity = quantity;
}
int RessourceObject::getQuantity() const
{
    return _quantity;
}

bool RessourceObject::setLevel(int level)
{
    if (level > _maxLevel)
	return false;
    _node->setMaterialTexture(0, _assets->getTexture(RESSOURCE, TEXTURE, level));
    _alignment.first = level * 1.0f / RESSOURCE_TYPE_COUNT;
    updateNodePosition();
    _level = level;
    return true;
}
