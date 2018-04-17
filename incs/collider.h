#ifndef COLLIDER_HPP_
# define COLLIDER_HPP_
#include <SFML/Graphics.hpp>

enum ID 
{
	SPACESHIP,
	GROUND,
	PLATFORM
};

class Collider
{

public:
	Collider();
	~Collider();
	void			init(const sf::Rect<float> &, const int &);
	sf::Rect<float>	getRekt() const;
	sf::Vector2f	getPos() const;
	sf::Vector2f	getSize() const;
	int             getId() {return _id;}
	virtual void	updatePos() {}
	int				checkC(const Collider &);
	void            setPos(const float &top)
	{_c.top = top;}

protected:
	int				_id;
	sf::Rect<float>	_c;
	sf::Vector2f	_f;
};

#endif // !COLLIDER_HPP_