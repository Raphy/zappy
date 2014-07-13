/* 
 * File:   TeamManager.cpp
 * Author: marie
 * 
 * Created on July 13, 2014, 2:36 AM
 */

#include <algorithm>
#include "TeamManager.hh"
#include "MapObject.hh"

TeamManager::TeamManager(MapObject const* mapObject)
: _mapObject(const_cast<MapObject*>(mapObject))//C'EST SALE !
{
}

//TeamManager::TeamManager(TeamManager const& orig)
//{
//}

TeamManager::~TeamManager()
{
}

bool TeamManager::addTeam(const std::string& name)
{
    //TODO : check existing
//    _teams.insert(std::pair<std::string, std::vector < PlayerObject*>>(name, std::vector<PlayerObject*>()));
    Team team;
    std::pair<std::string, Team> teamPair(name, team);
    _teams.insert(teamPair);
    return true;
}
bool TeamManager::addPlayerInTeam(const std::string& name, PlayerObject const* player)
{
    auto inventory = player->getInventory();
    Team team = _teams[name];
    team.players_by_level[player->getLevel()] += 1;
    for (int i = 0; i < RESSOURCE_TYPE_COUNT; i++)
	team.resources[i] += inventory[i];
    return true;
}
bool TeamManager::removePlayerInTeam(const std::string& name, PlayerObject const* player)
{
    auto inventory = player->getInventory();
    Team team = _teams[name];
    team.players_by_level[player->getLevel()] -= 1;
    for (int i = 0; i < RESSOURCE_TYPE_COUNT; i++)
	team.resources[i] -= inventory[i];
//    std::vector<PlayerObject*> team = _teams[name];
//    std::vector<PlayerObject*>::iterator it = std::find(team.begin(), team.end(), player);
//    team.erase(it);
    return true;
}
bool TeamManager::addEggInTeam(const std::string& name)
{
    Team team = _teams[name];
    team.eggs += 1;
    return true;
}
bool TeamManager::removeEggInTeam(const std::string& name)
{
    Team team = _teams[name];
    team.eggs -= 1;
    return true;
}





bool TeamManager::teamNameHandler(t_infos* infos)
{
    return addTeam(infos->team_name);
}
bool TeamManager::playerConnectionHandler(t_infos* infos)
{
    return addPlayerInTeam(infos->team_name, _mapObject->getPlayerFromIndex(infos->player_id));
}

bool TeamManager::playerDeathHandler(t_infos* infos)
{
    PlayerObject const* player = _mapObject->getPlayerFromIndex(infos->player_id);
    return removePlayerInTeam(player->getTeam(), player);
}

bool TeamManager::eggHandler(t_infos* infos)
{
    EggObject const*	egg = _mapObject->getEggFromIndex(infos->egg_id);
    return addEggInTeam(static_cast<PlayerObject*>(egg->getParent())->getTeam());
}
bool TeamManager::eggDeathHandler(t_infos* infos)
{
    EggObject const*	egg = _mapObject->getEggFromIndex(infos->egg_id);
    return removeEggInTeam(static_cast<PlayerObject*>(egg->getParent())->getTeam());
}

