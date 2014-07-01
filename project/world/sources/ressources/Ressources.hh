/* 
 * File:   Ressources.hh
 * Author: marie
 *
 * Created on June 30, 2014, 4:10 PM
 */

#ifndef	    RESSOURCES_HH
# define    RESSOURCES_HH

# include   <string>
# include   <irrlicht.h>
# include   "ids.hh"
# include   "IGameElement.hh"

using namespace irr;

class	Ressources;

enum	RessourceType
{
    MESH,
    HEIGHT_MAP,
    TEXTURE,
//    FILENAME,
//    PATH
};

class	Ressources {
public:
    static Ressources*	getInstance(scene::ISceneManager* smgr = nullptr,
	    std::string const& path = "./assets");
    void reload(std::string const& path = "./assets");
    
    std::string const&	getFileName(GameElementType, RessourceType) const;
    scene::IMesh*	getMesh(GameElementType, RessourceType rType = MESH, int level = 0) const;
    video::ITexture*	getTexture(GameElementType, RessourceType rType = TEXTURE, int level = 0) const;

//    std::string const&	getMapHeightFile() const;
//    std::string const&	getPersoMeshFile() const;
//    std::string const&	getMapTextureFile() const;
//    std::string const&	getPersoTextureFile() const;
//    
//    scene::IMesh*	getPersoMesh(int level) const;
//    
//    video::ITexture*	getPersoTexture() const;
//    video::ITexture*	getMapTexture() const;
    
private:
    Ressources(scene::ISceneManager* smgr, std::string const& path);
    ~Ressources();
    
    void		load(std::string const& path = "./assets");
    video::ITexture*	loadTexture(std::string const& filename);
    scene::IMesh*	loadMesh(std::string const& filename);
    
    
    scene::ISceneManager*	_smgr;
    video::IVideoDriver*	_driver;
    io::IFileSystem*	_fs;
    std::string		_path;
    
    /* FILENAMES */
    
    std::string		_mapHeight;
    
    std::string		_mapTextureFile;
    std::string		_dummyTextureFile;
    std::string		_persoTextureFile[8];
    
    std::string		_dummyMeshFile;
    std::string		_persoMeshFile[8];
    
    /* TEXTURES */
    
    video::ITexture*	_mapHeightTexture;
    video::ITexture*	_mapTexture;
    video::ITexture*	_persoTexture[8];
};

#endif	/* RESSOURCES_HH */

