/* 
 * File:   Ressources.hh
 * Author: marie
 *
 * Created on June 30, 2014, 4:10 PM
 */

#ifndef	    ASSETS_HH
# define    ASSETS_HH

# include   <assert.h>
# include   <string>
# include   <array>
# include   <irrlicht.h>
# include   "enums.hh"
# include   "IGameElement.hh"

using namespace irr;

class	Assets;

enum	AssetType
{
    MESH = 0,
    HEIGHT_MAP,
    TEXTURE,
    ASSET_TYPE_COUNT,
};

class	Assets {
public:
    static const int	LEVEL_MAX = 8;

    static Assets*	getInstance(scene::ISceneManager* smgr = nullptr,
	    std::string const& path = "./assets/irrlicht/assets.zip");
    bool reload(std::string const& path = "./assets/irrlicht/assets.zip");
    
    std::string const&	getFileName(GameElementType, AssetType, int level) const;
    scene::IMesh*	getMesh(GameElementType, AssetType aType = MESH, int level = 0) const;
    video::ITexture*	getTexture(GameElementType, AssetType aType = TEXTURE, int level = 0) const;
    
private:
    Assets(scene::ISceneManager* smgr, std::string const& path);
    ~Assets();
    
    bool		load(std::string const& path = "./assets/irrlicht/assets.zip");
    video::ITexture*	loadTexture(std::string const& filename);
    video::ITexture*	loadHeightMap(const std::string& filename);
    scene::IMesh*	loadMesh(std::string const& filename);
    

    scene::ISceneManager*	_smgr;
    video::IVideoDriver*	_driver;
    io::IFileSystem*	_fs;
    std::string		_path;
    
    /* ASSETS */
    
    std::array<std::array<std::array<std::string, LEVEL_MAX>, ASSET_TYPE_COUNT + 1>, GAME_ELEMENT_TYPE_COUNT + 1>		    _filenames;
    std::array<std::array<std::array<video::ITexture*, LEVEL_MAX>, ASSET_TYPE_COUNT + 1>, GAME_ELEMENT_TYPE_COUNT + 1>	    _textures;
    std::array<std::array<std::array<scene::IMesh*, LEVEL_MAX>, ASSET_TYPE_COUNT + 1>, GAME_ELEMENT_TYPE_COUNT + 1>		    _meshs;
};

#endif	/* RESSOURCES_HH */

