/* 
 * File:   TeamManager.cpp
 * Author: marie
 * 
 * Created on July 13, 2014, 2:36 AM
 */

#include <algorithm>
#include "TeamManager.hh"

TeamManager::TeamManager()
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
    _teams.insert(std::pair<std::string, std::vector < PlayerObject*>>(name, std::vector<PlayerObject*>()));
    return true;
}
void TeamManager::registerPersoInTeam(const std::string& name, PlayerObject* player)
{
    _teams[name].push_back(player);
}
void TeamManager::unregisterPersoInTeam(const std::string& name, PlayerObject* player)
{
    std::vector<PlayerObject*> team = _teams[name];
    std::vector<PlayerObject*>::iterator it = std::find(team.begin(), team.end(), player);
    team.erase(it);
}

bool TeamManager::teamNameHandler(t_infos* infos)
{
    return addTeam(infos->team_name);
}
