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
	vis[10];
	void Win_or_lost()
	{
		for (int i = 1; i <= n; i++)
			if (plays[i].cost == 0 && vis[i] == 0)
				PrintC("玩家" + char('0' + i) + "失败", "WHITE", 1), vis[i] = 1;
	}
	void LocalPlay(int Gamemode, int PlayersCount, int MapSize)
	{
		int games_step=0;
		if (Gamemode == 1)
		{
			while(1)
			{
				games_step++;
				for (int k = 1; k <= PlayersCount; k++)
				{
					player_start:
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
					int x, y;
					cin >> x >> y;
					if (x > MapSize || y > MapSize || x < 1 || y < 1)
					{
						PrintC("坐标已出界，请重新输入", "WHITE", 1);
						Sleep(1000);
						goto player_start;
					}
					if(dt[x][y].player!=0&&dt[x][y].player!=i)
					{
						PrintC("坐标已出界，请重新输入", "WHITE", 1);
						Sleep(1000);
						goto player_start;
					}
				}
				Win_or_lost();
			}
		}
	}
}