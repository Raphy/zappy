/* 
 * File:   PlayerObject.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:57 PM
 */

#include <iostream>
#include "PlayerObject.hh"

using namespace video;
using namespace scene;
using namespace core;

typedef std::pair<Orientation, void (PlayerObject::*)()> rotate_pair;

PlayerObject::PlayerObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AAnimatedMeshObject(smgr, parent, pos)
{
    _scale = vector3df(0.4);//?
    _type = PLAYER;
    //    std::vector<void (PlayerObject::*)()>	_rotateFuncs;
    _rotateFuncs.insert(rotate_pair(NORTH, &PlayerObject::rotateOnNorth));
    _rotateFuncs.insert(rotate_pair(EAST, &PlayerObject::rotateOnEast));
    _rotateFuncs.insert(rotate_pair(SOUTH, &PlayerObject::rotateOnSouth));
    _rotateFuncs.insert(rotate_pair(WEST, &PlayerObject::rotateOnWest));
}

//PlayerObject::PlayerObject(PlayerObject const& orig)
//: AGameElement(static_cast<AGameElement const&>(orig)),
//    AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig))
//{
//}

PlayerObject::~PlayerObject()
{
}

bool	PlayerObject::init()
{
    //call initWithLevel instead
    assert(false);
    return false;
}
bool    PlayerObject::initWithLevel(int level)
{
//    IMesh* mesh = _assets->getMesh(PLAYER, MESH, 0);
//    if (!mesh)
//	return false;
//
//    IMeshSceneNode* node = _smgr->addMeshSceneNode(mesh);
//    _node = node;
//    if (node)
//    {
//	node->setMaterialFlag(EMF_LIGHTING, true);
////	node->setMaterialFlag(EMF_FOG_ENABLE, true);
//	    node->setMaterialTexture(0, _assets->getTexture(PLAYER, TEXTURE, 0));
////	for (int i = 0; i < 9; i++)//TODO : comment faire pour ne pas mettre le nombre de textures en dur
////	{
////	    node->setMaterialTexture(0, _ressources->getTexture(PLAYER, TEXTURE, 0));
////	}
//
//	this->scaleOnCase();
//	this->updateNodePosition();
//	return true;
//    }    

    _level = level;
    
    IAnimatedMesh* mesh = static_cast<IAnimatedMesh*>(_assets->getMesh(PLAYER, MESH, _level));
    if (!mesh)
	return false;
    
    IAnimatedMeshSceneNode* node = _smgr->addAnimatedMeshSceneNode(mesh);
    _node = node;
    if (node)
    {
	node->setMaterialFlag(EMF_LIGHTING, false);
	//	node->setMaterialFlag(EMF_FOG_ENABLE, true);
	startNewAnim(EMAT_STAND, REPEAT);
	startNewAnim(EMAT_SALUTE, ONCE);
//	node->setMD2Animation(EMAT_STAND);

	this->scaleOnCase();
	this->updateNodePosition();
	node->setMaterialTexture(0, _assets->getTexture(PLAYER, TEXTURE, _level));
	return true;
    }    
    return false;
}


int PlayerObject::getIndex() const
{
    return _index;
}
void PlayerObject::setIndex(int index)
{
    this->_index = index;
}
const Orientation& PlayerObject::getOrientation() const
{
    return _orientation;
}
void PlayerObject::setOrientation(const Orientation& orientation)
{
    this->_orientation = orientation;
    (this->*(_rotateFuncs[orientation]))();
}
bool PlayerObject::setInventory(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity)
{
    //TODO : clean l'ancien inventory ?
    _inventory = quantity;
    return true;
}
const std::array<int, RESSOURCE_TYPE_COUNT>& PlayerObject::getInventory() const
{
    return _inventory;
}
const std::string& PlayerObject::getTeam() const
{
    return _team;
}
void PlayerObject::setTeam(const std::string& _team)
{
    this->_team = _team;
}
bool PlayerObject::setLevel(int level)
{
    if (level > _maxLevel)
	return false;
    initWithLevel(_level);
    (this->*(_rotateFuncs[_orientation]))();
    _level = level;
    return true;
}



void PlayerObject::rotateOnNorth()
{
    _node->setRotation(vector3df(0,-90,0));
}
void PlayerObject::rotateOnEast()
{
    _node->setRotation(vector3df(0,0,0));
}
void PlayerObject::rotateOnSouth()
{
    _node->setRotation(vector3df(0,90,0));
}
void PlayerObject::rotateOnWest()
{
    _node->setRotation(vector3df(0,180,0));
}
