#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

bool extern life;
int extern mapId;
sf::String extern* MapPack[3];

class Enemy {
public:
	int x[6] = { 1, 17, 1, 17, 9, 9 }, y[6] = { 1, 1, 19, 19, 11, 7 };
	int newx[6] = { 0, 0, 0, 0, 0, 0 }, newy[6] = { 0, 0, 0, 0, 0, 0 };
	int rotate[6] = { 1, 1, 1, 1, 1, 1 }, ti = 0;
	void update();
};

#endif //ENEMY_H