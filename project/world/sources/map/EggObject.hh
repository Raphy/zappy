/* 
 * File:   EggObject.hh
 * Author: marie
 *
 * Created on July 8, 2014, 10:01 PM
 */

#ifndef EGGOBJECT_HH
#define	EGGOBJECT_HH

#include    "AMeshObject.hh"
#include    "AGameElement.hh"

class EggObject : public AGameElement, public AMeshObject
{
public:
    EggObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    EggObject(const EggObject& orig);
    virtual ~EggObject();

    bool    init();
private:

};

#endif	/* EGGOBJECT_HH */

