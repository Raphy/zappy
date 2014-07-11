/* 
 * File:   AAnimatedMeshObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 11:03 PM
 */

#ifndef AANIMATEDMESHOBJECT_HH
#define	AANIMATEDMESHOBJECT_HH

#include "AMeshObject.hh"

class AAnimatedMeshObject : public AMeshObject
{
public:
    scene::IAnimatedMeshSceneNode*  getAnimatedMeshNode() const;
protected:
    AAnimatedMeshObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    AAnimatedMeshObject(AAnimatedMeshObject const& orig);
    virtual ~AAnimatedMeshObject();

};

#endif	/* AANIMATEDMESHOBJECT_HH */

