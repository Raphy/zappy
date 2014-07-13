/* 
 * File:   MyEventReceiver.cpp
 * Author: marie
 * 
 * Created on July 7, 2014, 12:21 AM
 */

#include <iostream>
#include "MyEventReceiver.hh"
#include "IEngine.hh"

using namespace irr;
using namespace scene;

typedef std::pair<irr::EEVENT_TYPE, eventReceivers_t> receiverPair;
typedef std::map<irr::EEVENT_TYPE, eventReceivers_t> receiverMap;

MyEventReceiver::MyEventReceiver(EventContext const& context)
{
    _context.device = context.device;
    _context.engine = context.engine;
    _context.smgr = context.device->getSceneManager();
    _receivers.insert(receiverPair(irr::EET_MOUSE_INPUT_EVENT, &MyEventReceiver::OnMouseEvent));
    _receivers.insert(receiverPair(irr::EET_KEY_INPUT_EVENT, &MyEventReceiver::OnKeyboardEvent));
    _receivers.insert(receiverPair(irr::EET_LOG_TEXT_EVENT, &MyEventReceiver::OnLogEvent));
    _receivers.insert(receiverPair(irr::EET_GUI_EVENT, &MyEventReceiver::OnGUIEvent));
}

MyEventReceiver::~MyEventReceiver()
{
}

bool MyEventReceiver::OnEvent(const SEvent& event)
{
    receiverMap::iterator it = _receivers.find(event.EventType);
    if (it != _receivers.end())
    {
	_event = event;
	return (this->*(_receivers[event.EventType]))();
    }
    return false;
}

bool MyEventReceiver::OnMouseEvent()
{
    if (_event.MouseInput.isLeftPressed())
    {
	scene::ISceneCollisionManager* pCollisionMgn = (_context.smgr)->getSceneCollisionManager();
	if (pCollisionMgn)
	{
	    core::line3d<f32> ray = pCollisionMgn->getRayFromScreenCoordinates(
		    core::position2d<s32>(_event.MouseInput.X, _event.MouseInput.Y), 
		    _context.smgr->getActiveCamera());
	    ISceneNode* node = pCollisionMgn->getSceneNodeFromRayBB(ray, 0, false/*, nullptr*/);
	    if (node)
	    {
		_context.engine->setLastNodeClicked(node);
		return false;//true sauf si on est en mode gui
	    }
	    
	}
    }
    return false;
}
bool MyEventReceiver::OnKeyboardEvent()
{
    if (_event.KeyInput.PressedDown)
	switch (_event.KeyInput.Key)
	{
	    case irr::KEY_F3:
		//TODO : faire ça proprement
		if (_context.engine->getCameraMode() == GUI_ID_MENU_CAMERA_FPS_BUTTON)
		    _context.engine->setCameraMode(GUI_ID_MENU_CAMERA_CLASSIC_BUTTON);
		else
		    _context.engine->setCameraMode(GUI_ID_MENU_CAMERA_FPS_BUTTON);
		//	bool enabled = camera->isInputReceiverEnabled();
		//	camera->setInputReceaiverEnabled(!enabled);
		//	device->getCursorControl()->setVisible(enabled);
		return true;
	    default:
		break;
	}
	return false;
}
bool MyEventReceiver::OnLogEvent()
{
    return true;
}
bool MyEventReceiver::OnGUIEvent()
{
    // we check for log message like "Resizing window (640 480)"
    //    string b = "Resizing window (";
    //    string s = evnt.Log.Text;
    //    if (s.StartsWith(b))
    //    {
    //	s = s.Substring(b.Length, s.Length - b.Length - 1);
    //	string[] v = s.Split(' ');
    //	int w = int.Parse(v[0]);
    //	int h = int.Parse(v[1]);
    //	// HERE WE KNOW THAT WINDOW HAS BEEN RESIZED TO w x h
    //    }
    return false;
}
