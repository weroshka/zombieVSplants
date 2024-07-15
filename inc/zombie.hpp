#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace veroshka
{
	class Zombie
	{
	public:
		Zombie(float x, float y, int r);
		~Zombie();

		bool Setup();
		void Move();
		sf::Sprite* Get();
		int GetX();
		int GetY();
		/*float GetR();*/

	private:
		float z_x, z_y;
		int z_r;
	
		sf::Texture z_texture;
		sf::Sprite* z_zombie = nullptr;
	};
}