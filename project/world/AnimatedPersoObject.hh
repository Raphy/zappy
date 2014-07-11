/* 
 * File:   PersoObject.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:57 PM
 */

#ifndef ANIMATED_PERSOOBJECT_HH
#define	ANIMATED_PERSOOBJECT_HH

#include    "AAnimatedMeshObject.hh"
#include    "AGameElement.hh"

class AnimatedPersoObject : public AGameElement, public AAnimatedMeshObject
{
public:
    AnimatedPersoObject(scene::ISceneManager* smgr, INodeObject* parent);
    AnimatedPersoObject(const AnimatedPersoObject& orig);
    virtual ~AnimatedPersoObject();

    bool    init();
private:

};

#endif	/* ANIMATED_PERSOOBJECT_HH */

