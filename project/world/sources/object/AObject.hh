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
#include "Binder.hh"
#include "Ressources.hh"

using namespace irr;

class AObject : public IObject
{
public:
    virtual bool    init();
    virtual bool    update();

    IObject*			getParent() const { return _parent; }
    scene::ISceneNode*		getParentNode() const { return ((_parent) ? (_parent->getNode()) : (_smgr->getRootSceneNode())); }
    scene::ISceneManager*	getSceneManager() const { return _smgr; }
    scene::ISceneNode*		getNode() const { return _node; }
	
protected:
    AObject(scene::ISceneManager* smgr, IObject* parent);
    AObject(const AObject& orig);
    virtual ~AObject();
    
    Binder*		    _binder;
    Ressources*		    _ressources;
    scene::ISceneManager*   _smgr;    
    IObject*		    _parent;
    scene::ISceneNode*	    _node;  
};

#endif	/* AOBJECT_HH */

