#include <iostream>
#include <thread>
#include <string>
#include <array>
#include "util.h"
#include "credits.h"
#include "lyrics.h"
#include "ascii.h"
#include "print.h"

int main()
{
    setConsoleColor(6);
    hideCursor();
    setConsoleTitle();
    printFile("assets/frame.txt", 0, 0);

    std::array<std::string, 28> visibleLyrics; 
    std::array<std::string, 7> visibleCredits;
    char asciiIndex{ '~' };
    for (short i{ 0 }; i < 28; ++i)
    {
        visibleLyrics[i] = std::string(52, ' ');  
        if (i < 7) visibleCredits[i] = std::string(52, ' ');  
    }

    std::thread creditsThread{ handleCredits, std::ref(visibleCredits) };
    std::thread lyricsThread{ handleLyrics, std::ref(visibleLyrics), std::ref(asciiIndex) };


    while (true)
    {
        print(visibleLyrics, visibleCredits, asciiIndex);
        if (asciiIndex == '>')
        {
            creditsThread.join();
            lyricsThread.join();
            setConsoleColor(15);
            return 0;
        }
    }

    setConsoleColor(15);
    return 0;
}

