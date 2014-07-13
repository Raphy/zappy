/* 
 * File:   EggObject.hh
 * Author: marie
 *
 * Created on July 8, 2014, 10:01 PM
 */

#ifndef EGGOBJECT_HH
#define	EGGOBJECT_HH

#include    "AMeshObject.hh"
#include    "AGameElement.hh"

class EggObject : public AGameElement, public AMeshObject
{
public:
    EggObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    EggObject(const EggObject& orig);
    virtual ~EggObject();

    bool    init();
    bool    update();


    bool    hatchHandler(t_infos * infos)
    {
	(void)infos;
	return true;
    }
    bool    connectedHandler(t_infos * infos)
    {
	(void)infos;
	return true;
    }

    void setIndex(unsigned int _index);
    void setPlayerIndex(unsigned int _playerIndex);
    unsigned int getIndex() const;
    unsigned int getPlayerIndex() const;
    
private:
    unsigned int    _index;
    unsigned int    _playerIndex;
};

#endif	/* EGGOBJECT_HH */

