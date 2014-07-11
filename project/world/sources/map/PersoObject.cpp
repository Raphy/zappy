/* 
 * File:   PersoObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include <iostream>
#include "PersoObject.hh"

using namespace video;
using namespace scene;
using namespace core;

typedef std::pair<Orientation, void (PersoObject::*)()> rotate_pair;

PersoObject::PersoObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AAnimatedMeshObject(smgr, parent, pos)
{
    _scale = vector3df(0.4);//?
//    std::vector<void (PersoObject::*)()>	_rotateFuncs;
    _rotateFuncs.insert(rotate_pair(NORTH, &PersoObject::rotateOnNorth));
    _rotateFuncs.insert(rotate_pair(EAST, &PersoObject::rotateOnEast));
    _rotateFuncs.insert(rotate_pair(SOUTH, &PersoObject::rotateOnSouth));
    _rotateFuncs.insert(rotate_pair(WEST, &PersoObject::rotateOnWest));
}

//PersoObject::PersoObject(PersoObject const& orig)
//: AGameElement(static_cast<AGameElement const&>(orig)),
//    AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
//{
//}

PersoObject::~PersoObject()
{
}

bool	PersoObject::init()
{
    //call initWithLevel instead
    assert(false);
    return false;
}
bool    PersoObject::initWithLevel(int level)
{
//    IMesh* mesh = _assets->getMesh(PERSO, MESH, 0);
//    if (!mesh)
//	return false;
//
//    IMeshSceneNode* node = _smgr->addMeshSceneNode(mesh);
//    _node = node;
//    if (node)
//    {
//	node->setMaterialFlag(EMF_LIGHTING, true);
////	node->setMaterialFlag(EMF_FOG_ENABLE, true);
//	    node->setMaterialTexture(0, _assets->getTexture(PERSO, TEXTURE, 0));
////	for (int i = 0; i < 9; i++)//TODO : comment faire pour ne pas mettre le nombre de textures en dur
////	{
////	    node->setMaterialTexture(0, _ressources->getTexture(PERSO, TEXTURE, 0));
////	}
//
//	this->scaleOnCase();
//	this->updateNodePosition();
//	return true;
//    }    

    _level = level;
    
    IAnimatedMesh* mesh = static_cast<IAnimatedMesh*>(_assets->getMesh(PERSO, MESH, _level));
    if (!mesh)
	return false;
    
    IAnimatedMeshSceneNode* node = _smgr->addAnimatedMeshSceneNode(mesh);
    _node = node;
    if (node)
    {
	node->setMaterialFlag(EMF_LIGHTING, false);
	//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	node->setMD2Animation(EMAT_STAND);

	this->scaleOnCase();
	this->updateNodePosition();
	node->setMaterialTexture(0, _assets->getTexture(PERSO, TEXTURE, _level));
	return true;
    }    
    return false;
}


int PersoObject::getIndex() const
{
    return _index;
}
void PersoObject::setIndex(int index)
{
    this->_index = index;
}
const Orientation& PersoObject::getOrientation() const
{
    return _orientation;
}
void PersoObject::setOrientation(const Orientation& orientation)
{
    this->_orientation = orientation;
    (this->*(_rotateFuncs[orientation]))();
}
bool PersoObject::setInventory(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity)
{
    return false;
}
const std::array<int, RESSOURCE_TYPE_COUNT>& PersoObject::getInventory() const
{
    return _inventory;
}
const std::string& PersoObject::getTeam() const
{
    return _team;
}
void PersoObject::setTeam(const std::string& _team)
{
    this->_team = _team;
}
bool PersoObject::setLevel(int level)
{
    if (level > _maxLevel)
	return false;
    initWithLevel(_level);
    (this->*(_rotateFuncs[_orientation]))();
    _level = level;
    return true;
}



void PersoObject::rotateOnNorth()
{
    _node->setRotation(vector3df(0,-90,0));
}
void PersoObject::rotateOnEast()
{
    _node->setRotation(vector3df(0,0,0));
}
void PersoObject::rotateOnSouth()
{
    _node->setRotation(vector3df(0,90,0));
}
void PersoObject::rotateOnWest()
{
    _node->setRotation(vector3df(0,180,0));
}
