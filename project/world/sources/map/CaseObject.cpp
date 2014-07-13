/* 
 * File:   CaseObject.cpp
 * Author: marie
 * 
 * Created on July 10, 2014, 4:35 PM
 */

#include <algorithm>

#include "CaseObject.hh"

using namespace core;
using namespace scene;

CaseObject::CaseObject(ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: ANodeObject(smgr, parent, pos)
{
    _alignment = posf_t(0, 0);
    _scale = vector3df(1);
    _ressources.fill(new RessourceObject(_smgr, this, pos)); //util?
}
//CaseObject::CaseObject(const CaseObject& orig)
//: ANodeObject(static_cast<ANodeObject const&> (orig))
//{
//    //TODO : copier les element de caseobject
//}
CaseObject::~CaseObject()
{
    //delete tous les objets portes ?
}

//prendre des pointeurs sur fonctions ?
bool CaseObject::init()
{
    //    for (std::pair<int, EggObject*>&& egg : _eggs) {
    //	egg.second->init();
    //    }
    //    for (std::pair<int, PlayerObject*>&& player : _players) {
    //	player.second->init();
    //    }
    //    for (RessourceObject* ressource : _ressources) {
    //	ressource->init();
    //    }
    return true;
}
bool CaseObject::update()
{
    for (std::pair<int, INodeObject*>&& egg : _eggs) {
	egg.second->update();
    }
    for (std::pair<int, PlayerObject*>&& player : _players) {
	player.second->update();
    }
    for (RessourceObject* ressource : _ressources) {
	ressource->update();
    }
    return true;
}


const std::map<int, EggObject*>& CaseObject::getEggs() const
{
    return _eggs;
}
const std::map<int, PlayerObject*>& CaseObject::getPlayers() const
{
    return _players;
}
const std::array<RessourceObject*, RESSOURCE_TYPE_COUNT>& CaseObject::getRessources() const
{
    return _ressources;
}
INodeObject* CaseObject::getObjectFromNode(const irr::scene::ISceneNode* node) const
{
    for (std::pair<int, INodeObject*>&& egg : _eggs) {
	if (*(egg.second) == node)
	    return egg.second;
    }
    for (std::pair<int, PlayerObject*>&& player : _players) {
	if (*(player.second) == node)
	    return player.second;
    }
    for (RessourceObject* ressource : _ressources) {
	if (*(ressource) == node)
	    return ressource;
    }
    return nullptr;
}



bool CaseObject::setCaseContent(const std::array<int, RESSOURCE_TYPE_COUNT>& quantity)
{
    for (int i = 0; i < RESSOURCE_TYPE_COUNT; i++)
    {
	RessourceObject* ressource = _ressources.at(i);
	assert(ressource != nullptr);
	if (!ressource || !ressource->init())
	    return false;
	ressource->setPositionInMap(_pos);
	ressource->setLevel(i);
	int q = quantity.at(i);
	ressource->setQuantity(q);
	ressource->getNode()->setVisible(q > 0);
	_ressources[i] = ressource;
    }
    return true;
}

bool CaseObject::addPlayer(int index, Orientation const& o, int level, const std::string& team)
{
    PlayerObject* player = new PlayerObject(_smgr, this, _pos);
    if (!player || !player->initWithLevel(level))
	return false;
    player->setIndex(index);
    player->setOrientation(o);
    player->setLevel(level);
    player->setTeam(team);
    _players.insert(std::pair<int, PlayerObject*>(index, player));
    return true;
}
void CaseObject::removePlayer(int index)
{
    std::map<int, PlayerObject*>::iterator it = _players.find(index);
    _players.erase(it);
    delete it->second;
}

void CaseObject::registerPlayer(PlayerObject* player)
{
    _players.insert(std::pair<int, PlayerObject*>(player->getIndex(), player));
}
PlayerObject* CaseObject::unregisterPlayer(int index)
{
    std::map<int, PlayerObject*>::iterator it = _players.find(index);
    PlayerObject * player = it->second;
    _players.erase(it);
    return player;
}

bool CaseObject::addEgg(int index, int playerIndex)
{
    EggObject* egg = new EggObject(_smgr, this, _pos);
    if (!egg || !egg->init())
	return false;
    egg->setIndex(index);
    egg->setPlayerIndex(playerIndex);
    _eggs.insert(std::pair<int, EggObject*>(index, egg));
    return true;
}

void CaseObject::removeEgg(int index)
{
    std::map<int, EggObject*>::iterator it = _eggs.find(index);
    _eggs.erase(it);
    delete it->second;
}


bool CaseObject::handlerRelay(t_data* data)
{
    (void)data;
    //    if (data->game_element_type == PLAYER_CLASS
    //	    || data->game_element_type == RESSOURCE_CLASS
    //	    || data->game_element_type == EGG_CLASS)
    //    {
    //	t_infos * infos = data->infos;
    //	switch (data->event_type)
    //	{
    //	    default:
    //		break;
    //	}
    //    }
    //    std::cout << "UNKNOWN CASE EVENT !" << std::endl;
    return false;
}

bool CaseObject::caseContentHandler(t_infos* infos)
{
    return setCaseContent(infos->quantity);
}
bool CaseObject::playerConnectionHandler(t_infos* infos)
{
    return addPlayer(infos->player_id, infos->orientation, infos->level, infos->team_name);
}

bool CaseObject::playerDeathHandler(t_infos* infos)
{
    removePlayer(infos->player_id);
    return true;
}

bool CaseObject::eggHandler(t_infos* infos)
{
    return addEgg(infos->egg_id, infos->player_id);
}
bool CaseObject::eggDeathHandler(t_infos* infos)
{
    removeEgg(infos->egg_id);
    return true;
}


