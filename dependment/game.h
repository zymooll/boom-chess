#pragma once

#include<xstring>
#include<windows.h>
#include<iostream>
#include<queue>
#include<stdio.h>
#include<cstdio>
#include"dependment\\dependment.h"
using namespace std;
using namespace custom;
namespace game {
	char colors[10] = { WHITE,RED,BLUE,PURPLE,YELLOW,GREEN,CYAN };
	struct Player {
		int num = 0;
		string name="";
		int cost = 0;
	}plays[10];
	struct maps {
		int player=0, sz=0;
	}dt[10][10];
	int vis[10],dt_max[10][10];
	struct BFS_CS {
		int x, y ,p, c;
	};
	queue<BFS_CS>q;
	int n;
	void BFS()
	{
		int dx[6] = { 0,1,-1,0,0 };
		int dy[6] = { 0,0,0,1,-1 };
		while (!q.empty())
		{
			BFS_CS cht = q.front(); q.pop();
			int x = cht.x, y = cht.y, p = cht.p, c = cht.c;
			for (int i = 1; i <= 4; i++)
			{
				int xx = x + dx[i], yy = y + dy[i];
				if (xx < 1 || yy<1 || xx >= n || yy>n) continue;
				dt[xx][yy].sz++;
				dt[xx][yy].player = p;
				while (dt[xx][yy].sz > dt_max[xx][yy]) q.push(BFS_CS{xx,yy,p,c+1}), dt[xx][yy].sz -= dt_max[xx][yy];
			}
		}
	}
	void LocalPlay(int Gamemode, int PlayersCount, int MapSize)
	{
		n = MapSize;
		int games_step=0;
		for (int i = 1; i <= MapSize; i++)
			for (int j = 1; j <= MapSize; j++)
				dt_max[i][j] = 3;
		for (int i = 2; i < MapSize; i++)
			for (int j = 2; j < MapSize; j++)
				dt_max[i][j] = 4;
		dt_max[1][1] = dt_max[1][MapSize] = dt_max[MapSize][1] = dt_max[MapSize][MapSize] = 2;
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
							PrintC(' ', WHITE);
						}
						putchar('\n');
					}
					int x, y;
					cin >> x >> y;
					if (x > MapSize || y > MapSize || x < 1 || y < 1)
					{
						PrintC("坐标已出界，请重新输入", WHITE, 1);
						Sleep(1000);
						goto player_start;
					}
					if(dt[x][y].player!=0&&dt[x][y].player!=k)
					{
						PrintC("此位置已被占领，请重新输入", WHITE, 1);
						Sleep(1000);
						goto player_start;
					}
					dt[x][y].player = k;
					dt[x][y].sz++;
					if (dt[x][y].sz >= dt_max[x][y])
						q.push({ x,y,dt[x][y].player,1}),
						BFS();
				}
				for (int i = 1; i <= PlayersCount; i++)
					if (plays[i].cost == 0 && vis[i] == 0) {
						string FailedPlayerName;
						FailedPlayerName += char('0' + i);
						PrintC("玩家" + FailedPlayerName +"失败", WHITE, 1), vis[i] = 1;
					}
			}
		}
	}
}