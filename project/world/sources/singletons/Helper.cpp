/* 
 * File:   Helper.cpp
 * Author: marie
 * 
 * Created on July 9, 2014, 11:03 PM
 */

#include "Helper.hh"
#include "WorldEngine.hh"
#include "Assets.hh"

using namespace	core;

Helper* Helper::getInstance(int ac, char** av)
{
    static Helper instance(ac, av);
    return &instance;
}
Helper::Helper(int ac, char** av)
{
    if (ac != 2 && ac != 4)
	throw std::string("Bad options.\nUsage : ./world assetsArchive [windowWidth windowHeight]");
    _path = av[1];
    _caseSize = vector3df(3,3,3);
    if (ac == 4)
    {
	std::stringstream str;
	std::stringstream str2;
	str << av[2];
	str >> _winSize.first;
	str2 << av[3];
	str2 >> _winSize.second;
	//TODO : recuperer la taille de l'ecran pour la limite max
//	if (_winSize.first < 1 || _winSize.first > 1000
//		|| _winSize.second < 1 || _winSize.second > 800)
	if (_winSize.first < 1
		|| _winSize.second < 1)
	    throw std::string("Bad window size.");
    }
    else
    {
	_winSize.first = 800;
	_winSize.second = 600;
    }
}

IEngine*	Helper::createEngine() const
{
    IEngine* engine = new WorldEngine();
    Assets::getInstance(engine->getDevice()->getSceneManager(), _path);
    return engine;
}

const posi_t& Helper::getWinSize() const
{
    return _winSize;
}
const vector3df& Helper::getCaseSize() const
{
    return _caseSize;
}

vector3df Helper::mapToWorldCoordinates(const posi_t& pos)
{
    return vector3df(pos.first, 0, -pos.second) * _caseSize;
}
vector3df Helper::mapToWorldCoordinates(const posf_t& pos)
{
    return vector3df(pos.first, 0, -pos.second) * _caseSize;
}
posi_t Helper::worldToMapCoordinates(vector3df real_pos)
{
    return posi_t(real_pos.X / _caseSize.X, -real_pos.Z / _caseSize.Z);
}
