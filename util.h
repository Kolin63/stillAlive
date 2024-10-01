#pragma once

void setCursorPosition(short x, short y);
void printFile(std::string filePath, short x, short y);
void setConsoleColor(short color);
int printLyric(std::string lyrics[], short line, short& x, short& y, int totalTime);
void parseLyrics(std::string lyrics[]);
void waitMilliseconds(int milliseconds);
void clearLyricWindow();
void printAscii(char index);
void clearAsciiWindow();

#define TOTAL_LYRIC_LINES 84 
