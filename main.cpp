#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#pragma comment(lib, "winmm.lib") 

#include "util.h"

int main()
{
    setConsoleColor(6);
    printFile("assets/frame.txt", 0, 0);

    std::string lyrics[TOTAL_LYRIC_LINES];
    parseLyrics(lyrics);
    
    int delay{};
    short lyricX{ 2 };
    short lyricY{ 1 };

    for (short i{ 1 }; i < TOTAL_LYRIC_LINES; ++i)
    {
        if (lyrics[i - 1] != "&" && lyrics[i] != "&" && lyrics[i][0] != '!' && lyrics[i][0] != ':')
        {
            lyricX = 2;
        }
        if (i == 7)
        {
            PlaySound(TEXT("stillAlive.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        delay = printLyric(lyrics, i, lyricX, lyricY, delay);
    }

    char c;
    std::cin >> c;

    setConsoleColor(15);

    return 0;
}

