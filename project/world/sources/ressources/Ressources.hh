/* 
 * File:   Ressources.hh
 * Author: marie
 *
 * Created on June 30, 2014, 4:10 PM
 */

#ifndef	    RESSOURCES_HH
# define    RESSOURCES_HH

# include   <assert.h>
# include   <string>
# include   <array>
# include   <irrlicht.h>
# include   "ids.hh"
# include   "IGameElement.hh"

using namespace irr;

class	Ressources;

enum	RessourceType
{
    MESH = 0,
    HEIGHT_MAP,
    TEXTURE,
    RESSOURCE_TYPE_COUNT,
};

class	Ressources {
public:
    static const int	LEVEL_MAX = 8;

    static Ressources*	getInstance(scene::ISceneManager* smgr = nullptr,
	    std::string const& path = "./assets");
    bool reload(std::string const& path = "./assets");
    
    std::string const&	getFileName(GameElementType, RessourceType, int level) const;
    scene::IMesh*	getMesh(GameElementType, RessourceType rType = MESH, int level = 0) const;
    video::ITexture*	getTexture(GameElementType, RessourceType rType = TEXTURE, int level = 0) const;
    
private:
    Ressources(scene::ISceneManager* smgr, std::string const& path);
    ~Ressources();
    
    bool		load(std::string const& path = "./assets");
    video::ITexture*	loadTexture(std::string const& filename);
    video::ITexture*	loadHeightMap(const std::string& filename);
    scene::IMesh*	loadMesh(std::string const& filename);
    

    scene::ISceneManager*	_smgr;
    video::IVideoDriver*	_driver;
    io::IFileSystem*	_fs;
    std::string		_path;
    
    /* ASSETS */
    
    std::array<std::array<std::array<std::string, LEVEL_MAX>, RESSOURCE_TYPE_COUNT + 1>, GAME_ELEMENT_TYPE_COUNT + 1>		    _filenames;
    std::array<std::array<std::array<video::ITexture*, LEVEL_MAX>, RESSOURCE_TYPE_COUNT + 1>, GAME_ELEMENT_TYPE_COUNT + 1>	    _textures;
    std::array<std::array<std::array<scene::IMesh*, LEVEL_MAX>, RESSOURCE_TYPE_COUNT + 1>, GAME_ELEMENT_TYPE_COUNT + 1>		    _meshs;
};

#endif	/* RESSOURCES_HH */

