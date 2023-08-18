#include <iostream>
#include "World.cpp"
#include <windows.h>

#include <windows.h>

void SetColor(int fg)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	SetConsoleTextAttribute(hstdout, (csbi.wAttributes & 0xF0) | (fg & 0x0F));
}

void PrintMap(World* world) {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 200; j++) {
			SetColor(world->_tiles[i][j]->GetTexture()->GetColor());
			std::cout << world->_tiles[i][j]->GetTexture()->GetCharacter();
		}
		std::cout << std::endl;
	}
}

int main() {
	World* world = new World('^','~','0','-', 50, 25, 111, 40);

	PrintMap(world);
}