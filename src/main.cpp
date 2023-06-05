#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

using namespace sf;

int q = 0;
bool life = true;

const int H = 21;
const int W = 19;
const int ts = 25;

int mapId = 0;

String EasyMap[H] = {
	"AAAAAAAAAAAAAAAAAAA",
	"A1       A       2A",
	"A AA AAA A AAA AA A",
	"A        A        A",
	"A AA A AAAAA A AA A",
	"A    A   A   A    A",
	"AAAA AAA A AAA AAAA",
	"BBBA A   6   A ABBB",
	"AAAA A AAAAA A AAAA",
	"BBBB   ABBBA   BBBB",
	"AAAA A AAAAA A AAAA",
	"BBBA A   5   A ABBB",
	"AAAA A AAAAA A AAAA",
	"A        A        A",
	"A AA AAA A AAA AA A",
	"A  A     C     A  A",
	"AA A A AAAAA A A AA",
	"A    A   A   A    A",
	"A AAAAAA A AAAAAA A",
	"A3               4A",
	"AAAAAAAAAAAAAAAAAAA",
};

String NoTeleport[H] = {
	"AAAAAAAAAAAAAAAAAAA",
	"A1               2A",
	"A AA AAA A AAA AA A",
	"A        A        A",
	"A AA A AAAAA A AA A",
	"A    A       A    A",
	"AA A AAAAAAAAA A AA",
	"A  A A   6   A A  A",
	"A AAAA AA AA AAAA A",
	"A A    A   A    A A",
	"A AAAA AA AA AAAA A",
	"A  A A   5   A A  A",
	"AA A A AAAAA A A AA",
	"A        A        A",
	"A AA AAA A AAA AA A",
	"A  A     C     A  A",
	"AA A A AAAAA A A AA",
	"A    A   A   A    A",
	"A AAAAAA A AAAAAA A",
	"A3               4A",
	"AAAAAAAAAAAAAAAAAAA",
};

String ChaoticMap[H] = {
	"AAAAAAAAAAAAAAAAAAA",
	"A1               2A",
	"A                 A",
	"A                 A",
	"A                 A",
	"A                 A",
	"A                 A",
	"A        6        A",
	"A                 A",
	"A                 A",
	"A                 A",
	"A        5        A",
	"A                 A",
	"A                 A",
	"A                 A",
	"A        C        A",
	"A                 A",
	"A                 A",
	"A                 A",
	"A3               4A",
	"AAAAAAAAAAAAAAAAAAA",
};

String* MapPack[3] = { EasyMap, NoTeleport, ChaoticMap };

int countScoreToWin() {
	int count = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (MapPack[mapId][i][j] == ' ') {
				count++;
			}
		}
	}
	return count;
}

int menu() {
	int input = 0;
	std::cout << "Available difficulties:\n\t1)Easy (regular map)\n\t2)Medium (map with no teleports)\n\t3)Hard (blank chaotic map)\nChoose your difficulty (type 4 to exit): ";
	std::cin >> input;
	switch (input) {
	case 1:
		mapId = 0;
		break;
	case 2:
		mapId = 1;
		break;
	case 3:
		mapId = 2;
		break;
	case 4:
		break;
	default:
		std::cout << "wrong input\n";
	}
	return input;
}

void playGame() {
	int winCondition = countScoreToWin();
	life = 1;
	q = 0;

	srand(time(0));
	RenderWindow window(VideoMode(W * ts, H * ts), "Pacman");

	Texture t;
	t.loadFromFile("Sprites.png");
	Sprite plat(t);

	Texture yw;
	yw.loadFromFile("YouWin.png");
	Sprite youwin(yw);
	youwin.setPosition(100, 210);

	Texture yl;
	yl.loadFromFile("YouLose.png");
	Sprite youlose(yl);
	youlose.setPosition(100, 210);

	Player p;
	Enemy en;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();

			if (q < winCondition && life)
				if (event.type == Event::KeyPressed) {
					p.newx = p.x;
					p.newy = p.y;

					if (event.key.code == Keyboard::Right) p.rotate = 1;
					if (event.key.code == Keyboard::Left) p.rotate = 2;
					if (event.key.code == Keyboard::Up) p.rotate = 3;
					if (event.key.code == Keyboard::Down) p.rotate = 4;
				}
		}

		if (q < winCondition && life) {
			p.update();
			en.update();
		}
		window.clear(Color::Black);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (MapPack[mapId][i][j] == 'A') plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (MapPack[mapId][i][j] == 'C')
					plat.setTextureRect(
						IntRect(ts * int(p.frame), ts * p.rotate, ts, ts));
				if (MapPack[mapId][i][j] == ' ') plat.setTextureRect(IntRect(ts, 0, ts, ts));
				if (MapPack[mapId][i][j] == '1')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[0], ts, ts));
				if (MapPack[mapId][i][j] == '2')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[1], ts, ts));
				if (MapPack[mapId][i][j] == '3')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[2], ts, ts));
				if (MapPack[mapId][i][j] == '4')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[3], ts, ts));
				if (MapPack[mapId][i][j] == '5')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[4], ts, ts));
				if (MapPack[mapId][i][j] == '6')
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[5], ts, ts));
				if (MapPack[mapId][i][j] == 'B') continue;

				plat.setPosition(j * ts, i * ts);
				window.draw(plat);
			}

		if (q == winCondition) {
			window.draw(youwin);
		}
		if (!life) {
			window.draw(youlose);
		}

		window.display();
	}
}

int main() {
	while (menu() != 4) {
		playGame();
	}
	return 0;
}