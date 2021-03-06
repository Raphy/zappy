/* 
 * File:   CaseObject.hh
 * Author: marie
 *
 * Created on July 10, 2014, 4:35 PM
 */

#ifndef CASEOBJECT_HH
#define	CASEOBJECT_HH

#include    <iostream>
#include    <array>
#include    <map>
#include    "ANodeObject.hh"
#include    "INetworkEventHandler.hh"

#include    "EggObject.hh"
#include    "PlayerObject.hh"
#include    "RessourceObject.hh"

class CaseObject : public ANodeObject, public INetworkEventHandler
{
public:
    CaseObject(scene::ISceneManager* smgr, INodeObject* parent, posi_t const& pos);
//    CaseObject(const CaseObject& orig);
    virtual ~CaseObject();

    bool    init();
    bool    update();

    /* GETTERS/SETTERS */
    std::map<int, EggObject*> const&				getEggs() const;
    std::map<int, PlayerObject*> const&				getPlayers() const;
    std::array<RessourceObject*, RESSOURCE_TYPE_COUNT> const&	getRessources() const;

    INodeObject*    getObjectFromNode(const scene::ISceneNode* node) const;
    
    /* HANDLERS IMPLEMENTATION */
    bool	    addPlayer(unsigned int index, Orientation const& o, int level, const std::string& team);
    void	    removePlayer(unsigned int index);
    void	    registerPlayer(PlayerObject* player);
    PlayerObject*   unregisterPlayer(unsigned int index);
    bool	    addEgg(unsigned int index, int playerIndex);
    void	    removeEgg(unsigned int index);
    bool	    setCaseContent(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity);
    
    /* HANDLERS */
    bool    handlerRelay(t_data * data);

    bool    caseContentHandler(t_infos *infos);
    bool    playerConnectionHandler(t_infos *infos);
    bool    playerDeathHandler(t_infos *infos);
    bool    eggHandler(t_infos *infos);
    bool    eggDeathHandler(t_infos *infos);
    

private:
    std::map<int, EggObject*>				_eggs;
    std::map<int, PlayerObject*>			_players;
    std::array<RessourceObject*, RESSOURCE_TYPE_COUNT>	_ressources;
};

#endif	/* CASEOBJECT_HH */

