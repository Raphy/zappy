/* 
 * File:   IGameElement.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:08 PM
 */

#ifndef IGAMEELEMENT_HH
#define	IGAMEELEMENT_HH

#include    "IPosition.hh"
#include    "ILevel.hh"

enum	GameElementType
{
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    PERSO,
    MAP,
    GAME_ELEMENT_TYPE_COUNT,
};

class	IGameElement : public IPosition, public ILevel
{
public:
    virtual ~IGameElement() {}
    
    virtual GameElementType getType() const = 0;
};

#endif	/* IGAMEELEMENT_HH */

