/* 
 * File:   AObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:36 PM
 */

#include "ANodeObject.hh"
#include "Binder.hh"
#include "Helper.hh"

using namespace	core;

ANodeObject::ANodeObject(scene::ISceneManager* smgr, INodeObject* parent)
: _binder(Binder::getInstance()), _assets(Assets::getInstance()), _smgr(smgr),
    _parent(parent), _node(nullptr), _pos(0,0), _alignment(0.5,0.5)
{
}

ANodeObject::ANodeObject(const ANodeObject& orig)
: _smgr(orig.getSceneManager()), _parent(orig.getParent()), _node(orig.getNode()), _pos(orig.getPositionInMap())
{
}

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

void ANodeObject::setPositionInMap(pos_t const& new_pos)
{
    _pos = new_pos;
    this->updateNodePosition();
}
pos_t const& ANodeObject::getPositionInMap() const
{
    return _pos;
}
void ANodeObject::updateNodePosition()
{
    if (_node)
    {
	pos_t real_pos(_pos.first + _alignment.first, _pos.second + _alignment.second);
	vector3df pos = Helper::MapToWorldCoordinates(real_pos);
//	vector3df pos(_pos.first,0,_pos.second);
//	auto extent = _node->getBoundingBox().getExtent();
//	pos += (_node->getBoundingBox().getExtent() / 2.0);
//	pos += 0.5;
	_node->setPosition(pos);
//	_node->setPosition(vector3df(0,0,0));//debug
    }
}
