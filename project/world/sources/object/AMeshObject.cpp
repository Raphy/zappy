/* 
 * File:   AMeshObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 9:37 PM
 */

#include "AMeshObject.hh"

AMeshObject::AMeshObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: ANodeObject(smgr, parent, pos)
{
}

//AMeshObject::AMeshObject(const AMeshObject& orig)
//: ANodeObject(static_cast<ANodeObject const&>(orig))
//{
//}

AMeshObject::~AMeshObject()
{
}

scene::IMeshSceneNode*  AMeshObject::getMeshNode() const
{
    return static_cast<scene::IMeshSceneNode*>(_node);
}
