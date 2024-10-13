#include <fstream>
#include <iostream>
#include "ascii.h"
#include "util.h"

void printFile(std::string filePath, short x, short y)
{
	setCursorPosition(x, y);
	
	if (std::ifstream is{ filePath, std::ios::binary | std::ios::ate })
	{
		auto size = is.tellg();
		std::string str(size, '\0'); 
		is.seekg(0);
		if (is.read(&str[0], size))
			std::cout << str << '\n';
	}
}

void printAscii(char index)
{
	std::ifstream fs;
	std::string asciiDir{ "assets/ascii/" };
	asciiDir += index;
	asciiDir += ".txt";
	fs.open(asciiDir);
	std::string temp;
	
	for (short i = 0; i < 20; ++i)
	{
		setCursorPosition(64, 9 + i);
		std::cout << "                                         ";
		setCursorPosition(64, 9 + i);
		std::getline(fs, temp);
		std::cout << temp;
	}
}


