#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <zombie.hpp>
#include<circle.hpp>
#include <plant.hpp>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std::chrono_literals;

int main()
{
    float t = 0;
    int score = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 429), "Zombie VS Plants");

    // Подгрузка фонового изображения
    sf::Texture texture;
    if (!texture.loadFromFile("img/day_level.png"))
    {
        std::cout << "ERROR when loading day_level.png" << std::endl;
        return false;
    }
    sf::Sprite back;
    back.setTexture(texture);

    sf::Texture texture1;
    if (!texture1.loadFromFile("img/score.png"))
    {
        std::cout << "ERROR when loading day_level.jpg" << std::endl;
        return false;
    }
    sf::Sprite scoree;
    scoree.setPosition(850, 369);
    scoree.setTexture(texture1);
   
    
    // Подгрузка шрифта и создание отображения счета
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Score");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Добавление иконки
    sf::Image icon;
    if (!icon.loadFromFile("img/icon32_1.png"))
    {
        return -1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    std::vector<veroshka::Plant*> plants;
    plants.push_back(new veroshka::Plant(150, 50, 25));
    plants.push_back(new veroshka::Plant(150, 150, 25));
    plants.push_back(new veroshka::Plant(150, 250, 25));

    // Подгрузка картинок и завершение программы, если они не загрузились
    for (const auto& plant : plants)
        if (!plant->Setup())
            return -1;

    veroshka::Zombie* zombie = nullptr;
   
    veroshka::Circle* circle = nullptr;

    bool isStrikeEnable = false;

    // Цикл работает до тех пор, пока окно открыто
    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event))
        {
            // Обработка событий
            // Если нажат крестик, то
            if (event.type == sf::Event::Closed)
                // окно закрывается
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            sf::Vector2i mp = sf::Mouse::getPosition(window);

            if (zombie != nullptr)
                delete zombie;

            float sx = mp.x;
            float sy = mp.y;

            if (sx < 500)
                sx = 501;

            if (sx > 750)
                sx = 749;

            if (sy > 300)
                sy = 301;

            if (sy < 20)
                sy = 21;
           
            zombie = new veroshka::Zombie(sx, sy, 25);

            if (!zombie->Setup())
            {
                delete zombie;
                window.close();
                return -1;
            }

            /*t = 0;*/
        }

        // Движение зомби
        if (zombie != nullptr)
        {
            
            zombie->Move();
            int zx = zombie->GetX();

            if (zombie->GetX() == 500)
            {
                isStrikeEnable = true;
            }

        }

        if (circle != nullptr)
        {
       
            int zX = zombie->GetX();
            int cX = circle->GetX();
            circle->Move();
            
            if (zX == cX)
            {
                circle = nullptr;
                delete circle;
                zombie = nullptr;
                score++;
            }
        }

        if (isStrikeEnable)
        {
 
            int cx = 235;
            int cy = zombie->GetY();
            circle = new veroshka::Circle(cx, cy, 25);

            if(!circle->Setup())
            {
                delete circle;
                window.close();
            }

            isStrikeEnable = false;
        }
        
        // Вывод на экрна
        window.clear();

        // Вывод фона
        window.draw(back);
        window.draw(scoree);
        for (const auto& plant : plants)
            window.draw(*plant->Get());

        // Вывод счета
        text.setString(std::string("Score ") + std::to_string(score));
        text.setPosition(885, 385);
        window.draw(text);

        if (zombie != nullptr)
            window.draw(*zombie->Get());
        
        if (circle != nullptr)
            window.draw(*circle->Get());

        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(10ms);
        t += 0.02;
    }

    if (zombie != nullptr)
        delete zombie;

    if (circle != nullptr)
        delete circle;
    
    return 0;

}
