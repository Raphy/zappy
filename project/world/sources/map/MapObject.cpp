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

MapObject::MapObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: AAnimatedMeshObject(smgr, parent, pos), _selector(nullptr)
{
    _alignment = posi_t(0,0);
}

//MapObject::MapObject(const MapObject& orig)
//: AAnimatedMeshObject(static_cast<AAnimatedMeshObject const&>(orig)), _selector(nullptr)
//{
//}

MapObject::~MapObject()
{
    if (_selector)
	_selector->drop();
}

bool    MapObject::init()
{
    createGround(20,30);//test
    
    for (unsigned int x = 0; x < _mapSize.first; x++)
    {
        CaseObject *c = getCaseObject(posi_t(10,x));
	c->init();
	std::array<int, RESSOURCE_TYPE_COUNT> q;
	q.fill(1);
	c->setCaseContent(q);
    }
    
    //    CaseObject *c = getCaseObject(posi_t(10,10));
    //    CaseObject *c2 = getCaseObject(posi_t(10,11));
    //    CaseObject *c3 = getCaseObject(posi_t(10,12));
    //
    //    c->init();
    //    c2->init();
    //    c3->init();
    ////    bool    setCaseContent(std::array<int, RESSOURCE_TYPE_COUNT> const& quantity);
    //    std::array<int, RESSOURCE_TYPE_COUNT> q;
    //    q.fill(1);
    //    c->setCaseContent(q);
    //    c2->setCaseContent(q);
    //    c3->setCaseContent(q);
    
    
    ////    c->setPositionInMap(posi_t(10,10));
    //    RessourceObject *r = new RessourceObject(_smgr, this, c->getPositionInMap());
    //    r->setQuantity(10);
    //    std::cout << r->getQuantity() << std::endl;
    //    std::cout << r->getPositionInMap().first << std::endl;
    //    std::cout << r->getPositionInMap().second << std::endl;
    //    r->init();
    //    //    delete c;
    
    
    //    std::for_each(_persos.begin(), _persos.end(), [](IObject* perso){
    //	perso->init();
    //    });
    return true;
}

void MapObject::scaleOnCase()
{
    vector3df extent = _node->getTransformedBoundingBox().getExtent();
    vector3df scale = _node->getScale();
    if (extent.X > 1.0f)
        scale.X *= 1.0f / extent.X;
    if (extent.Z > 1.0f)
        scale.Z *= 1.0f / extent.Z;
    scale *= _helper->getCaseSize();
    scale.X *= _mapSize.first;
    scale.Z *= _mapSize.second;
    _node->setScale(scale);
}
void MapObject::updateNodePosition()
{
    vector3df caseSize = _helper->getCaseSize();
    posf_t real_pos(0, _mapSize.second * caseSize.Z);
    vector3df pos = _helper->mapToWorldCoordinates(real_pos);
    pos /= caseSize;
    _node->setPosition(pos);
}


bool MapObject::callHandler(t_data * data)
{
    if (data->game_element_type == PERSO_CLASS
	    || data->game_element_type == RESSOURCE_CLASS
	    || data->game_element_type == EGG_CLASS
	    || data->game_element_type == CASE_CLASS)
    {
	t_infos * infos = data->infos;
	posi_t	pos = infos->pos;
	CaseObject * caseObj = getCaseObject(pos);
	//	CaseObject& caseObj;
	//	tryGetCaseObject(pos, caseObj);
	switch (data->event_type)
	{
	    case PERSO_CONNECTION_EVENT:
		return caseObj->addPerso(infos->player_id, infos->orientation, infos->level, infos->team_name);
		//	    case PERSO_DEAD_EVENT:
		//		return caseObj->removePerso(infos->player_id);
	    case CASE_CONTENT_EVENT:
		return caseObj->setCaseContent(infos->quantity);
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
    _mapSize.first = x;
    _mapSize.second = y;
    
    std::string const& heightmap = _assets->getFileName(MAP, HEIGHT_MAP, 0);
    ITerrainSceneNode* node = _smgr->addTerrainSceneNode(heightmap.c_str(), getParentNode(), NODE_ID_MAP);
    _node = node;
    if (!_node)//throw exception ?
	return false;
    
    scaleOnCase();
    updateNodePosition();
    
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
    
    initCases();
    return true;
}

CaseObject* MapObject::getCaseObject(posi_t const& pos)// const
{
    return &_cases[pos.first][pos.second];
}
bool MapObject::tryGetCaseObject(const posi_t& pos, CaseObject* caseObject)// const
{
    if (false)//TODO : check pos
	return false;
    caseObject = &_cases[pos.first][pos.second];
    return true;
}


void MapObject::initCases()
{
    for (unsigned int i = 0; i < _mapSize.second; i++)
    {
	std::vector<CaseObject>	row;
	for (unsigned int j = 0; j < _mapSize.first; j++)
	{
	    row.push_back(CaseObject(_smgr, this, posi_t(j,i)));
	}		
	_cases.push_back(row);
    }
}
