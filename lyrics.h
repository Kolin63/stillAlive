#pragma once
#include <string>
#include <array>
#include <vector>

int printLyric(std::vector<std::string> lyrics, short line, short& x, short& y, int totalTime);
void clearLyricWindow();
void handleLyrics(std::vector<std::string> visibleLyrics);
