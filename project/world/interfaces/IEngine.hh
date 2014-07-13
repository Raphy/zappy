/* 
 * File:   IEngine.hh
 * Author: marie
 *
 * Created on June 30, 2014, 12:50 PM
 */

#ifndef IENGINE_HH
#define	IENGINE_HH

#include <irrlicht.h>
#include "IObject.hh"
#include "INetworkEventHandler.hh"
#include "enums.hh"

using namespace irr;

class INodeObject;

class IEngine : public IObject, public INetworkEventHandler
{
public:
    virtual ~IEngine() {}
    
    virtual bool mainLoop() = 0;
    
    virtual IrrlichtDevice* getDevice() const = 0;
    virtual TeamManager const* getTeamManager() const = 0;
    
    virtual bool    connectedHandler(t_infos * infos) = 0;
    virtual bool    disconnectedHandler(t_infos * infos) = 0;
    virtual bool    errnoHandler(t_infos * infos) = 0;
    
    virtual bool setCameraMode(Ids id) = 0;
    virtual bool setTheme(Ids id) = 0;
    virtual bool setTimeUnit(int value) = 0;
    virtual bool setVolume(int value) = 0;
    virtual bool setMuteStatus(bool mute) = 0;
    virtual void setLastNodeClicked(scene::ISceneNode const* node,
	core::vector3df point = core::vector3df(),
	core::triangle3df triangle = core::triangle3df()) = 0;
    
    virtual Ids getCameraMode() const = 0;
    virtual Ids getTheme() const = 0;
    virtual int getTimeUnit() const = 0;
    virtual int getVolume() const = 0;
    virtual bool getMuteStatus() const = 0;
    virtual INodeObject const* getLastNodeClicked() const = 0;
};

//typedef bool (IEngine::*engine_handler_t)(t_infos *);

#endif	/* IENGINE_HH */

