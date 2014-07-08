/* 
 * File:   RessourceObject.hh
 * Author: marie
 *
 * Created on July 8, 2014, 6:47 PM
 */

#ifndef RESSOURCEOBJECT_HH
#define	RESSOURCEOBJECT_HH

#include    "AMeshObject.hh"
#include    "AGameElement.hh"

class RessourceObject : public AGameElement, public AMeshObject
{
public:
    RessourceObject(scene::ISceneManager* smgr, INodeObject* parent);
    RessourceObject(const RessourceObject& orig);
    virtual ~RessourceObject();

    bool    init();
private:

};

#endif	/* RESSOURCEOBJECT_HH */

