/* 
 * File:   AMeshObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 9:37 PM
 */

#include "AMeshObject.hh"

AMeshObject::AMeshObject(scene::ISceneManager* smgr, IObject* parent)
: AObject(smgr, parent)
{
}

AMeshObject::AMeshObject(const AMeshObject& orig)
: AObject(static_cast<AObject const&>(orig))
{
}

AMeshObject::~AMeshObject()
{
}

scene::IMeshSceneNode*  AMeshObject::getMeshNode() const
{
    return static_cast<scene::IMeshSceneNode*>(_node);
}
