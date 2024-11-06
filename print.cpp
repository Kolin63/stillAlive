#include <string>
#include <array>
#include <iostream>
#include "print.h"
#include "util.h"
#include "ascii.h"

void print(std::array<std::string, 28>& visibleLyrics, std::array<std::string, 7>& visibleCredits, char& asciiIndex)
{
	for (short i{ 0 }; i < 27; ++i)
	{
		setCursorPosition(2, i + 1);
		std::cout << visibleLyrics[i];
	}
	for (short i{ 0 }; i < 7; ++i)
	{
		setCursorPosition(57, i + 1);
		std::cout << visibleCredits[i];
	}
	if (asciiIndex == '>') return;
	if (asciiIndex != '~') printAscii(asciiIndex);
	asciiIndex = '~';
}
