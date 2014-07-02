/* 
 * File:   PersoObject.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:57 PM
 */

#ifndef PERSOOBJECT_HH
#define	PERSOOBJECT_HH

#include    "AAnimatedMeshObject.hh"
#include    "AGameElement.hh"

class PersoObject : public AGameElement, public AAnimatedMeshObject
{
public:
    PersoObject(scene::ISceneManager* smgr, IObject* parent);
    PersoObject(const PersoObject& orig);
    virtual ~PersoObject();

    bool    init();
private:

};

#endif	/* PERSOOBJECT_HH */

