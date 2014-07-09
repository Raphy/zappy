/* 
 * File:   IGameElement.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:08 PM
 */

#ifndef IGAMEELEMENT_HH
#define	IGAMEELEMENT_HH

#include    "ILevel.hh"
#include    "enums.hh"

class	IGameElement : public ILevel
{
public:
    virtual ~IGameElement() {}
    
    virtual GameElementType getType() const = 0;
    // From ILEVEL :    
    //    virtual int	    getLevel() const = 0;
    //    virtual int	    getMaxLevel() const = 0;
    //    virtual bool    setLevel(int newLevel) = 0;
    //    virtual bool    evolue() = 0;
};

#endif	/* IGAMEELEMENT_HH */

