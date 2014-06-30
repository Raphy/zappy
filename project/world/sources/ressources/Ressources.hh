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
#include "ids.hh"

using namespace irr;

class Ressources;

class Ressources {
public:
    static Ressources*	getInstance(io::IFileSystem* fs = nullptr,
	    std::string const& path = "./assets")
    {
	static Ressources instance(fs, path);
	return &instance;
    }
    
    void reload(std::string const& path = "./assets")
    {
	//TODO
    }
    
    scene::IMesh*  getPersoMesh(int level) { return nullptr; }
//    scene::IMesh*  getMapMesh(scene::ISceneManager* smgr)
//    { return smgr->addTerrainMesh(meshname, texture, heightmap, ...); }
    scene::ISceneNode*  getMapNode(scene::ISceneManager* smgr, scene::ISceneNode* parent)
    { return smgr->addTerrainSceneNode("terrain-heightmap.bmp", parent, NODE_ID_MAP); }
    
private:
    Ressources(io::IFileSystem* fs, std::string const& path)
    : _fs(fs), _path(path)
    {
	load(path);
    }
    ~Ressources()
    {}

    void load(std::string const& path = "./assets")
    {
	_fs->addFileArchive(path.c_str());
    }

    io::IFileSystem*	_fs;
    std::string		_path;
};

#endif	/* RESSOURCES_HH */

