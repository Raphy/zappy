/* 
 * File:   AObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:36 PM
 */

#include "AObject.hh"
#include "Binder.hh"
#include "Ressources.hh"

AObject::AObject(scene::ISceneManager* smgr, IObject* parent)
: _smgr(smgr), _parent(parent), _node(nullptr), _binder(Binder::getInstance()), _ressources(Ressources::getInstance())
{
}

AObject::AObject(const AObject& orig)
: _smgr(orig.getSceneManager()), _parent(orig.getParent()), _node(orig.getNode())
{
}

AObject::~AObject()
{
}

bool    AObject::init()
{
    return true;
}
bool    AObject::update()
{
    return true;
}
