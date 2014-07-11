/* 
 * File:   PersoObject.hh
 * Author: marie
 *
 * Created on July 5, 2014, 8:16 PM
 */

#ifndef PERSOOBJECT_HH
#define	PERSOOBJECT_HH

#include    <array>
#include    <map>
#include    "AAnimatedMeshObject.hh"
#include    "AGameElement.hh"

class PersoObject : public AGameElement, public AAnimatedMeshObject
{
public:
    PersoObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    PersoObject(const PersoObject& orig);
    virtual ~PersoObject();

    bool    init();
    bool    initWithLevel(int level);

    void    setIndex(int index);
    int	    getIndex() const;    
    void    setOrientation(Orientation const& orientation);
    Orientation const& getOrientation() const;
    void    setTeam(std::string const& _team);
    std::string const& getTeam() const;

    bool    setLevel(int level);
    
    /* HANDLERS */
    bool    setInventory(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity);
    std::array<int, RESSOURCE_TYPE_COUNT> const& getInventory() const;


private:
    void    rotateOnNorth();
    void    rotateOnEast();
    void    rotateOnSouth();
    void    rotateOnWest();

    std::array<int, RESSOURCE_TYPE_COUNT>	_inventory;
    std::map<Orientation, void (PersoObject::*)()>	_rotateFuncs;
    int		    _index;
    Orientation	    _orientation;
    std::string	    _team;
};

#endif	/* PERSOOBJECT_HH */

