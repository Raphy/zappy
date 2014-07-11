/* 
 * File:   PlayerObject.hh
 * Author: marie
 *
 * Created on July 5, 2014, 8:16 PM
 */

#ifndef PLAYEROBJECT_HH
#define	PLAYEROBJECT_HH

#include    <array>
#include    <map>
#include    "AAnimatedMeshObject.hh"
#include    "AGameElement.hh"

class PlayerObject : public AGameElement, public AAnimatedMeshObject
{
public:
    PlayerObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos);
//    PlayerObject(const PlayerObject& orig);
    virtual ~PlayerObject();

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
    std::map<Orientation, void (PlayerObject::*)()>	_rotateFuncs;
    int		    _index;
    Orientation	    _orientation;
    std::string	    _team;
};

#endif	/* PLAYEROBJECT_HH */

