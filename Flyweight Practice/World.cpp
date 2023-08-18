#include "Terrain.cpp"
#include <random>
#include <ctime>

class World {

	Texture grassTexture;
	Texture waterTexture;
	Texture rockTexture;
	Texture dirtTexture;

	Terrain grassTerrain;
	Terrain waterTerrain;
	Terrain rockTerrain;
	Terrain dirtTerrain;

public:
	Terrain* _tiles[500][200];

	World(char grassChar, char waterChar, char rockChar, char dirtChar, int grassColor, int waterColor, int rockColor, int DirtColor)
		:
		grassTexture(grassChar, grassColor),
		waterTexture(waterChar, waterColor),
		rockTexture(rockChar, rockColor),
		dirtTexture(dirtChar, DirtColor),
		grassTerrain(1, &grassTexture),
		waterTerrain(1, &waterTexture),
		rockTerrain(1, &rockTexture),
		dirtTerrain(1, &dirtTexture)
	{
		GenerateTerrain();
		GenerateRiver();
	}

	void GenerateTerrain() {

		for (int i = 0; i < 500; i++) {
			for (int j = 0; j < 200; j++) {
				srand(time(NULL) / (j + 1) * i);
				int randomInt = rand();

				if (randomInt % 2 == 0) {
					_tiles[i][j] = &grassTerrain;
				}
				else if (randomInt % 97 == 0) {
					_tiles[i][j] = &rockTerrain;
				}
				else {
					_tiles[i][j] = &dirtTerrain;
				}
			}
		}
	}

	void GenerateRiver() {

		srand(time(NULL));
		int randomInt = rand() % 500;

		for (int j = 0; j < 500; j++) {
			_tiles[randomInt][j] = &waterTerrain;
		}
	}
};