/* 
 * File:   AObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:36 PM
 */

#ifndef AOBJECT_HH
#define	AOBJECT_HH

#include <irrlicht.h>
#include "IObject.hh"

using namespace irr;

class AObject : public IObject
{
public:
    virtual bool    init();
    virtual bool    update();

    IObject*			getParent() const { return _parent; }
    scene::ISceneManager*	getSceneManager() const { return _smgr; }
    scene::ISceneNode*		getNode() const { return _node; }
	
protected:
    AObject(scene::ISceneManager* smgr, IObject* parent);
    AObject(const AObject& orig);
    virtual ~AObject();
    
    IObject*		    _parent;
    scene::ISceneManager*   _smgr;    
    scene::ISceneNode*	    _node;  
};

#endif	/* AOBJECT_HH */

