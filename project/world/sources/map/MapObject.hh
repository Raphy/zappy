/* 
 * File:   MapObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:34 PM
 */

#ifndef MAPOBJECT_HH
#define	MAPOBJECT_HH

#include "AAnimatedMeshObject.hh"

class MapObject : public AAnimatedMeshObject
{
public:
    MapObject(scene::ISceneManager* smgr, IObject* parent);
    MapObject(const MapObject& orig);
    virtual ~MapObject();
    
    bool    init();
private:

};

#endif	/* MAPOBJECT_HH */

