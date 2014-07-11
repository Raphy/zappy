/* 
 * File:   AObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:36 PM
 */

#include "ANodeObject.hh"
//#include "Binder.hh"
#include "Helper.hh"

using namespace	core;

ANodeObject::ANodeObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: _helper(Helper::getInstance()), _assets(Assets::getInstance()), _smgr(smgr),
	_parent(static_cast<ANodeObject*>(parent)), _node(nullptr), _pos(pos), _alignment(0.5,0.5), _scale(0.2,0.2,0.2)
{
}

//ANodeObject::ANodeObject(const ANodeObject& orig)
//: _smgr(orig.getSceneManager()), _parent(orig.getParent()), _node(orig.getNode()), _pos(orig.getPositionInMap())
//{
//}

ANodeObject::~ANodeObject()
{
}

bool    ANodeObject::init()
{
    return true;
}
bool    ANodeObject::update()
{
    return true;
}

scene::ISceneNode* ANodeObject::getNode() const
{
    return static_cast<scene::ISceneNode*>(_node);
}
INodeObject* ANodeObject::getParent() const
{
    return _parent;
}
scene::ISceneNode* ANodeObject::getParentNode() const
{
    //TODO : debug !
    if (!_parent)
	return _smgr->getRootSceneNode();
    return (_parent->getNode());
//    return _smgr->getRootSceneNode();
}
scene::ISceneManager* ANodeObject::getSceneManager() const
{
    return _smgr;
}




void ANodeObject::setPositionInMap(posi_t const& new_pos)
{
    _pos = new_pos;
    this->updateNodePosition();
}
posi_t const& ANodeObject::getPositionInMap() const
{
    return _pos;
}
void ANodeObject::updateNodePosition()
{
    if (_node)
    {
	posf_t real_pos(_pos.first + _alignment.first, _pos.second + _alignment.second);
	vector3df pos = _helper->mapToWorldCoordinates(real_pos);
	_node->setPosition(pos);
    }
}
void ANodeObject::scaleOnCase()
{
    if (_node)
    {
	vector3df extent = _node->getTransformedBoundingBox().getExtent();
	vector3df scale = _node->getScale() / extent;
	scale *= _scale;
	scale *= _helper->getCaseSize();
	_node->setScale(scale);
    }
}

