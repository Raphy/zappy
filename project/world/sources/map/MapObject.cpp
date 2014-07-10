/* 
 * File:   MapObject.cpp
 * Author: marie
 * 
 * Created on June 30, 2014, 8:34 PM
 */

#include <algorithm>
#include <iostream>
#include "MapObject.hh"
#include "AGameElement.hh"

#include    "PersoObject.hh"
#include    "RessourceObject.hh"

using namespace video;
using namespace scene;
using namespace core;

MapObject::MapObject(scene::ISceneManager* smgr, INodeObject* parent)
: AAnimatedMeshObject(smgr, parent), _selector(nullptr)
{
}

MapObject::MapObject(const MapObject& orig)
: AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig)), _selector(nullptr)
{
}

MapObject::~MapObject()
{
    if (_selector)
	_selector->drop();
}

bool    MapObject::init()
{
    //    createGround(20,20);//test
    
    //    std::for_each(_persos.begin(), _persos.end(), [](IObject* perso){
    //	perso->init();
    //    });
    return true;
}





bool MapObject::callHandler(t_data * data)
{
    std::cout << "EVENT RECEIVED ..." << std::endl;
    if (data->game_element_type == PERSO_CLASS
	    || data->game_element_type == RESSOURCE_CLASS
	    || data->game_element_type == EGG_CLASS)
    {
	t_infos * infos = data->infos;
	switch (data->event_type)
	{
	    default:
		break;
	}
    }
    std::cout << "UNKNOWN MAP EVENT !" << std::endl;
    return false;
}

/* HANDLERS */

bool MapObject::createGround(int x, int y)
{
    std::string const& heightmap = _assets->getFileName(MAP, HEIGHT_MAP, 0);
    ITerrainSceneNode* node = _smgr->addTerrainSceneNode(heightmap.c_str(), getParentNode(), NODE_ID_MAP);//,
    //	    core::vector3df(0, 0, 0),		// position
    ////	    core::vector3df(x/2.0, 0, y/2.0),		// position
    //	    core::vector3df(1.f, 0.f, 0.f),		// rotation
    //	    core::vector3df(1.f, 1.f, 1.f),	// scale
    //	    video::SColor ( 255, 255, 255, 0 ),	// vertexColor
    //	    5,					// maxLOD
    //	    scene::ETPS_17,				// patchSize
    //	    4					// smoothFactor
    //	    );
    //    ITerrainSceneNode* node = _smgr->addTerrainSceneNode(heightmap.c_str());
    _node = node;
    if (!_node)
	return false;
    
    vector3df extent = node->getTransformedBoundingBox().getExtent();
    if (extent.X > 1.0f)
        node->setScale(vector3df(1.0 / extent.X, 1.0, 1.0));
    if (extent.Z > 1.0f)
        node->setScale(vector3df(1.0, 1.0, 1.0 / extent.Z) * node->getScale());
    node->setScale(vector3df(x, 1.f, y) * node->getScale());
    
    _node->setMaterialFlag(EMF_LIGHTING, true);
    ////    _node->setMaterialFlag(EMF_FOG_ENABLE, true);
    ////    _node->setMaterialType(video::EMT_DETAIL_MAP);
    _node->setMaterialTexture(0, _assets->getTexture(MAP, TEXTURE, 0));
    _node->setMaterialTexture(1, _assets->getTexture(MAP, TEXTURE, 1));        
    _node->getMaterial(0).getTextureMatrix(0).setTextureScale(x,y);
    
    _selector = _smgr->createTerrainTriangleSelector(node);
    if (!_selector)
	return false;
    node->setTriangleSelector(_selector);
    return true;
}

bool MapObject::setCaseContent(posi_t const& pos, const std::vector<int>& quantity)
{
    std::vector<INodeObject*> the_case = _ressources[pos];
    if (the_case.empty())
    {
	std::vector<INodeObject*> content(RESSOURCE_TYPE_COUNT, nullptr);
	_ressources.insert(std::pair<posi_t, std::vector<INodeObject*>>(pos, content));
    }
    int level = 0;
    auto it = quantity.begin();
    auto end = quantity.end();
    for (; it != end; ++it)
    {
//	RessourceObject* ressource = static_cast<RessourceObject*>(the_case[level]);
	RessourceObject* ressource = nullptr;
	if (!ressource)
	    this->addRessource(pos, level, quantity[level]);
	//	else
	//	    ressource->setQuantity(quantity[level]);
	level++;
    }
    
    //    std::for_each(quantity.begin(), quantity.end(), [&](int q){
    //	RessourceObject* ressource = static_cast<RessourceObject*>(the_case[level]);
    //	if (!ressource)
    //	    this->addRessource(pos, level, quantity[level]);
    //	//	else
    //	//	    ressource->setQuantity(quantity[level]);
    //	level++;
    //    });
    return false;
}

bool MapObject::addPerso(posi_t const& pos, int index, Orientation o, int level, const std::string& team)
{
    //    PersoObject* perso = _binder->createGameElementObject<PERSO>(_smgr, this);
    INodeObject* perso = _binder->createGameElementObject<PERSO>(_smgr, this);
    if (!perso || !perso->init())
	return false;
    perso->setPositionInMap(pos);
    //TODO : setter index, o, et team?
    //    perso->setLevel(level);
    _persos.push_back(perso);
    return true;
}

bool MapObject::addRessource(const posi_t& pos, int level, int quantity)
{
    //    RessourceObject* ressource = _binder->createGameElementObject<RESSOURCE>(_smgr, this);
    INodeObject* ressource = _binder->createGameElementObject<RESSOURCE>(_smgr, this);
    if (!ressource || !ressource->init())
	return false;
    ressource->setPositionInMap(pos);
//    ressource->setPositionInMap(posi_t(15,15));
    //    ressource->setLevel(level);
    //    ressource->setQuantity(quantity);
    _ressources[pos].push_back(ressource);
    return true;
}
