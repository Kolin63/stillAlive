#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <string_view>
#include <chrono>
#include <thread>
#include <array>
#include "util.h"

void setConsoleColor(short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setCursorPosition(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x, y });
}

void waitMilliseconds(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

