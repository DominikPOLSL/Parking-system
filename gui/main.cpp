#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "Plik.h"
#include "Point.h"
#include "Func.h"
#include <SFML/Graphics.hpp>


int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        

        std::vector<std::string>list = {}; //Code from matlab
        std::vector<std::string>list2 = {}; //Paring places coords
        Plik file;
        Plik coords;

        file.read(list, argv[1]);
        coords.read(list2, argv[2]);
        std::cout << "Available coords:\n";
        coords.show(list2);
        std::cout << "Current parking pose: " << list[0];

        //Free spaces on parking
        std::vector<Point>points = {};

        points.emplace_back(Point(0, 46, 86, 297, 305));
        points.emplace_back(Point(1, 46, 86, 369, 305));
        points.emplace_back(Point(2, 46, 86, 441, 417));

        //Background 
        sf::Sprite bg;
        sf::Text info;
        sf::Font a;
        sf::Texture bgT;
        bgSet(bg, info, a, bgT);

        bool choosed = false;
        bool test = true;
        int id;

        sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
        
        while (window.isOpen())
        {
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(position);

            if (!choosed && test)
                for (auto& x : points)
                {
                    if (x.shape.getGlobalBounds().contains(translated_pos) && !choosed)
                    {
                        x.color(sf::Color::Green);
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            test = false;
                            choosed = true;
                            id = x.getId();
                            break;
                        }
                    }
                    else if (!choosed)
                        x.color(sf::Color::Black);
                }

            if (finish(choosed, file, list, list2, id, argv[1]))
            {
                system("MatLab.exe");
                choosed = false; 
            }
            

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(bg);
            for (auto x : points)
                window.draw(x);
            window.draw(info);
            window.display();
        }     
        return 0;
    }
    else std::cout << "Brak argmunetow: 1.ParkingValetMap.m 2.coords.txt";
    return 0;
}