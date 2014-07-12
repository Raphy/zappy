/* 
 * File:   IEngine.hh
 * Author: marie
 *
 * Created on June 30, 2014, 12:50 PM
 */

#ifndef IENGINE_HH
#define	IENGINE_HH

#include <irrlicht.h>
#include "IObject.h"
#include "INetworkEventHandler.hh"
#include "enums.hh"

class IEngine : public IObject, public INetworkEventHandler
{
public:
    virtual ~IEngine() {}

    virtual bool mainLoop() = 0;

    virtual irr::IrrlichtDevice* getDevice() const = 0;
    

    virtual bool    connectedHandler(t_infos * infos) = 0;

    
    virtual bool setCameraMode(Ids id) = 0;
    virtual bool setTheme(Ids id) = 0;
    virtual bool setTimeUnit(int value) = 0;
    virtual bool setVolume(int value) = 0;
    virtual bool setMuteStatus(bool mute) = 0;

    virtual Ids getCameraMode() const = 0;
    virtual Ids getTheme() const = 0;
    virtual int getTimeUnit() const = 0;
    virtual int getVolume() const = 0;
    virtual bool getMuteStatus() const = 0;
};

//typedef bool (IEngine::*engine_handler_t)(t_infos *);

#endif	/* IENGINE_HH */

