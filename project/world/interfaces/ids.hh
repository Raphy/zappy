/* 
 * File:   ids.hh
 * Author: marie
 *
 * Created on June 30, 2014, 7:35 PM
 */

#ifndef IDS_HH
#define	IDS_HH

// Define values that will be used to identify individual GUI controls or Scenenodes.
enum Ids
{
    GUI_ID_MAP = 101,

    GUI_ID_MENU,
    GUI_ID_MENU_CAMERA_CHOICE,
    GUI_ID_MENU_CAMERA_FPS_BUTTON,
    GUI_ID_MENU_CAMERA_MAYA_BUTTON,// gerer avec des raccourcis a la place? ou les 2?
    GUI_ID_MENU_CAMERA_CLASSIC_BUTTON,
    GUI_ID_MENU_SOUND_CHOICE,

    GUI_ID_INVENTORY,

    GUI_ID_TEAM_INFO,

    GUI_ID_CHAT_EVENT,

    GUI_ID_DETAILS,

    
    NODE_ID_MAP = 201,
    NODE_ID_PERSO,
    NODE_ID_FOOD,
    NODE_ID_STONE,
    NODE_ID_CASE,
};

//enum du tuto
//{
//    GUI_ID_QUIT_BUTTON = 101,
//    GUI_ID_NEW_WINDOW_BUTTON,
//    GUI_ID_FILE_OPEN_BUTTON,
//    GUI_ID_TRANSPARENCY_SCROLL_BAR
//};

#endif	/* IDS_HH */

