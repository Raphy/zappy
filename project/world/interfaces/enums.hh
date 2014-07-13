/* 
 * File:   ids.hh
 * Author: marie
 *
 * Created on June 30, 2014, 7:35 PM
 */

#ifndef IDS_HH
#define	IDS_HH

#include    <irrlicht.h>

class IEngine;

enum	Orientation
{
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};

enum	RessourceType
{
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    RESSOURCE_TYPE_COUNT
};

enum	GameElementType
{
    RESSOURCE = 0,//pour avoir la texture
    PLAYER,
    EGG,
    CASE,
    MAP,
    SKYBOX,
    BROADCAST,
    INVOCATION,
    GAME_ELEMENT_TYPE_COUNT,
};

//enum CameraMode
//{
//    MODE_FPS = 0,
//    MODE_CLASSIC,
//    CAMERA_MODE_COUNT
//};

// Define values that will be used to identify individual GUI controls or Scenenodes.
enum Ids
{
    GUI_ID_MAP = 101,
    
    GUI_ID_COMPASS,
    GUI_ID_HELP,
    
    GUI_ID_MENU,

    GUI_ID_MENU_CAMERA_CHOICE,
    GUI_ID_MENU_CAMERA_FPS_BUTTON,
    GUI_ID_MENU_CAMERA_CLASSIC_BUTTON,

    GUI_ID_MENU_SOUND_CHOICE,
    
    GUI_ID_INFORMATION,
    
    GUI_ID_TEAM_INFO,
    
    GUI_ID_CHAT_EVENT,
    
    GUI_ID_DETAILS,
    
    GUI_ID_UNDEFINED,
    
    
    NODE_ID_MAP = 201,
    NODE_ID_CASE,
    NODE_ID_PLAYER,
    NODE_ID_EGG,
    NODE_ID_RESSOURCE,
    NODE_ID_BROADCAST,
    NODE_ID_INVOCATION,
};

//class EnumManager
//{
//    static  Ids CameraModeToId(CameraMode mode);
//    static  CameraMode IdToCameraMode(Ids ids);
//};

//Ids CameraManager::CameraModeToId(CameraMode mode)
//{
//    Ids id;
//    switch (mode)
//    {
//	case FPS:
//	    id = GUI_ID_MENU_CAMERA_FPS_BUTTON;
//	    break;
//	case STATIC:
//	    id = GUI_ID_MENU_CAMERA_CLASSIC_BUTTON;
//	    break;
//	default:
//	    id = GUI_ID_MENU_CAMERA_CLASSIC_BUTTON;
//	    break;
//    }
//    return id;
//}
//
//CameraMode CameraManager::IdToCameraMode(Ids ids)
//{
//    (void)ids;
//    //TODO
//    return STATIC;
//}

#endif	/* IDS_HH */

