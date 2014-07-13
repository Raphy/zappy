/* 
 * File:   AEngine.hh
 * Author: marie
 *
 * Created on June 30, 2014, 12:54 PM
 */

#ifndef AENGINE_HH
#define	AENGINE_HH

#include <irrlicht.h>
#include "IEngine.hh"
#include "Helper.hh"
#include "Assets.hh"
#include "IThread.hh"
#include "ISafeQueue.hh"
#include "MapViewer.hh"
#include "GUIManager.hh"

using namespace irr;

class AEngine : public IEngine
{
public:
    virtual ~AEngine();
    
    virtual bool init();
    virtual bool update();
    virtual bool mainLoop();
    
    virtual irr::IrrlichtDevice* getDevice() const;
    
    virtual bool handlerRelay(t_data * data);
    //    virtual bool handlerRelayCreateMap(int x, int y);//VERSION SIMPLE
    virtual void sendCommand(t_data * data);
    
    /* HANDLERS */
    bool    connectedHandler(t_infos * infos)
    {
	(void)infos;
	std::cout << "Successful connection to server !" << std::endl;
	return true;
    }
    bool    disconnectedHandler(t_infos * infos)
    {
	(void)infos;
	std::cout << "Successful disconnection !" << std::endl;
	return true;
    }
    bool    disconnectedHandler(t_infos * infos)
    {
	(void)infos;
	//TODO
	std::cout << "errno !" << std::endl;
	return true;
    }
    
    /* SETTINGS */
    
    virtual void setLastNodeClicked(scene::ISceneNode const* node)//a acceder depuis l'eventReceiver
    {
	MapObject const* mapObj = _mapViewer->getMapObject();
	if (mapObj)
	    _lastNodeClicked = mapObj->getObjectFromNode(node);
    }
    virtual INodeObject const* getLastNodeClicked() const
    {
	return _lastNodeClicked;
    }
    
    virtual bool setCameraMode(Ids id);
    virtual bool setTheme(Ids id);
    virtual bool setTimeUnit(int value);
    virtual bool setVolume(int value);
    virtual bool setMuteStatus(bool mute);
    
    virtual Ids getCameraMode() const;
    virtual Ids getTheme() const;
    virtual int getTimeUnit() const;
    virtual int getVolume() const;
    virtual bool getMuteStatus() const;
    
protected:
    AEngine();
    void updateFPS();
    
    IrrlichtDevice*	    _device;
    video::IVideoDriver*    _driver;
    scene::ISceneManager*   _smgr;
    gui::IGUIEnvironment*   _env;
    io::IFileSystem*	    _fs;
    gui::ICursorControl*    _cursor;
    
    IEventReceiver*	    _eventReceiver;
    GUIManager*		    _guiManager;
    int			    _fps;
    INodeObject*	    _lastNodeClicked;
    
    posi_t		    _winSize;
    MapViewer*		    _mapViewer;
    
    Helper*		    _helper;
    Assets*		    _assets;
    IThread*		    _networkThread;
    ISafeQueue<t_data *>*   _eventQueue;
    ISafeQueue<t_data *>*   _commandQueue;
};

#endif	/* AENGINE_HH */

