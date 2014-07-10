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

using namespace	irr;

typedef	std::pair<unsigned int,unsigned int>  posi_t;
typedef	std::pair<float,float>  posf_t;

class Helper
{
public:
//    static Helper*  getInstance()
//    {
//	static Helper instance;
//	return &instance;
//    }
    static core::vector3df MapToWorldCoordinates(posi_t const& pos)
    {
	return core::vector3df(pos.first, 0, -pos.second);
    }
    static core::vector3df MapToWorldCoordinates(posf_t const& pos)
    {
	return core::vector3df(pos.first, 0, -pos.second);
    }
private:
//    Helper();
//    Helper(const Helper& orig);
//    virtual ~Helper();
};

#endif	/* HELPER_HH */

