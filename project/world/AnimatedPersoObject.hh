/* 
 * File:   PlayerObject.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:57 PM
 */

#ifndef ANIMATED_PLAYEROBJECT_HH
#define	ANIMATED_PLAYEROBJECT_HH

#include    "AAnimatedMeshObject.hh"
#include    "AGameElement.hh"

class AnimatedPlayerObject : public AGameElement, public AAnimatedMeshObject
{
public:
    AnimatedPlayerObject(scene::ISceneManager* smgr, INodeObject* parent);
    AnimatedPlayerObject(const AnimatedPlayerObject& orig);
    virtual ~AnimatedPlayerObject();

    bool    init();
private:

};

#endif	/* ANIMATED_PLAYEROBJECT_HH */

