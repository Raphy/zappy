/* 
 * File:   MyEventReceiver.hh
 * Author: marie
 *
 * Created on July 7, 2014, 12:21 AM
 */

#ifndef MYEVENTRECEIVER_HH
#define	MYEVENTRECEIVER_HH

#include <irrlicht.h>
#include "enums.hh"

class MyEventReceiver : public irr::IEventReceiver
{
public:
    MyEventReceiver(EventContext const& context);
    virtual ~MyEventReceiver();

    virtual bool OnEvent(const irr::SEvent& event);

private:
    EventContext _context;
};

#endif	/* MYEVENTRECEIVER_HH */

