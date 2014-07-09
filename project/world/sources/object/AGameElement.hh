/* 
 * File:   AGameElement.hh
 * Author: marie
 *
 * Created on July 1, 2014, 4:12 PM
 */

#ifndef AGAMEELEMENT_HH
#define	AGAMEELEMENT_HH

#include    "IGameElement.hh"

class AGameElement : public IGameElement
{
public:
    AGameElement();
    AGameElement(const AGameElement& orig);
    virtual ~AGameElement();

//    void setPositionInMap(std::tuple<int, int> const& _positionInMap);
    void setType(GameElementType _type);
    void setMaxLevel(int _maxLevel);
    bool setLevel(int level);
    bool evolue();

//    std::tuple<int, int> const& getPositionInMap() const;
    GameElementType getType() const;
    int getMaxLevel() const;
    int getLevel() const;

private:
    int			_level;
    int			_maxLevel;
    GameElementType	_type;
};

#endif	/* AGAMEELEMENT_HH */

