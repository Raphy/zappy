/* 
 * File:   IPosition.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:04 PM
 */

#ifndef IPOSITION_HH
#define	IPOSITION_HH

#include    <tuple>

class IPosition
{
public:
    virtual ~IPosition() {}
    
    virtual std::tuple<int,int> const&	getPositionInMap() const = 0;
    virtual void    setPositionInMap(std::tuple<int,int> const& newPosition) = 0;
};

#endif	/* IPOSITION_HH */

