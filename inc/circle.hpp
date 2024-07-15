#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace veroshka
{
	class Circle
	{
	public:
			Circle(float x, float y, float r);
			~Circle();
			bool Setup();
			sf::Sprite* Get();
			int GetX();
			int GetY();
			float GetR();
			void Move();


	private:
		float n_x, n_y;
		float n_r;
		sf::Texture n_texture;
		sf::Sprite* n_circle = nullptr;
	};
}