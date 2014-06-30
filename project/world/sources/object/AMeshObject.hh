/* 
 * File:   AMeshObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 9:37 PM
 */

#ifndef AMESHOBJECT_HH
#define	AMESHOBJECT_HH

#include "AObject.hh"

class AMeshObject : public AObject
{
public:
    scene::IMeshSceneNode*  getMeshNode() const;

protected:
    AMeshObject(scene::ISceneManager* smgr, IObject* parent);
    AMeshObject(const AMeshObject& orig);
    virtual ~AMeshObject();

};

#endif	/* AMESHOBJECT_HH */

