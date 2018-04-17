#include "collider.h"

Collider::Collider()
{
	_f = sf::Vector2f(0, 0);
}

Collider::~Collider()
{
}

void Collider::init(const sf::Rect<float> &c, const int &id)
{
	_c = c;
	_c.width /= 2;
	_id = id;
	_f = sf::Vector2f(0, 0);
}

sf::Rect<float> Collider::getRekt() const
{
	return _c;
}

sf::Vector2f Collider::getPos() const
{
	return sf::Vector2f(_c.left, _c.top);
}

sf::Vector2f Collider::getSize() const
{
	return sf::Vector2f(_c.width, _c.height);
}

int Collider::checkC(const Collider &c)
{

	sf::Rect<int>	cTmp(getRekt());
	sf::Rect<int>	tmp(c.getRekt());
	// sf::Vector2i	fTmp(_f);

	// cTmp.left += fTmp.x;
	if (cTmp.intersects(tmp))
        return 1;
	// 	if (fTmp.x > 0)
	// 		_f.x = tmp.left - (cTmp.left - fTmp.x + cTmp.width);
	// 	else if (fTmp.x < 0)
	// 		_f.x = (tmp.left + tmp.width) - (cTmp.left - fTmp.x);
	// cTmp.left -= fTmp.x;
	// cTmp.top += fTmp.y;
	// if (cTmp.intersects(tmp))
	// 	if (fTmp.y > 0)
	// 		_f.y = tmp.top - (cTmp.top - fTmp.y + cTmp.height);
	// 	else if (fTmp.y < 0)
	// 		_f.y = (tmp.top + tmp.height) - (cTmp.top - fTmp.y);
	
	// cTmp.left += _f.x;
	// cTmp.top += _f.y - fTmp.y;
	// if (cTmp.intersects(tmp))
	// 	_f.x += tmp.left + tmp.width - cTmp.left;
	return 0;
}