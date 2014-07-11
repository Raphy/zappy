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

#include    "PlayerObject.hh"
#include    "RessourceObject.hh"

class CaseObject : public ANodeObject, public INetworkEventHandler
{
public:
    CaseObject(scene::ISceneManager* smgr, INodeObject* parent, posi_t const& pos);
//    CaseObject(const CaseObject& orig);
    virtual ~CaseObject();

    bool    callHandler(t_data * data);

    /* HANDLERS */
    bool	    addPlayer(int index, Orientation const& o, int level, const std::string& team);
    void	    removePlayer(int index);

    void	    registerPlayer(PlayerObject* player);
    PlayerObject*    unregisterPlayer(int index);

//    bool	    addEgg(int index);
//    INodeObject*    removeEgg(int index);
    bool    setCaseContent(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity);
    
    
    /* GETTERS/SETTERS */
    std::map<int, INodeObject*> const& getEggs() const;
    std::map<int, INodeObject*> const& getPlayers() const;
    std::array<RessourceObject*, RESSOURCE_TYPE_COUNT> const& getRessources() const;

private:
    std::map<int, INodeObject*>	_eggs;
    std::map<int, INodeObject*>	_players;
    std::array<RessourceObject*, RESSOURCE_TYPE_COUNT>	_ressources;
};

#endif	/* CASEOBJECT_HH */

