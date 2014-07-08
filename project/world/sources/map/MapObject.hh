/* 
 * File:   MapObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:34 PM
 */

#ifndef MAPOBJECT_HH
#define	MAPOBJECT_HH

#include <list>
#include "AAnimatedMeshObject.hh"
#include "INetworkEventHandler.hh"

class MapObject : public AAnimatedMeshObject, INetworkEventHandler
{
public:
    MapObject(scene::ISceneManager* smgr, INodeObject* parent);
    MapObject(const MapObject& orig);
    virtual ~MapObject();

    scene::ITriangleSelector* getSelector() const { return _selector; }

    bool    init();
    bool    callHandler(t_data * data);

    /* HANDLERS */

    bool    createGround(int x, int y);
//    bool    setCaseContent(int x, int y, std::vector<int> const& quantity);
//    bool    addPlayer(int x, int y, int n, int o, int level, std::string const& team);
//
    bool    addObject(int x, int y, GameElementType type);

private:

    scene::ITriangleSelector*	_selector;
    std::list<INodeObject*>		_persos;
    std::list<INodeObject*>		_objects;
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

