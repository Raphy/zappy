/* 
 * File:   AAnimatedMeshObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 11:03 PM
 */

#include "AAnimatedMeshObject.hh"

AAnimatedMeshObject::AAnimatedMeshObject(scene::ISceneManager* smgr, INodeObject* parent)
: AMeshObject(smgr, parent)
{
}

AAnimatedMeshObject::AAnimatedMeshObject(AAnimatedMeshObject const& orig)
: AMeshObject(static_cast<AMeshObject const&>(orig))
{
}

AAnimatedMeshObject::~AAnimatedMeshObject()
{
}

scene::IAnimatedMeshSceneNode*  AAnimatedMeshObject::getAnimatedMeshNode() const
{
    return static_cast<scene::IAnimatedMeshSceneNode*>(_node);
}