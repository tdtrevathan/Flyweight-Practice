class Texture {

	char _textureChar;
	int _color;

public:
	char GetCharacter() {
		return _textureChar;
	}
	int GetColor() {
		return _color;
	}
	Texture(char textureChar, int color) {
		_textureChar = textureChar;
		_color = color;
	}
};