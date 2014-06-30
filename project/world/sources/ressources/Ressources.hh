/* 
 * File:   Ressources.hh
 * Author: marie
 *
 * Created on June 30, 2014, 4:10 PM
 */

#ifndef RESSOURCES_HH
#define	RESSOURCES_HH

#include <string>
#include <irrlicht.h>

using namespace irr;

class Ressources {
public:
    Ressources();
    virtual ~Ressources();
    
    void load(std::string const& path = "./assets");
    void reload(std::string const& path = "./assets");
    
    scene::IMesh*  getPersoMesh(int level);
private:
    std::string	_path;
};

#endif	/* RESSOURCES_HH */

