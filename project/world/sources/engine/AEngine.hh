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
#include "Binder.hh"
#include "IThread.hh"
#include "ISafeQueue.hh"

using namespace irr;

class AEngine : public IEngine
{
public:
    virtual ~AEngine();

    virtual bool init();
    virtual bool update();
    virtual bool mainLoop();
    
    virtual bool callHandler(void * data);
 
protected:
    AEngine();

    IrrlichtDevice*	    _device;
    video::IVideoDriver*    _driver;
    scene::ISceneManager*   _smgr;
    gui::IGUIEnvironment*   _env;
    io::IFileSystem*	    _fs;

//    SAppContext		    _context;
    IEventReceiver*	    _eventReceiver;    

    gui::IGUIElement*	    _mapViewer;
    
    Binder*		    _binder;
    IThread*		    _networkThread;
    ISafeQueue<void *>*	    _eventQueue;
};

#endif	/* AENGINE_HH */

