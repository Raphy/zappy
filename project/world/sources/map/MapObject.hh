/* 
 * File:   MapObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:34 PM
 */

#ifndef MAPOBJECT_HH
#define	MAPOBJECT_HH

#include <list>
#include <vector>
#include <map>
#include "AAnimatedMeshObject.hh"
#include "INetworkEventHandler.hh"
#include "CaseObject.hh"

class MapObject : public AAnimatedMeshObject, INetworkEventHandler
{
public:
    MapObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    MapObject(const MapObject& orig);
    virtual ~MapObject();

    scene::ITriangleSelector* getSelector() const { return _selector; }

    bool    init();
    void    updateNodePosition();
    void    scaleOnCase();

    bool    callHandler(t_data * data);

    /* HANDLERS */

    bool    createGround(int x, int y);
//    bool    setCaseContent(posi_t const& pos, std::vector<int> const& quantity);
//
//    bool    addPlayer(posi_t const& pos, int index,
//			Orientation o, int level, std::string const& team);
//    bool    addEgg(posi_t const& pos);
//
//    bool    removePlayer(int index) { return false; }

private:
    CaseObject*	getCaseObject(posi_t const& pos);// const;
    bool	tryGetCaseObject(posi_t const& pos, CaseObject* caseObject);// const;
    void    initCases();
    
//    bool    addRessource(posi_t const& pos, int level, int quantity);

    scene::ITriangleSelector*	_selector;
//    std::list<INodeObject*>		_players;
//    std::list<INodeObject*>		_eggs;
//    std::map<posi_t, std::vector<INodeObject*>>	_ressources;
    std::vector<std::vector<CaseObject>>    _cases;
    posi_t  _mapSize;
//    std::map<posi_t, CaseObject>    _cases;
};

#endif	/* MAPOBJECT_HH */

//#n X Y O L N

//X Largeur ou position horizontale 
//Y Hauteur ou position verticale 
//q Quantité 
//n Numéro de joueur sur le serveur 
//O Orientation (N:1, E:2, S:3, O:4) 
//L Niveau du joueur ou de l’incantation 
//e Numéro d’œuf sur le serveur 

//T Unité de temps
//N Nom de l’équipe
//R Résultat de l’incantation
//M Message
//i Numéro de ressource

