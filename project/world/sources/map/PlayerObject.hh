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

    void    setIndex(unsigned int index);
    void    setOrientation(Orientation const& orientation);
    void    setTeam(std::string const& _team);
    bool    setLevel(int level);
    bool    setInventory(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity);

    int			getIndex() const;    
    Orientation const&	getOrientation() const;
    std::string const&	getTeam() const;
    std::array<int, RESSOURCE_TYPE_COUNT> const&    getInventory() const;

    bool    expel();
    bool    broadcast();
    bool    fork();
    bool    incant(bool begin);
    bool    takeRessource();
    bool    throwRessource();
    
    /* HANDLERS */
    bool    levelHandler(t_infos *infos);
    bool    inventoryHandler(t_infos *infos);
    bool    expelHandler(__attribute__((unused))t_infos *infos);
    bool    broadcastHandler(__attribute__((unused))t_infos *infos);
    bool    incantationHandler(__attribute__((unused))t_infos *infos);
    bool    forkHandler(__attribute__((unused))t_infos *infos);
    bool    takeHandler(__attribute__((unused))t_infos *infos);
    bool    throwHandler(__attribute__((unused))t_infos *infos);

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

