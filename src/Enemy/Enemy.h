#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

bool extern life;
int extern mapId;
sf::String extern* MapPack[3];

class Enemy {
public:
	int x[4] = { 1, 17, 1, 17 }, y[4] = { 1, 1, 19, 19 };
	int newx[4] = { 0, 0, 0, 0 }, newy[4] = { 0, 0, 0, 0 };
	int rotate[4] = { 1, 1, 1, 1 }, ti = 0;
	void update();
};

#endif //ENEMY_H