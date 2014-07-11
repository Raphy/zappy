/* 
 * File:   Helper.hh
 * Author: marie
 *
 * Created on July 9, 2014, 11:03 PM
 */

#ifndef HELPER_HH
#define	HELPER_HH

#include    <irrlicht.h>
#include    <utility>
#include    <string>
#include    <sstream>
#include    "IEngine.hh"

using namespace	irr;

typedef	std::pair<unsigned int,unsigned int>  posi_t;
typedef	std::pair<float,float>  posf_t;

class Helper
{
public:
    static Helper*	    getInstance(int ac = 0, char **av = nullptr);
    
    IEngine*		    createEngine() const;
    
    core::vector3df	    mapToWorldCoordinates(posi_t const& pos);
    core::vector3df	    mapToWorldCoordinates(posf_t const& pos);
    posi_t		    worldToMapCoordinates(core::vector3df real_pos);

    posi_t const&	    getWinSize() const;
    core::vector3df const&  getCaseSize() const;

private:
    Helper(int ac, char **av);
    Helper(const Helper& orig);
    virtual ~Helper() {}

    std::string		_path;
    posi_t		_winSize;
    core::vector3df	_caseSize;
};

#endif	/* HELPER_HH */

