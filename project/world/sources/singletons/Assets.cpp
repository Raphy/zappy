/* 
 * File:   Ressources.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 4:10 PM
 */

#include <iostream>
#include "Assets.hh"


Assets*	Assets::getInstance(scene::ISceneManager* smgr,
	std::string const& path)
{
    static Assets instance(smgr, path);
    return &instance;
}

Assets::Assets(scene::ISceneManager* smgr, std::string const& path)
: _smgr(smgr), _driver(smgr->getVideoDriver()), _fs(smgr->getFileSystem()), _path(path)
{    
    //TODO : utiliser un algo de la STL ?
    for (int i = 0; i <= GAME_ELEMENT_TYPE_COUNT; i++)
	for (int j = 0; j <= RESSOURCE_TYPE_COUNT; j++)
	    for (int k = 0; k < LEVEL_MAX; k++)
	    {
		_filenames[i][j][k] = "";
		_textures[i][j][k] = nullptr;
		_meshs[i][j][k] = nullptr;
	    }
    
    _filenames[GAME_ELEMENT_TYPE_COUNT][RESSOURCE_TYPE_COUNT][0] = "terrain-texture.jpg";
    _filenames[GAME_ELEMENT_TYPE_COUNT][MESH][0] = "perso/faerie.md2";
//    _filenames[GAME_ELEMENT_TYPE_COUNT][HEIGHT_MAP][0] = "ground/normal.tga";
    _filenames[GAME_ELEMENT_TYPE_COUNT][HEIGHT_MAP][0] = "heightmap.bmp";
    _filenames[GAME_ELEMENT_TYPE_COUNT][TEXTURE][0] = "terrain-texture.jpg";
    
    for (int i = 0; i < LEVEL_MAX; i++)
    {
	_filenames[PERSO][MESH][0] = "perso/faerie.md2";
	_filenames[PERSO][TEXTURE][0] = "perso/faerie2.bmp";
    }
    
//    _filenames[MAP][HEIGHT_MAP][0] = "ground/normal.tga";
    _filenames[MAP][HEIGHT_MAP][0] = "heightmap.bmp";
    _filenames[MAP][TEXTURE][0] = "terrain-texture.jpg";
    _filenames[MAP][TEXTURE][1] = "detailmap3.jpg";

//        _driver->getTexture("../../media/irrlicht2_up.jpg"),
//        _driver->getTexture("../../media/irrlicht2_dn.jpg"),
//        _driver->getTexture("../../media/irrlicht2_lf.jpg"),
//        _driver->getTexture("../../media/irrlicht2_rt.jpg"),
//        _driver->getTexture("../../media/irrlicht2_ft.jpg"),
//        _driver->getTexture("../../media/irrlicht2_bk.jpg"));
//    scene::ISceneNode* skydome = _smgr->addSkyDomeSceneNode(_driver->getTexture("../../media/skydome.jpg"),16,8,0.95f,2.0f);


        _filenames[SKYBOX][TEXTURE][0] = "irrlicht2_up.jpg";
        _filenames[SKYBOX][TEXTURE][1] = "irrlicht2_dn.jpg";
        _filenames[SKYBOX][TEXTURE][2] = "irrlicht2_lf.jpg";
        _filenames[SKYBOX][TEXTURE][3] = "irrlicht2_rt.jpg";
        _filenames[SKYBOX][TEXTURE][4] = "irrlicht2_ft.jpg";
        _filenames[SKYBOX][TEXTURE][5] = "irrlicht2_bk.jpg";
        _filenames[SKYBOX][TEXTURE][6] = "";//?
//        _filenames[SKYBOX][TEXTURE][0] = "skybox/up.psd";
//        _filenames[SKYBOX][TEXTURE][1] = "skybox/bot.psd";
//        _filenames[SKYBOX][TEXTURE][2] = "skybox/l.psd";
//        _filenames[SKYBOX][TEXTURE][3] = "skybox/r.psd";
//        _filenames[SKYBOX][TEXTURE][4] = "skybox/front.psd";
//        _filenames[SKYBOX][TEXTURE][5] = "skybox/down.psd";
//        _filenames[SKYBOX][TEXTURE][6] = "skybox/up.psd";//?
    
    //        _filenames[PERSO][TEXTURE][2] = "enano.jpg";
    _filenames[PERSO][MESH][3] = "perso/dwarf.x";
    _filenames[PERSO][TEXTURE][3] = "perso/dwarf.jpg";
    _filenames[PERSO][MESH][4] = "perso/ninja.b3d";
    _filenames[PERSO][TEXTURE][4] = "perso/nskinbl.jpg";
    _filenames[PERSO][MESH][5] = "perso/ninja.b3d";
    _filenames[PERSO][TEXTURE][5] = "perso/nskinrd.jpg";
    _filenames[PERSO][MESH][6] = "perso/sydney.md2";
    _filenames[PERSO][TEXTURE][6] = "perso/sydney.bmp";
    
    load(path);
}
Assets::~Assets()
{}



bool Assets::load(std::string const& path)
{
    std::cout << "FILE ARCHIVE : " << path
	    << " with working repertory = " << _fs->getWorkingDirectory().c_str() << std::endl;
    _fs->addFileArchive(path.c_str());
    
    _textures[GAME_ELEMENT_TYPE_COUNT][TEXTURE][0] = loadTexture(_filenames[GAME_ELEMENT_TYPE_COUNT][TEXTURE][0]);
    _textures[GAME_ELEMENT_TYPE_COUNT][HEIGHT_MAP][0] = loadHeightMap(_filenames[GAME_ELEMENT_TYPE_COUNT][HEIGHT_MAP][0]);
    _meshs[GAME_ELEMENT_TYPE_COUNT][MESH][0] = loadMesh(_filenames[GAME_ELEMENT_TYPE_COUNT][MESH][0]);
    
    for (int i = 0; i < GAME_ELEMENT_TYPE_COUNT; i++)
	for (int k = 0; k < LEVEL_MAX; k++)
	{
	    _textures[i][TEXTURE][k] = (!_filenames[i][TEXTURE][k].empty()) ?
		(loadTexture(_filenames[i][TEXTURE][k])) :
		(_textures[GAME_ELEMENT_TYPE_COUNT][TEXTURE][0]);
	    _textures[i][HEIGHT_MAP][k] = (!_filenames[i][HEIGHT_MAP][k].empty()) ?
		(loadHeightMap(_filenames[i][HEIGHT_MAP][k])) :
		(_textures[GAME_ELEMENT_TYPE_COUNT][HEIGHT_MAP][0]);
	    _meshs[i][MESH][k] = (!_filenames[i][MESH][k].empty()) ?
		(loadMesh(_filenames[i][MESH][k])) :
		(_meshs[GAME_ELEMENT_TYPE_COUNT][MESH][0]);
	}
    return true;
}
bool Assets::reload(std::string const& path)
{
    (void)path;
    //TODO
    return false;
}

video::ITexture* Assets::loadTexture(const std::string& filename)
{
    //video::ITexture* tmp = _smgr->getVideoDriver()->addTexture(core::dimension2du(32, 32), filename.c_str());
    //    video::ITexture* tmp = _smgr->getVideoDriver()->getTexture("./world/assets/irrlicht/faerie2.bmp");
    video::ITexture* tmp = _smgr->getVideoDriver()->getTexture(filename.c_str());
    if (!tmp)
	std::cout << "NULL TEXTURE : " << filename << std::endl;
    return tmp;
}
video::ITexture* Assets::loadHeightMap(const std::string& filename)
{
    //    (void)f;
    //    std::string filename = _filenames[GAME_ELEMENT_TYPE_COUNT][TEXTURE][0];
    video::ITexture* tmp = _smgr->getVideoDriver()->addTexture(core::dimension2du(32, 32), filename.c_str());
    //    _smgr->getVideoDriver()->makeNormalMapTexture(tmp);
    if (!tmp)
	std::cout << "NULL TEXTURE : " << filename << std::endl;
    return tmp;
}
scene::IMesh* Assets::loadMesh(const std::string& filename)
{
    scene::IMesh* tmp = _smgr->getMesh(filename.c_str());
    if (!tmp)
	std::cout << "NULL MESH : " << filename << std::endl;
    return tmp;
}




/* GETTERS */

const std::string& Assets::getFileName(GameElementType egType, RessourceType rType, int level) const
{
    return _filenames[static_cast<int>(egType)][static_cast<int>(rType)][level];
}
scene::IMesh* Assets::getMesh(GameElementType egType, RessourceType rType, int level) const
{
    assert(rType == MESH);
    scene::IMesh* tmp =  _meshs[static_cast<int>(egType)][static_cast<int>(rType)][level];
    if (!tmp)
	std::cout << "NULL MESH : " << std::endl;
    return tmp;    
}
video::ITexture* Assets::getTexture(GameElementType egType, RessourceType rType, int level) const
{
    assert(rType == TEXTURE || rType == HEIGHT_MAP);
    video::ITexture* tmp = _textures[static_cast<int>(egType)][static_cast<int>(rType)][level];
    std::string debug_name = _filenames[static_cast<int>(egType)][static_cast<int>(rType)][level];
    if (!tmp)
	std::cout << "NULL TEXTURE : " << std::endl;
    return tmp;    
}
