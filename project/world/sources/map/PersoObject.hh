/* 
 * File:   PersoObject.hh
 * Author: marie
 *
 * Created on July 5, 2014, 8:16 PM
 */

#ifndef PERSOOBJECT_HH
#define	PERSOOBJECT_HH

#include    <vector>
#include    "AAnimatedMeshObject.hh"
#include    "AGameElement.hh"

class PersoObject : public AGameElement, public AAnimatedMeshObject
{
public:
    PersoObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    PersoObject(const PersoObject& orig);
    virtual ~PersoObject();

    bool    init();

    void setIndex(int index);
    int getIndex() const;    
    
    /* HANDLERS */
    bool    setInventory(/*int x, int y, */std::vector<int> const& quantity) { return false; }

private:
    std::array<int, ASSET_TYPE_COUNT>  _inventory;//vector?
    int	_index;
};

#endif	/* PERSOOBJECT_HH */

