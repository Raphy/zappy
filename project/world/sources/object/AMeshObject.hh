/* 
 * File:   AMeshObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 9:37 PM
 */

#ifndef AMESHOBJECT_HH
#define	AMESHOBJECT_HH

#include "ANodeObject.hh"

class AMeshObject : public ANodeObject
{
public:
    scene::IMeshSceneNode*  getMeshNode() const;

protected:
    AMeshObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    AMeshObject(const AMeshObject& orig);
    virtual ~AMeshObject();

};

#endif	/* AMESHOBJECT_HH */

