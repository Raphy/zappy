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

using namespace scene;//cpp

class AAnimatedMeshObject : public AMeshObject
{
public:
    scene::IAnimatedMeshSceneNode*  getAnimatedMeshNode() const;
    
    bool    update()
    {
	if (_anims.empty())
	    return true;
	_animInfo current = _anims.top();
	if (current.flag == REPEAT_UNTIL_FRAME
		&& getAnimatedMeshNode()->getFrameNr() >= current.endFrame)
	    return stopLastAnim();
	return true;
    }
    
protected:
    AAnimatedMeshObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
    //    AAnimatedMeshObject(AAnimatedMeshObject const& orig);
    virtual ~AAnimatedMeshObject();
    
    bool    startNewAnim(scene::EMD2_ANIMATION_TYPE const& type, AnimationRepeatFlag flag)
    {
	_animInfo newAnim(getAnimatedMeshNode(), type, flag);
	IAnimatedMeshSceneNode* node = getAnimatedMeshNode();
	node->setMD2Animation(type);
	node->setLoopMode(flag == ONCE);	
	_anims.push(newAnim);
	return true;
    }
    //    bool    pushNextAnim(scene::EMD2_ANIMATION_TYPE const& type, AnimationRepeatFlag flag);
    bool    stopLastAnim()
    {
	assert(_anims.size() > 1);
	assert(_anims.top().flag == REPEAT_UNTIL_STOP_CALL);
	_anims.pop();
	_animInfo last = _anims.top();
	IAnimatedMeshSceneNode* node = getAnimatedMeshNode();
	node->setMD2Animation(last.type);
	node->setLoopMode(last.flag == ONCE);
	return true;
    }
    
private:
    struct _animInfo
    {
	scene::EMD2_ANIMATION_TYPE  type;
	AnimationRepeatFlag	    flag;
	s32 startFrame;
	s32 endFrame;
	
	_animInfo(IAnimatedMeshSceneNode* node, scene::EMD2_ANIMATION_TYPE type, AnimationRepeatFlag flag)
	: type(type), flag(flag)
	{
	    assert(node);
	    startFrame = node->getFrameNr();
	    endFrame = node->getEndFrame();
	}
    };
    
    std::stack<_animInfo>	_anims;
};

#endif	/* AANIMATEDMESHOBJECT_HH */

