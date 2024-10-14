#pragma once
#include <string>
#include <array>
#include <vector>

void printLyric(std::array<std::string, TOTAL_LYRIC_LINES>& lyrics, std::array<std::string, 28>& visibleLyrics, short line, short& x, short& y, int& totalTime, char& asciiIndex);
void clearLyricWindow(std::array<std::string, 28>& visibleLyrics);
void handleLyrics(std::array<std::string, 28>& visibleLyrics, char& asciiIndex);
