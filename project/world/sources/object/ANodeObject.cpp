/* 
 * File:   AObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:36 PM
 */

#include "ANodeObject.hh"
#include "Binder.hh"

ANodeObject::ANodeObject(scene::ISceneManager* smgr, INodeObject* parent)
: _binder(Binder::getInstance()), _assets(Assets::getInstance()), _smgr(smgr), _parent(parent), _node(nullptr)
{
}

ANodeObject::ANodeObject(const ANodeObject& orig)
: _smgr(orig.getSceneManager()), _parent(orig.getParent()), _node(orig.getNode())
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
