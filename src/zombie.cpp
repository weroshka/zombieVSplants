#include <zombie.hpp>

namespace veroshka
{
	Zombie::Zombie(float x, float y, int r)
	{
		z_x = x;
		z_y = y;
		z_r = r;
	}

	bool Zombie::Setup()
	{
		if (!z_texture.loadFromFile("img/zombie.png"))
		{
			std::cout << "ERROR when loading zombie.png" << std::endl;
			return false;
		}

		z_zombie = new sf::Sprite();
		z_zombie->setTexture(z_texture);
		z_zombie->setOrigin(z_r, z_r);
		z_zombie->setPosition(z_x, z_y);
		z_zombie->setScale(0.6, 0.6);

		return true;
	}

	void Zombie::Move()
	{
		z_x += -1;
		z_y = z_y;
		z_zombie->setPosition(z_x, z_y);
	}

	Zombie::~Zombie()
	{
		if (z_zombie != nullptr)
			delete z_zombie;
	}

	sf::Sprite* Zombie::Get() { return z_zombie; }

	int Zombie::GetX() { return z_x; }
	int Zombie::GetY() { return z_y; }
	/*float Zombie::GetR() { return z_r; }*/
}