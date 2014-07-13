/* 
 * File:   MyEventReceiver.hh
 * Author: marie
 *
 * Created on July 7, 2014, 12:21 AM
 */

#ifndef MYEVENTRECEIVER_HH
#define	MYEVENTRECEIVER_HH

#include <map>
#include <irrlicht.h>
#include "enums.hh"

// data structure for the EventReceiver
struct EventContext
{
    irr::IrrlichtDevice*	    device;
    IEngine*			    engine;
    irr::scene::ISceneManager*	    smgr;
    //...
};

class MyEventReceiver;

typedef bool (MyEventReceiver::*eventReceivers_t)();

class MyEventReceiver : public irr::IEventReceiver
{
public:
    MyEventReceiver(EventContext const& context);
    virtual ~MyEventReceiver();

    virtual bool OnEvent(const irr::SEvent& event);

private:
    bool OnMouseEvent();
    bool OnKeyboardEvent();
    bool OnLogEvent();
    bool OnGUIEvent();

    irr::SEvent	    _event;
    EventContext    _context;
    std::map<irr::EEVENT_TYPE, eventReceivers_t>    _receivers;
};

#endif	/* MYEVENTRECEIVER_HH */

