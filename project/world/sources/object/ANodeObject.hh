/* 
 * File:   AObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:36 PM
 */

#ifndef ANODEOBJECT_HH
#define	ANODEOBJECT_HH

#include <irrlicht.h>
#include "INodeObject.hh"
#include "Binder.hh"
#include "Assets.hh"

using namespace irr;

class ANodeObject : public INodeObject
{
public:
    virtual bool    init();
    virtual bool    update();

    INodeObject*		getParent() const;
    scene::ISceneNode*		getParentNode() const;
    scene::ISceneManager*	getSceneManager() const;
    scene::ISceneNode*		getNode() const;

    void			setPositionInMap(posi_t const& new_pos);
    posi_t const&		getPositionInMap() const;    
    virtual void		updateNodePosition();
    virtual void		scaleOnCase();
    
protected:
    ANodeObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    ANodeObject(const ANodeObject& orig);
    virtual ~ANodeObject();
    
    Helper*		    _helper;
    Assets*		    _assets;
    scene::ISceneManager*   _smgr;    
    ANodeObject*	    _parent;
    scene::ISceneNode*	    _node;
    posi_t		    _pos;
    posi_t		    _alignment;
    core::vector3df	    _scale;
};

#endif	/* AOBJECT_HH */

