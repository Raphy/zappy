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

#include    "PersoObject.hh"
#include    "RessourceObject.hh"

class CaseObject : public ANodeObject, public INetworkEventHandler
{
public:
    CaseObject(scene::ISceneManager* smgr, INodeObject* parent, posi_t const& pos);
//    CaseObject(const CaseObject& orig);
    virtual ~CaseObject();

    bool    callHandler(t_data * data);

    /* HANDLERS */
    bool	    addPerso(int index, Orientation const& o, int level, const std::string& team);
    void	    removePerso(int index);

    void	    registerPerso(PersoObject* perso);
    void	    unregisterPerso(PersoObject* perso);

//    bool	    addEgg(int index);
//    INodeObject*    removeEgg(int index);
    bool    setCaseContent(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity);
    
    
    /* GETTERS/SETTERS */
    std::map<int, INodeObject*> const& getEggs() const;
    std::map<int, INodeObject*> const& getPersos() const;
//    std::array<INodeObject*, RESSOURCE_TYPE_COUNT> const& getRessources() const;
    std::array<RessourceObject*, RESSOURCE_TYPE_COUNT> const& getRessources() const;

private:
//    posi_t			_pos;
    std::map<int, INodeObject*>	_eggs;
    std::map<int, INodeObject*>	_persos;
//    std::array<INodeObject*, RESSOURCE_TYPE_COUNT>	_ressources;
    std::array<RessourceObject*, RESSOURCE_TYPE_COUNT>	_ressources;
};

#endif	/* CASEOBJECT_HH */

