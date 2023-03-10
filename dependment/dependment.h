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
	void PrintC(char PrintChar, char ColorCode = WHITE, int NewLine = 0);
	void SetColor(char ColorCode);
	void Pause(string Text = "Press Any Buttom To Continue...");
	void Cls();
	int StrToInt(string _String);

	void PrintC(string PrintStr, char ColorCode, int NewLine) {
		SetColor(ColorCode);
		for (char i : PrintStr) {
			putchar(i);
		}
		if (NewLine)putchar('\n');
	}
	void PrintC(char PrintChar, char ColorCode, int NewLine) {
		SetColor(ColorCode);
		putchar(PrintChar);
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
	void Cls() {
		system("cls");
	}
	int StrToInt(string _String) {
		int x = 0, f = 1;
		for (char i : _String) {
			if (i < '0' || i>'9')return INT_MAX;
			if (i == '-')f = -1;
		}
		for (char i : _String) {
			if (i >= '0' && i <= '9')x = x * 10 + i - '0';
		}
		return x * f;
	}
}
