#include "Player.h"
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>

void Player::update() {
	frame += 0.01;
	if (frame > 5) frame -= 5;

	ti++;
	if (ti >= 400) {
		switch (rotate) {
		case 1:
			if (MapPack[mapId][y][newx + 1] != 'A') newx += 1;
			break;
		case 2:
			if (MapPack[mapId][y][newx - 1] != 'A') newx -= 1;
			break;
		case 3:
			if (MapPack[mapId][newy - 1][x] != 'A') newy -= 1;
			break;
		case 4:
			if (MapPack[mapId][newy + 1][x] != 'A') newy += 1;
			break;
		}

		ti = 0;
	}

	if (MapPack[mapId][newy][newx] == ' ' || MapPack[mapId][newy][newx] == 'B') {
		if (MapPack[mapId][newy][newx] == ' ') q++;

		if (MapPack[mapId][newy][newx] == '1' || MapPack[mapId][newy][newx] == '2' ||
			MapPack[mapId][newy][newx] == '3' || MapPack[mapId][newy][newx] == '4')
			life = false;

		MapPack[mapId][y][x] = 'B';

		MapPack[mapId][newy][newx] = 'C';

		x = newx;
		y = newy;
	}

	if (newy == 9 && (newx == 0 || newx == 18)) {
		if (newx == 0)
			newx = 17;
		else
			newx = 1;

		MapPack[mapId][y][x] = 'B';
		MapPack[mapId][newy][newx] = 'C';

		x = newx;
		y = newy;
	}
}