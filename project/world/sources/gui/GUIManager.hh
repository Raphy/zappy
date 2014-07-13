/* 
 * File:   GUIManager.hh
 * Author: marie
 *
 * Created on July 8, 2014, 2:23 PM
 */

#ifndef GUIMANAGER_HH
#define	GUIMANAGER_HH

#include    <irrlicht.h>
#include    "INodeObject.hh"
//#include    "Compass.hh"

using namespace irr;

class IEngine;

class GUIManager : public IObject
{
public:
    GUIManager(gui::IGUIEnvironment* env, IEngine* engine, posi_t const& winSize);
    GUIManager(const GUIManager& orig);
    virtual ~GUIManager();
    
    bool    	init();
    bool    	update();
    
    void resize();
//    void updateDirection(f32 angle);
    void updateTeamsViewer();
    void updateNodeInformation(INodeObject const* lastNodeClicked);
private:
    gui::IGUIEnvironment*   _env;
    video::IVideoDriver*    _driver;
    IEngine*		    _engine;
    unsigned int _x;
    unsigned int _y;
    
    gui::IGUIListBox*	_information;
    gui::IGUIWindow*	_help;
    gui::IGUIListBox*	_menu;
    gui::IGUIComboBox*	_camera;
//    gui::IGUIListBox*	_teams;
    gui::IGUITable*	_teamTable;
    core::recti		_rectZero;
};

#endif	/* GUIMANAGER_HH */

