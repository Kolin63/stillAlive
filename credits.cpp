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

	waitMilliseconds(8800);
	
	for (short line{ 0 }; line < TOTAL_CREDITS_LINES; ++line)
	{
		for (short visibleLine{ line }; visibleLine < line + 7; ++visibleLine)
		{
			visibleCredits[visibleLine - line] = "                                                ";
			for (short letter{ 0 }; letter < credits[visibleLine].size(); ++letter)
			{
				visibleCredits[visibleLine - line][letter] = credits[visibleLine][letter];
				if (credits[visibleLine][letter] == ' ' && credits[visibleLine].size() == 1 && visibleLine == line + 6)
				{
					waitMilliseconds(100);
					continue;
				}
				if (visibleLine == line + 6)
					waitMilliseconds(static_cast<int>(1000 / credits[visibleLine].size()));
			}
		}
	}

	return;
}

