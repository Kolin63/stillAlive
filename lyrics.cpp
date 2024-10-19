#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include "util.h"
#include "lyrics.h"
#include "ascii.h"
#pragma comment(lib, "winmm.lib") 

void printLyric(std::array<std::string, TOTAL_LYRIC_LINES>& lyrics, std::array<std::string, 28>& visibleLyrics, short line, short& x, short& y, int& totalTime, char& asciiIndex)
{
	int ms {};
	switch (lyrics[line][0])
	{
	case ('!'):
		ms += static_cast<int>((lyrics[line][1] - 48) * 10000);
		ms += static_cast<int>((lyrics[line][2] - 48) * 1000);
		switch (lyrics[line][3])
		{
		case (';'):
			totalTime = static_cast<int>(ms * 0.9473684);
			return;
		case ('w'): 
			waitMilliseconds(static_cast<int>(ms * 0.9473684));
			return;
		}
		ms += static_cast<int>((lyrics[line][3] - 48) * 416.667);
		ms += static_cast<int>((lyrics[line][4] - 48) * 41.6667);
		if (lyrics[line][5] == 'w')
		{
			waitMilliseconds(static_cast<int>(ms * 0.9473684));
			return;
		}
		totalTime = static_cast<int>(ms * 0.9473684);
		return;
	case (':'):
		asciiIndex = lyrics[line][1];
		totalTime = static_cast<int>(totalTime * 0.988);
		return;
	case ('}'):
		clearLyricWindow(visibleLyrics);
		y = 1;
		return;
	case ('&'):
		--y;
		++x;
		return;
	case (' '):
		++y;
		return;
	}

	for (short i{ 0 }; i < lyrics[line].size(); ++i)
	{
		visibleLyrics[y][++x - 2] = lyrics[line][i];
		waitMilliseconds(static_cast<int>(totalTime / lyrics[line].size()));
	}
	++y;
}

void clearLyricWindow(std::array<std::string, 28>& visibleLyrics)
{
	for (short i{ 1 }; i < 28; ++i)
	{
        visibleLyrics[i] = std::string(52, ' ');  // 52 spaces
	}
}

void handleLyrics(std::array<std::string, 28>& visibleLyrics, char& asciiIndex)
{
	short lyricX{};
	short lyricY{ 1 };
	int delay{};
	std::array<std::string, TOTAL_LYRIC_LINES> lyrics;

	std::ifstream fs;
	fs.open("assets/lyrics.txt");
	
	for (int i = 0; i < TOTAL_LYRIC_LINES; ++i)
	{
		std::string temp;
		std::getline(fs, temp);
		lyrics[i] = temp;
	}

	for (short i{ 2 }; i < TOTAL_LYRIC_LINES + 1; ++i)
    {
        if (lyrics[i - 1] != "&" && lyrics[i] != "&" && lyrics[i][0] != '!' && lyrics[i][0] != ':')
        {
            lyricX = 2;
        }
        if (i == 9)
        {
			PlaySound(TEXT("assets/stillAlive.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        printLyric(lyrics, visibleLyrics, i, lyricX, lyricY, delay, asciiIndex);
    }
}

