#include <plant.hpp>

namespace veroshka
{
	Plant::Plant(int x, int y, float r)
	{
		l_x = x;
		l_y = y;
		l_r = r;
	}

	bool Plant::Setup()
	{
		if (!l_texture.loadFromFile("img/plant.png"))
		{
			std::cout << "ERROR when loading peppa.png" << std::endl;
			return false;
		}

		l_plant = new sf::Sprite();
		l_plant->setTexture(l_texture);
		l_plant->setOrigin(l_r, l_r);
		l_plant->setPosition(l_x, l_y);
		l_plant->setScale(0.12, 0.12);

		return true;
	}

	Plant::~Plant()
	{
		if (l_plant != nullptr)
			delete l_plant;
	}

	sf::Sprite* Plant::Get() { return l_plant; }

	int Plant::GetX() { return l_x; }
	int Plant::GetY() { return l_y; }
	float Plant::GetR() { return l_r; }
}
