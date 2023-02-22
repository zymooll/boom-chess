#include "./dependment/dependment.h"
#include "./dependment/game.h"
#include "./dependment/network.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <xstring>

using namespace std;
using namespace custom;
using namespace game;
//using namespace network;

void Init();
void Lobby();

void Init() {

	return;
}
void Lobby() {
	PrintC("Boom Chess\n1:Play\n2:Help\n0:Exit\n>");
	while (1) {
		char opt = getchar();
		if (opt == '1') {
			PrintC("1:Local Play\n2:Online Play\n0:Back\n>");
			while (1) {
				char opt = getchar();
				if (opt == '1') {
					PrintC("1:Standard Game\n0:Back\n>");
					while (1) {
						char opt = getchar();
						const int MaxGameMode = 1;
						int GameMode = 0, PlayersCount = 0, MapSize = 0;
						if (opt >= '1' && opt <= '9' && opt < MaxGameMode) {
							GameMode = opt - '0';
							PrintC("How many people play this game?\n>");
							string opts;
							cin >> opts;
							/*
							int num = StrToNum(opts);
							if () {

							}
							else {
								PrintC("Invalid Input.\n");
								Pause();
								Cls();
							}
							*/
						}
						else if (opt == '0') {
							break;
						}
					}
				}
				else if (opt == '2') {
					PrintC("There is nothing here...\n");
					Pause();
				}
				else if (opt == '0') {
					break;
				}
			}
		}
		else if (opt == '2') {
			PrintC("There is nothing here...\n");
			Pause();
		}
		else if (opt == '0') {
			exit(0);
		}
	}
}

int main() {
	Init();
	Lobby();
	return 0;
}