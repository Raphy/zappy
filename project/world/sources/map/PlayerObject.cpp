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
    
    IAnimatedMeshSceneNode* node = _smgr->addAnimatedMeshSceneNode(mesh, getParentNode(), NODE_ID_PLAYER);
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
void PlayerObject::setIndex(unsigned int index)
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
    level = 3;//test
    if (level > _maxLevel)
	return false;
    initWithLevel(_level);
    (this->*(_rotateFuncs[_orientation]))();
    _level = level;
    return true;
}

bool PlayerObject::expel()
{
    return startNewAnim(EMAT_ATTACK, ONCE);
}
bool PlayerObject::broadcast()
{
    return startNewAnim(EMAT_PAIN_A, ONCE);
}
bool PlayerObject::incant(bool begin)
{
    if (begin)
        return startNewAnim(EMAT_JUMP, REPEAT_UNTIL_STOP_CALL);
    return stopLastAnim();
}
bool PlayerObject::fork()
{
    return startNewAnim(EMAT_JUMP, ONCE);
}
bool PlayerObject::takeRessource()
{
    return startNewAnim(EMAT_CROUCH_STAND, ONCE);    
}
bool PlayerObject::throwRessource()
{
    return startNewAnim(EMAT_CROUCH_ATTACK, ONCE);
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

/* HANDLERS */
bool PlayerObject::levelHandler(t_infos* infos)
{
    return setLevel(infos->level);
}
bool PlayerObject::inventoryHandler(t_infos* infos)
{
    return setInventory(infos->quantity);
}
bool PlayerObject::expelHandler(__attribute__((unused)) t_infos* infos)
{
    return expel();
}
bool PlayerObject::broadcastHandler(__attribute__((unused)) t_infos* infos)
{
    return broadcast();
}
bool PlayerObject::incantationHandler(t_infos* infos)
{
    return incant(infos->begin);
}
bool PlayerObject::forkHandler(__attribute__((unused)) t_infos* infos)
{
    return fork();
}
bool PlayerObject::takeHandler(__attribute__((unused)) t_infos* infos)
{
    return takeRessource();
}
bool PlayerObject::throwHandler(__attribute__((unused)) t_infos* infos)
{
    return throwRessource();
}
