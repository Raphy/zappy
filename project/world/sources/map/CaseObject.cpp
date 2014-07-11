/* 
 * File:   CaseObject.cpp
 * Author: marie
 * 
 * Created on July 10, 2014, 4:35 PM
 */

#include "CaseObject.hh"

using namespace core;

CaseObject::CaseObject(scene::ISceneManager* smgr, INodeObject* parent, const posi_t& pos)
: ANodeObject(smgr, parent, pos)
{
    _alignment = posf_t(0, 0);
    _scale = vector3df(1);
    _ressources.fill(new RessourceObject(_smgr, this, pos)); //util?
}
//CaseObject::CaseObject(const CaseObject& orig)
//: ANodeObject(static_cast<ANodeObject const&> (orig))
//{
//    //TODO : copier les element de caseobject
//}
CaseObject::~CaseObject()
{
    //delete tous les objets portes ?
}


bool CaseObject::callHandler(t_data* data)
{
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
    std::cout << "UNKNOWN CASE EVENT !" << std::endl;
    return false;
}


bool CaseObject::setCaseContent(const std::array<int, RESSOURCE_TYPE_COUNT>& quantity)
{
    for (int i = 0; i < RESSOURCE_TYPE_COUNT; i++)
    {
	RessourceObject* ressource = _ressources.at(i);
	assert(ressource != nullptr);
	if (!ressource || !ressource->init())
	    return false;
	ressource->setPositionInMap(_pos);
	ressource->setLevel(i);
	ressource->setQuantity(quantity.at(i));
	_ressources[i] = ressource;
	//	}
    }
    return true;
}

bool CaseObject::addPerso(int index, Orientation const& o, int level, const std::string& team)
{
    PersoObject* perso = new PersoObject(_smgr, this, _pos);
    if (!perso || !perso->initWithLevel(level))
	return false;
    //TODO : setter index, o, et team?
    perso->setIndex(index);
    perso->setOrientation(o);
    perso->setLevel(level);
    perso->setTeam(team);
    _persos.insert(std::pair<int, INodeObject*>(index, perso));
    //    _persos.push_back(perso);
    return true;
}
void CaseObject::removePerso(int index)
{
    auto it = _persos.find(index);
    _persos.erase(it);
    delete it->second;
}

void CaseObject::registerPerso(PersoObject* perso)
{
    _persos.insert(std::pair<int, INodeObject*>(perso->getIndex(), perso));
}
void CaseObject::unregisterPerso(PersoObject* perso)
{
    auto it = _persos.find(perso->getIndex());
    _persos.erase(it);
}

const std::map<int, INodeObject*>& CaseObject::getEggs() const
{
    return _eggs;
}
const std::map<int, INodeObject*>& CaseObject::getPersos() const
{
    return _persos;
}
const std::array<RessourceObject*, RESSOURCE_TYPE_COUNT>& CaseObject::getRessources() const
{
    return _ressources;
}

