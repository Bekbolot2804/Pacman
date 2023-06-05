#include "Enemy.h"
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>

void Enemy::update() {
	ti++;
	if (ti >= 300) {
		for (int i = 0; i < 6; i++) {
			rotate[i] = rand() % 4 + 1;

			newx[i] = x[i];
			newy[i] = y[i];

			switch (rotate[i]) {
			case 1:
				if (MapPack[mapId][y[i]][newx[i] + 1] != 'A') newx[i] += 1;
				break;
			case 2:
				if (MapPack[mapId][y[i]][newx[i] - 1] != 'A') newx[i] -= 1;
				break;
			case 3:
				if (MapPack[mapId][newy[i] - 1][x[i]] != 'A') newy[i] -= 1;
				break;
			case 4:
				if (MapPack[mapId][newy[i] + 1][x[i]] != 'A') newy[i] += 1;
				break;
			}
		}

		ti = 0;
	}

	for (int i = 0; i < 6; i++) {
		if (MapPack[mapId][newy[i]][newx[i]] == ' ' ||
			MapPack[mapId][newy[i]][newx[i]] == 'B' ||
			MapPack[mapId][newy[i]][newx[i]] == 'C') {
			if (MapPack[mapId][newy[i]][newx[i]] == 'B')
				MapPack[mapId][y[i]][x[i]] = 'B';
			else if (MapPack[mapId][newy[i]][newx[i]] == ' ')
				MapPack[mapId][y[i]][x[i]] = ' ';
			else if (MapPack[mapId][newy[i]][newx[i]] == 'C')
				life = false;

			if (i == 0) MapPack[mapId][newy[i]][newx[i]] = '1';
			if (i == 1) MapPack[mapId][newy[i]][newx[i]] = '2';
			if (i == 2) MapPack[mapId][newy[i]][newx[i]] = '3';
			if (i == 3) MapPack[mapId][newy[i]][newx[i]] = '4';
			if (i == 4) MapPack[mapId][newy[i]][newx[i]] = '5';
			if (i == 5) MapPack[mapId][newy[i]][newx[i]] = '6';

			x[i] = newx[i];
			y[i] = newy[i];
		}

		if (newy[i] == 9 && (newx[i] == 0 || newx[i] == 18)) {
			if (newx[i] == 0)
				newx[i] = 17;
			else
				newx[i] = 1;

			MapPack[mapId][y[i]][x[i]] = 'B';

			if (i == 0) MapPack[mapId][newy[i]][newx[i]] = '1';
			if (i == 1) MapPack[mapId][newy[i]][newx[i]] = '2';
			if (i == 2) MapPack[mapId][newy[i]][newx[i]] = '3';
			if (i == 3) MapPack[mapId][newy[i]][newx[i]] = '4';
			if (i == 4) MapPack[mapId][newy[i]][newx[i]] = '5';
			if (i == 5) MapPack[mapId][newy[i]][newx[i]] = '6';

			x[i] = newx[i];
			y[i] = newy[i];
		}
	}
}