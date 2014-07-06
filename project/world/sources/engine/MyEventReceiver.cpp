/* 
 * File:   MyEventReceiver.cpp
 * Author: marie
 * 
 * Created on July 7, 2014, 12:21 AM
 */

#include "MyEventReceiver.hh"

using namespace irr;

MyEventReceiver::MyEventReceiver(EventContext context)
: _context(context)
{
}

MyEventReceiver::~MyEventReceiver()
{
}

bool MyEventReceiver::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_LOG_TEXT_EVENT)
	return true;
    return false;
}
