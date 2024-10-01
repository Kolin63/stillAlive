#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <string_view>
#include <chrono>
#include <thread>
#include "util.h"

void setConsoleColor(short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	
}

void setCursorPosition(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x, y });
}

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

void parseLyrics(std::string lyrics[])
{
	std::ifstream fs;
	fs.open("assets/lyrics.txt");
	std::string temp;
	
	for (int i = 0; i < TOTAL_LYRIC_LINES; ++i)
	{
		std::getline(fs, temp);
		lyrics[i] = temp;
	}
}

int printLyric(std::string lyrics[], short line, short& x, short& y, int totalTime)
{
	std::string_view temp{ lyrics[line] };

	if (temp[0] == '!')
	{
		short delaz{};
		delaz += (static_cast<int>(temp[1]) - 48) * 10000;
		delaz += (static_cast<int>(temp[2]) - 48) * 1000;
		if (temp[3] == ';')
			return delaz;
		if (temp[3] == 'w')
		{
			waitMilliseconds(delaz);
			return totalTime;
		}
		
		delaz += (static_cast<int>(temp[3]) - 48) * 100;
		delaz += (static_cast<int>(temp[4]) - 48) * 10;
		delaz += (static_cast<int>(temp[5]) - 48) * 1;

		if (temp[6] == 'w')
		{
			waitMilliseconds(delaz);
			return totalTime;
		}

		return delaz;
	}
	else if (temp == ";")
	{
		y = 1;
	}
	else if (temp == " ")
	{
		y += 1;
		return totalTime;
	}
	else if (temp == "}")
	{
		clearLyricWindow();
		x = 1;
		y = 1;
		return totalTime;
	}
	else if (temp[0] == ':')
	{
		if (temp[1] == 'c') clearAsciiWindow();
		printAscii(temp[1]);
		++y;
		return totalTime;
	}
	
	setCursorPosition(x, y);
	std::cout << ' ';

	for (short i{ 0 }; i < lyrics[line].size(); ++i)
	{
		if (temp[i] == '\\')
		{
			setCursorPosition(x + 1, y + 1);
			++y;
		}
		else
		{
			std::cout << lyrics[line][i]; 
		}

		waitMilliseconds(static_cast<int>(totalTime / temp.size()));
	}
	y += 1;
	return totalTime;
}

void waitMilliseconds(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void clearLyricWindow()
{
	for (short i{ 1 }; i < 28; ++i)
	{
		setCursorPosition(1, i);
		std::cout << "                                                     ";
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
		std::getline(fs, temp);
		std::cout << temp;
	}
}

void clearAsciiWindow()
{
}
