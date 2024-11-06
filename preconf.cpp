#include <iostream>
#include <fstream>
#include <Windows.h>

int main()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	for (short i{ 0 }; i < 50; ++i) std::cout << std::string(111, ' ');
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	for (short i{ 0 }; i < 111; ++i) std::cout << '-';
	std::cout << '\n';
	for (short i{ 0 }; i < 29-1; ++i) std::cout << "|\n";
}
