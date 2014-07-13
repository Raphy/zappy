/* 
 * File:   IObject.h
 * Author: marie
 *
 * Created on July 12, 2014, 1:52 AM
 */

#ifndef IOBJECT_H
#define	IOBJECT_H

class	IObject
{
public:
    virtual bool    init() = 0;
    virtual bool    update() = 0;
};

#endif	/* IOBJECT_H */

