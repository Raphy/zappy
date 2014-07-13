/* 
 * File:   AAnimatedMeshObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 11:03 PM
 */

#include "AAnimatedMeshObject.hh"

using namespace scene;

AAnimatedMeshObject::AAnimatedMeshObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AMeshObject(smgr, parent, pos)
{
}
//AAnimatedMeshObject::AAnimatedMeshObject(AAnimatedMeshObject const& orig)
//: AMeshObject(static_cast<AMeshObject const&>(orig))
//{
//}
AAnimatedMeshObject::~AAnimatedMeshObject()
{
}

scene::IAnimatedMeshSceneNode*  AAnimatedMeshObject::getAnimatedMeshNode() const
{
    return static_cast<scene::IAnimatedMeshSceneNode*>(_node);
}


struct AAnimatedMeshObject::_animInfo
{
    scene::EMD2_ANIMATION_TYPE  type;
    AnimationRepeatFlag	    flag;
    s32 startFrame;
    s32 endFrame;
    
    _animInfo(IAnimatedMeshSceneNode* node, scene::EMD2_ANIMATION_TYPE type,
		AnimationRepeatFlag flag, f32 endFrame);
};

AAnimatedMeshObject::_animInfo::_animInfo(IAnimatedMeshSceneNode* node,
	scene::EMD2_ANIMATION_TYPE type, AnimationRepeatFlag flag, f32 endFr)
: type(type), flag(flag)
{
    assert(node);
    startFrame = node->getFrameNr();
    endFrame = (flag == REPEAT_UNTIL_FRAME) ? (endFr) : (node->getEndFrame());
}


bool AAnimatedMeshObject::update()
{
    if (_anims.empty())
	return true;
    _animInfo current = _anims.top();
    if ((current.flag == REPEAT_UNTIL_FRAME || current.flag == ONCE)
	    && getAnimatedMeshNode()->getFrameNr() >= current.endFrame)
	return _stopAnim();
    return true;
}

bool AAnimatedMeshObject::startNewAnim(const scene::EMD2_ANIMATION_TYPE& type,
	AnimationRepeatFlag flag, f32 endFrame)
{
    if (flag == REPEAT_UNTIL_FRAME)
	assert(endFrame != 0);
    IAnimatedMeshSceneNode* node = getAnimatedMeshNode();
    _animInfo newAnim(node, type, flag, endFrame);
    node->setMD2Animation(type);
    node->setLoopMode(flag != ONCE);
    _anims.push(newAnim);
    return true;
}
bool AAnimatedMeshObject::stopLastAnim()
{
    assert(_anims.size() > 1);
    assert(_anims.top().flag == REPEAT_UNTIL_STOP_CALL);
    return _stopAnim();
}

bool AAnimatedMeshObject::_startAnim()
{
    return true;
}
bool AAnimatedMeshObject::_stopAnim()
{
    IAnimatedMeshSceneNode* node = getAnimatedMeshNode();
    _anims.pop();
    _animInfo last = _anims.top();
    node->setMD2Animation(last.type);
    node->setLoopMode(last.flag != ONCE);
    return true;
}
