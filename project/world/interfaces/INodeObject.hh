/* 
 * File:   IObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:34 PM
 */

#ifndef INODEOBJECT_HH
#define	INODEOBJECT_HH

#include <irrlicht.h>

using namespace irr;

class INodeObject
{
public:
    virtual ~INodeObject() {}
    
    virtual bool    init() = 0;
    virtual bool    update() = 0;

    virtual scene::ISceneManager*   getSceneManager() const = 0;
    virtual scene::ISceneNode*	    getNode() const = 0;
    virtual INodeObject*	    getParent() const = 0;
    virtual scene::ISceneNode*	    getParentNode() const = 0;
};

#endif	/* INODEOBJECT_HH */
