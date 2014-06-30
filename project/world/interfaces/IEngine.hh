/* 
 * File:   IEngine.hh
 * Author: marie
 *
 * Created on June 30, 2014, 12:50 PM
 */

#ifndef IENGINE_HH
#define	IENGINE_HH

class IEngine
{
public:
    virtual ~IEngine() {}
    
    virtual bool init() = 0;
    virtual bool update() = 0;
    virtual bool mainLoop() = 0;
};

#endif	/* IENGINE_HH */

