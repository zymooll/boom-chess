#include "./dependment/dependment.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <xstring>

using namespace std;
using namespace custom;

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