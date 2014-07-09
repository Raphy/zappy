/* 
 * File:   AGameElement.cpp
 * Author: marie
 * 
 * Created on July 1, 2014, 4:12 PM
 */

#include <iostream>
#include "AGameElement.hh"

AGameElement::AGameElement()
{
}

AGameElement::AGameElement(const AGameElement& orig)
{
    (void)orig;
    //TODO
}

AGameElement::~AGameElement()
{
}




/* SETTERS */

void AGameElement::setType(GameElementType _type)
{
    this->_type = _type;
}
//void AGameElement::setPositionInMap(std::tuple<int, int> const& _positionInMap)
//{
//    this->_positionInMap = _positionInMap;
//}
void AGameElement::setMaxLevel(int _maxLevel)
{
    this->_maxLevel = _maxLevel;
}
bool AGameElement::setLevel(int level)
{
    std::cout << "set Level !! " << std::endl;
    if (level > _maxLevel)
	return false;
    _level = level;
    return true;
}
bool AGameElement::evolue()
{
    if (_level == _maxLevel)
	return false;
    _level++;
    return true;
}

/* GETTERS */

GameElementType AGameElement::getType() const
{
    return _type;
}
//std::tuple<int, int> const& AGameElement::getPositionInMap() const
//{
//    return _positionInMap;
//}
int AGameElement::getMaxLevel() const
{
    return _maxLevel;
}
int AGameElement::getLevel() const
{
    return _level;
}


//    int			_level;
//    int			_maxLevel;
//    GameElementType	_type;
//    std::tuple<int,int>	_positionInMap;

