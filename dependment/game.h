#include<xstring>
#include<windows.h>
#include"dependment\\dependment.h"
using namespace std;
using namespace custom;
using namespace game {
	string colors[10] = { "WHITE","RED","BLUE","PURPLE","YELLOW","GREEN","CYAN" };
	struct Player {
		int num = 0;
		string name="";
		int cost = 0;
	}plays[10];
	struct maps {
		int player=0, sz=0;
	}dt[10][10];
	void LocalPlay(int Gamemode, int PlayersCount, int MapSize)
	{
		if (Gamemode == 1)
		{
			system("cls");
			for (int i = 1; i <= MapSize; i++)
			{
				for (int j = 1; j <= MapSize; i++)
				{
					PrintC(char(dt[i][j].sz+'0'), colors[dt[i][j].player]);
					PrintC(' ', "WHITE");
				}
				putchar('\n');
			}
		}
	}
}