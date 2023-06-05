#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

bool extern life;
int extern q;
int extern mapId;
sf::String extern* MapPack[3];

class Player {
public:
    float frame = 0;
    int x = 9, y = 15;
    int newx = 0, newy = 0;
    int rotate = 1, ti = 0;
    void update();
};

#endif //PLAYER_H