/* 
 * File:   MapObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:34 PM
 */

#include "MapObject.hh"
#include "Ressources.hh"
//bool loadTheNode(IrrlichtDevice* device, IVideoDriver* driver, ISceneManager* smgr)
//{
//    IAnimatedMesh* mesh = smgr->getMesh("../media/sydney.md2");
//    if (!mesh)
//    {
//	//device->drop();
//	return false;
//    }
//    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );
//    
//    if (node)
//    {
//	node->setMaterialFlag(EMF_LIGHTING, true);
//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
//	node->setMD2Animation(EMAT_STAND);
//	node->setMaterialTexture( 0, driver->getTexture("../media/sydney.bmp") );
//    } 
//    return true;
//}

MapObject::MapObject(scene::ISceneManager* smgr, IObject* parent)
: AAnimatedMeshObject(smgr, parent)
{
}

MapObject::MapObject(const MapObject& orig)
: AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
{
}

MapObject::~MapObject()
{
}

bool    MapObject::init()
{
    if (_parent)
        _node = (Ressources::getInstance())->getMapNode(_smgr, _parent->getNode());
    else
        _node = (Ressources::getInstance())->getMapNode(_smgr, _smgr->getRootSceneNode());
}

