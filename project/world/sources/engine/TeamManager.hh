/* 
 * File:   TeamManager.hh
 * Author: marie
 *
 * Created on July 13, 2014, 2:36 AM
 */

#ifndef TEAMMANAGER_HH
#define	TEAMMANAGER_HH

#include    <map>
#include    <vector>
#include    <string>
#include    "PlayerObject.hh"
#include    "World.hh"

class TeamManager
{
public:
    TeamManager();
//    TeamManager(const TeamManager& orig);
    virtual ~TeamManager();

    bool    addTeam(std::string const& name);
    void    registerPersoInTeam(std::string const& name, PlayerObject* player);
    void    unregisterPersoInTeam(std::string const& name, PlayerObject* player);

    bool    teamNameHandler(t_infos * infos);
    
private:
    std::map<std::string, std::vector<PlayerObject*>>	    _teams;
};

#endif	/* TEAMMANAGER_HH */

