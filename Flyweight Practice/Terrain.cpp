#include "Texture.cpp"

class Terrain {
	int _movementCost = 0;
	Texture* _texture;

public:

	int GetMovementCost() const {
		return _movementCost;
	}
	Texture* GetTexture() const {
		return _texture;
	}

	Terrain(int movementCost, Texture* texture) {
		_movementCost = movementCost;
		_texture = texture;
	}
};