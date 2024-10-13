#include <fstream>
#include <array>
#include "util.h"
#include "credits.h"

void handleCredits(std::array<std::string, 7>& visibleCredits)
{
	std::ifstream fs;
	fs.open("assets/credits.txt");
	std::string credits[TOTAL_CREDITS_LINES + 14];

	for (short i = 0; i < TOTAL_CREDITS_LINES + 14; ++i)
	{
		std::string temp;
		std::getline(fs, temp);
		credits[i] = temp;
	}
	
	for (short line{ 0 }; line < TOTAL_CREDITS_LINES; ++line)
	{
		for (short visibleLine{ line }; visibleLine < line + 7; ++visibleLine)
		{
			visibleCredits[visibleLine - line] = "                                                ";
			for (short letter{ 0 }; letter < credits[visibleLine].size(); ++letter)
			{
				visibleCredits[visibleLine - line][letter] = credits[visibleLine][letter];
				waitMilliseconds(static_cast<int>(1 / credits[visibleLine].size() * 100));
			}
		}
	}

	return;
}

