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
    MapObject(scene::ISceneManager* smgr, IObject* parent);
    MapObject(const MapObject& orig);
    virtual ~MapObject();

    bool    callHandler(t_data * data);
    
    bool    init();
private:
    std::list<IObject*>  _persos;
};

#endif	/* MAPOBJECT_HH */

