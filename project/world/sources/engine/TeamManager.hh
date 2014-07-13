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
    struct  Team
    {
//	std::vector<PlayerObject*>  players;
	int			    players_by_level[Assets::LEVEL_MAX];
	int			    resources[RESSOURCE_TYPE_COUNT];
	int			    eggs;
    };

    TeamManager(MapObject const* mapObject);
//    TeamManager(const TeamManager& orig);
    virtual ~TeamManager();

    bool    update();
    
    bool    addTeam(std::string const& name);
    bool    addPlayerInTeam(std::string const& name, PlayerObject const* player);
    bool    removePlayerInTeam(std::string const& name, PlayerObject const* player);
    bool    addEggInTeam(std::string const& name);
    bool    removeEggInTeam(std::string const& name);

    //    void    addPersoInTeam(std::string const& name);
//    void    removePersoFromTeam(std::string const& name);

    bool    teamNameHandler(t_infos * infos);
    bool    playerConnectionHandler(t_infos *infos);
    bool    playerDeathHandler(t_infos *infos);
    bool    eggHandler(t_infos *infos);
    bool    eggDeathHandler(t_infos *infos);

    std::map<std::string, Team> const&	getTeamsInfo() const { return _teams; }
    
private:
//    std::map<std::string, std::vector<PlayerObject*>>	    _teams;
    std::map<std::string, Team>	    _teams;
    MapObject*	_mapObject;
};

#endif	/* TEAMMANAGER_HH */

