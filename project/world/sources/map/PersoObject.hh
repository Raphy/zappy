/* 
 * File:   PersoObject.hh
 * Author: marie
 *
 * Created on July 5, 2014, 8:16 PM
 */

#ifndef PERSOOBJECT_HH
#define	PERSOOBJECT_HH

#include    "AMeshObject.hh"
#include    "AGameElement.hh"

class PersoObject : public AGameElement, public AMeshObject
{
public:
    PersoObject(scene::ISceneManager* smgr, IObject* parent);
    PersoObject(const PersoObject& orig);
    virtual ~PersoObject();

    bool    init();
private:

};

#endif	/* PERSOOBJECT_HH */

