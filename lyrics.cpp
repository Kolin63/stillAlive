//#include <mmsystem.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include "util.h"
#include "lyrics.h"
#include "ascii.h"
#pragma comment(lib, "winmm.lib") 

void parseLyrics(std::vector<std::string> lyrics)
{
	
}

int printLyric(std::vector<std::string> lyrics, short line, short& x, short& y, int totalTime)
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
		if (temp[5] == 'w')
		{
			waitMilliseconds(delaz);
			return totalTime;
		}

		return delaz;
	}
	else if (temp == " ")
	{
		++y;
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
		printAscii(temp[1]);
		++line;
		return totalTime;
	}
	else if (temp == "&")
	{
		++line;
		return totalTime;
	}
	
	if (line != 0)
	if (lyrics[line - 1] == "&")
	{
		++x;
		--y;
	}
	for (short i{ 0 }; i < lyrics[line].size(); ++i)
	{
		setCursorPosition(++x, y);
		std::cout << temp[i]; 

		waitMilliseconds(static_cast<int>(totalTime / temp.size()));

		
	}
	y += 1;

	return totalTime;
}

void clearLyricWindow()
{
	for (short i{ 1 }; i < 28; ++i)
	{
		setCursorPosition(1, i);
		std::cout << "                                                     ";
	}
}

void handleLyrics(std::vector<std::string> visibleLyrics)
{
	short lyricX{};
	short lyricY{};
	int delay{};
	std::vector<std::string> lyrics(TOTAL_LYRIC_LINES);

	std::ifstream fs;
	fs.open("assets/lyrics.txt");
	
	for (int i = 0; i < TOTAL_LYRIC_LINES; ++i)
	{
		std::string temp;
		std::getline(fs, temp);
		lyrics[i] = temp;
	}

	for (short i{ 1 }; i < TOTAL_LYRIC_LINES + 1; ++i)
    {
        if (lyrics[i - 1] != "&" && lyrics[i] != "&" && lyrics[i][0] != '!' && lyrics[i][0] != ':')
        {
            lyricX = 2;
        }
        if (i == 7)
        {
			//PlaySound(TEXT("assets/stillAlive.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        delay = printLyric(lyrics, i, lyricX, lyricY, delay);
    }
}

