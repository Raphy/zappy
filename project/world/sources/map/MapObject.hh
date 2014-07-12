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
    bool    update();

    void    updateNodePosition();
    void    scaleOnCase();

    bool    createGround(int x, int y);

    bool    handlerRelay(t_data * data);

    /* HANDLERS */
    bool    mapSizeHandler(t_infos * infos);

private:
    void		applyToAllCases(bool (CaseObject::*f)());
    void		initCases();
    CaseObject*		getCaseObject(posi_t const& pos);// const;
    PlayerObject*	getPlayer(int index);// const;
    
    scene::ITriangleSelector*		    _selector;
    std::vector<std::vector<CaseObject*>>   _cases;
    posi_t				    _mapSize;
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

