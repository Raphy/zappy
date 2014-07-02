/* 
 * File:   Ressources.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 4:10 PM
 */

#include "Ressources.hh"


Ressources*	Ressources::getInstance(scene::ISceneManager* smgr,
	std::string const& path)
{
    static Ressources instance(smgr, path);
    return &instance;
}

Ressources::Ressources(scene::ISceneManager* smgr, std::string const& path)
: _smgr(smgr), _fs(smgr->getFileSystem()), _driver(smgr->getVideoDriver()), _path(path)
{
    _dummyTextureFile = "wall.bmp";
    _dummyMeshFile = "faerie2.bmp";
    
    _mapHeight = "terrain-heightmap.bmp";
    
    _mapTextureFile = _dummyTextureFile;//"terrain-texture.jpg";
    
    
    for (int i = 0; i < 8; i++)
    {
	_persoTextureFile[i] = "faerie.md2";
	_persoMeshFile[i] = _dummyMeshFile;
    }
    
    load(path);
}
Ressources::~Ressources()
{}

void Ressources::load(std::string const& path)
{
    _fs->addFileArchive(path.c_str());
    
    _mapHeightTexture = loadTexture(_mapHeight);
//    _mapTexture = loadTexture(_mapHeight);
//    loadTexture(getMapTextureFile());
}
void Ressources::reload(std::string const& path)
{
    //TODO
}

video::ITexture* Ressources::loadTexture(const std::string& filename)
{
    return _smgr->getVideoDriver()->addTexture(core::dimension2du(32, 32), filename.c_str());
}
scene::IMesh* Ressources::loadMesh(const std::string& filename)
{
    return nullptr;
}




/* GETTERS */

const std::string& Ressources::getFileName(GameElementType egType, RessourceType rType) const
{
    return _mapHeight;
}
scene::IMesh* Ressources::getMesh(GameElementType, RessourceType rType, int level) const
{
    return nullptr;
}
video::ITexture* Ressources::getTexture(GameElementType, RessourceType rType, int level) const
{
    return nullptr;
}




//scene::IMesh*  Ressources::getPersoMesh(int level) const
//{
//    return nullptr;
//}
//
//std::string const&	Ressources::getMapHeightFile() const
//{
//    return _mapHeight;
//}
//
//const std::string& Ressources::getMapTextureFile() const
//{
//    return _mapTextureFile;
//}
//const std::string& Ressources::getPersoTextureFile() const
//{
//    return _persoTextureFile[0];
//}
//
//video::ITexture* Ressources::getMapTexture() const
//{
//    return _mapTexture;
//}
//video::ITexture* Ressources::getPersoTexture() const
//{
//    return _persoTexture[0];
//}
//
//const std::string& Ressources::getPersoMeshFile() const
//{
//    return _persoMeshFile[0];
//}


