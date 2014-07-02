/* 
 * File:   IObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 8:34 PM
 */

#ifndef IOBJECT_HH
#define	IOBJECT_HH

#include <irrlicht.h>

using namespace irr;

class IObject
{
public:
    virtual ~IObject() {}
    
    virtual bool    init() = 0;
    virtual bool    update() = 0;

    virtual scene::ISceneManager*   getSceneManager() const = 0;
    virtual scene::ISceneNode*	    getNode() const = 0;
    virtual IObject*		    getParent() const = 0;
    virtual scene::ISceneNode*	    getParentNode() const = 0;
};

#endif	/* IOBJECT_HH */

