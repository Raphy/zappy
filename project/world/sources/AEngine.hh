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

using namespace irr;

class AEngine : public IEngine
{
public:
    virtual ~AEngine();

    virtual bool init();
    virtual bool update();
    virtual bool mainLoop();
 
protected:
    AEngine();

    IrrlichtDevice*	    _device;
    video::IVideoDriver*    _driver;
    scene::ISceneManager*   _smgr;
    gui::IGUIEnvironment*   _env;
};

#endif	/* AENGINE_HH */

