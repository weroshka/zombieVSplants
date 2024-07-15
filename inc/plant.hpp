#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace veroshka
{
	class Plant
	{
	public:
		Plant(int x, int y, float r);
		~Plant();

		bool Setup();

		sf::Sprite* Get();
		int GetX();
		int GetY();
		float GetR();

	private:
		int l_x, l_y;
		float l_r;

		sf::Texture l_texture;
		sf::Sprite* l_plant = nullptr;
	};
}
