/* 
 * File:   AObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:36 PM
 */

#ifndef ANODEOBJECT_HH
#define	ANODEOBJECT_HH

#include <irrlicht.h>
#include <utility>
#include "INodeObject.hh"
#include "Binder.hh"
#include "Assets.hh"

using namespace irr;

class ANodeObject : public INodeObject
{
public:
    virtual bool    init();
    virtual bool    update();

    INodeObject*		getParent() const { return _parent; }
    scene::ISceneNode*		getParentNode() const { return ((_parent) ? (_parent->getNode()) : (_smgr->getRootSceneNode())); }
    scene::ISceneManager*	getSceneManager() const { return _smgr; }
    scene::ISceneNode*		getNode() const { return _node; }

    void			setPositionInMap(posi_t const& new_pos);
    posi_t const&		getPositionInMap() const;    
    void			updateNodePosition();
    void			scaleOnCase();
    
protected:
    ANodeObject(scene::ISceneManager* smgr, INodeObject* parent);
    ANodeObject(const ANodeObject& orig);
    virtual ~ANodeObject();
    
    Binder*		    _binder;
    Assets*		    _assets;
    scene::ISceneManager*   _smgr;    
    INodeObject*	    _parent;
    scene::ISceneNode*	    _node;  
    posi_t		    _pos;
    posi_t		    _alignment;
};

#endif	/* AOBJECT_HH */

