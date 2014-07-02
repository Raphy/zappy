/* 
 * File:   ILevel.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:06 PM
 */

#ifndef ILEVEL_HH
#define	ILEVEL_HH

class ILevel
{
public:
    virtual ~ILevel() {}
    
    virtual int	    getLevel() const = 0;
    virtual int	    getMaxLevel() const = 0;
    virtual bool    setLevel(int newLevel) = 0;
    virtual bool    evolue() = 0;
};

#endif	/* ILEVEL_HH */

