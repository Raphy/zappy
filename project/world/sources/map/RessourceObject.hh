/* 
 * File:   RessourceObject.hh
 * Author: marie
 *
 * Created on July 8, 2014, 6:47 PM
 */

#ifndef RESSOURCEOBJECT_HH
#define	RESSOURCEOBJECT_HH

#include    "AMeshObject.hh"
#include    "AGameElement.hh"

class RessourceObject : public AGameElement, public AMeshObject
{
public:
    RessourceObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    RessourceObject(const RessourceObject& orig);
    virtual ~RessourceObject();

    bool    init();
    bool    update();

    void setQuantity(int quantity);
    int getQuantity() const;

    bool setLevel(int level);
    
private:
    int	_quantity;
};

#endif	/* RESSOURCEOBJECT_HH */

