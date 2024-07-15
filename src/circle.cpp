#include <circle.hpp>

namespace veroshka
{
	Circle::Circle(float x, float y, float r)
	{
		n_x = x;
		n_y = y;
		n_r = r;
	}

	bool Circle::Setup()
	{
		if (!n_texture.loadFromFile("img/circle.png"))
		{
			std::cout << "ERROR when loading circle.png" << std::endl;
			return false;
		}

		n_circle = new sf::Sprite;
		n_circle->setTexture(n_texture);
		n_circle->setOrigin(n_r, n_r);
		n_circle->setPosition(n_x, n_y);
		n_circle->setScale(0.05, 0.05);

		return true;
	}

	Circle::~Circle()
	{
		if (n_circle != nullptr)
			delete n_circle;
	}

	void Circle::Move()
	{
		n_x += 1;
		n_y = n_y;
		n_circle->setPosition(n_x, n_y);
	}

	sf::Sprite* Circle::Get() { return n_circle; }

	int Circle::GetX() { return n_x; }
	int Circle::GetY() { return n_y; }
	float Circle::GetR() { return n_r; }
}