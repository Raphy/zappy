/* 
 * File:   IObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:34 PM
 */

#ifndef INODEOBJECT_HH
#define	INODEOBJECT_HH

#include <irrlicht.h>
#include "Helper.hh"
#include "IObject.hh"

using namespace irr;

class INodeObject : public IObject
{
public:
    virtual ~INodeObject() {}

    virtual scene::ISceneManager*   getSceneManager() const = 0;
    virtual scene::ISceneNode*	    getNode() const = 0;
    virtual INodeObject*	    getParent() const = 0;
    virtual scene::ISceneNode*	    getParentNode() const = 0;

    virtual void		    setPositionInMap(posi_t const& new_pos) = 0;
    virtual posi_t const&	    getPositionInMap() const = 0;    
    virtual void		    updateNodePosition() = 0;
    
    virtual bool    operator==(const scene::ISceneNode * node) const = 0;
    virtual bool    operator==(INodeObject const* other) const = 0;
};

#endif	/* INODEOBJECT_HH */

