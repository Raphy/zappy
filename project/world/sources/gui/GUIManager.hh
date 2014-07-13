/* 
 * File:   GUIManager.hh
 * Author: marie
 *
 * Created on July 8, 2014, 2:23 PM
 */

#ifndef GUIMANAGER_HH
#define	GUIMANAGER_HH

#include    <irrlicht.h>
#include    <map>
#include    "INodeObject.hh"
//#include    "Compass.hh"

using namespace irr;

class IEngine;
class GUIManager;

typedef	void (GUIManager::*displayObjInfo_t)(INodeObject const* obj);

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
    bool updateNodeInformation(INodeObject const* lastNodeClicked);
    
private:
    void displayPlayerInfo(INodeObject const* obj);
    void displayEggInfo(INodeObject const* obj);
    void displayRessourceInfo(INodeObject const* obj);
    void displayCaseInfo(INodeObject const* obj);
    
    gui::IGUIEnvironment*   _env;
    video::IVideoDriver*    _driver;
    IEngine*		    _engine;
    unsigned int _x;
    unsigned int _y;
    core::recti		_rectZero;
    
    gui::IGUIWindow*	_help;
    gui::IGUIListBox*	_menu;
    gui::IGUIComboBox*	_camera;

    gui::IGUITable*	_teamTable;

    gui::IGUIListBox*	_information;
    INodeObject const*	_currentObj;
    std::map<Ids, displayObjInfo_t> _objDisplayers;
};

#endif	/* GUIMANAGER_HH */

