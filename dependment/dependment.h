#pragma once

#include <windows.h>
#include <xstring>

#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7

using namespace std;

namespace custom {
	void PrintC(string PrintStr, char ColorCode = WHITE, int NewLine = 0);
	void SetColor(char ColorCode);
	void Pause(string Text = "Press Any Buttom To Continue...");

	void PrintC(string PrintStr, char ColorCode, int NewLine) {
		SetColor(ColorCode);
		for (char i : PrintStr) {
			putchar(i);
		}
		if (NewLine)putchar('\n');
	}
	void SetColor(char ColorCode) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode);
	}
	void Pause(string Text) {
		for (char i : Text) {
			putchar(i);
		}
		getchar();
	}
}
