/* 
 * File:   AAnimatedMeshObject.hh
 * Author: marie
 *
 * Created on June 30, 2014, 11:03 PM
 */

#ifndef AANIMATEDMESHOBJECT_HH
#define	AANIMATEDMESHOBJECT_HH

#include <stack>
#include "AMeshObject.hh"

enum AnimationRepeatFlag
{
    REPEAT,
    REPEAT_UNTIL_FRAME,
    REPEAT_UNTIL_STOP_CALL,
    ONCE
};

class AAnimatedMeshObject : public AMeshObject
{
public:
    scene::IAnimatedMeshSceneNode*  getAnimatedMeshNode() const;
    
    bool    update();
    
protected:
    AAnimatedMeshObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
    //    AAnimatedMeshObject(AAnimatedMeshObject const& orig);
    virtual ~AAnimatedMeshObject();
    
    bool    startNewAnim(scene::EMD2_ANIMATION_TYPE const& type, AnimationRepeatFlag flag,
		f32 endFrame = 0);
    //    bool    pushNextAnim(scene::EMD2_ANIMATION_TYPE const& type, AnimationRepeatFlag flag);
    bool    stopLastAnim();
    
private:
    struct _animInfo;
    
    bool    _startAnim();
    bool    _stopAnim();
    
    std::stack<_animInfo>	_anims;
};

#endif	/* AANIMATEDMESHOBJECT_HH */

