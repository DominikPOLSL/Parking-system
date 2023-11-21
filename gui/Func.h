#pragma once

#include "Plik.h"
#include "Point.h"
#include <filesystem>

void bgSet(sf::Sprite &bg,sf::Text &info,sf::Font &a,sf::Texture &bgT)
{
    a.loadFromFile("arial.ttf");
    info.setFont(a);
    info.setCharacterSize(30);
    info.setString("Choose parking spot");
    info.setPosition(250, 200);
    bgT.loadFromFile("parking.png");
    bg.setTexture(bgT);
}

bool finish(bool choosed, Plik file,std::vector<std::string> &list, 
            std::vector<std::string>&list2,int id, std::string doc)
{
    if (choosed)
    {
        file.change(list, list2, id);
        file.save(list, doc);
        std::cout << "\nChoosed parking pos: " << list[0];
        std::cout << "\n\nChanged route map!\n";
        (id == 2) ? std::cout << "Current using routePlan1.mat\n" : std::cout << "Current using routePlan.mat\n";
        return true;
    }
    return false;
}
