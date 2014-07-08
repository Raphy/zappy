/* 
 * File:   MyEventReceiver.cpp
 * Author: marie
 * 
 * Created on July 7, 2014, 12:21 AM
 */

#include "MyEventReceiver.hh"
#include "IEngine.hh"

using namespace irr;

MyEventReceiver::MyEventReceiver(EventContext const& context)
{
    _context.device = context.device;
    _context.engine = context.engine;
}

MyEventReceiver::~MyEventReceiver()
{
}

bool MyEventReceiver::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_LOG_TEXT_EVENT)
	return true;
    else if (event.KeyInput.Key == irr::KEY_F3 && event.KeyInput.PressedDown)
    {
	//TODO : faire ça proprement
	if (_context.engine->getCameraMode() == GUI_ID_MENU_CAMERA_FPS_BUTTON)
	    _context.engine->setCameraMode(GUI_ID_MENU_CAMERA_CLASSIC_BUTTON);
	else
	    _context.engine->setCameraMode(GUI_ID_MENU_CAMERA_FPS_BUTTON);
//	bool enabled = camera->isInputReceiverEnabled();
//	camera->setInputReceaiverEnabled(!enabled);
//	device->getCursorControl()->setVisible(enabled);
    }
    return false;
}
