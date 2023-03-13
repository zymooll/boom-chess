#include<iostream>
#include<pthread.h>
#include<windows.h>
#include<WinSock2.h>
#include<conio.h>
#pragma comment(lib,"ws2_32.lib")
//客户端构建
//1、初始化
//2、创建一个接口并且对其初始化
//3、创建一个地址包 并且存入服务器地址
//4、尝试连接
//5、发送和接受
//=====================全局变量================
const int buf_size = 512;
char buf[buf_size] = {0};
std::string ippp;
//======================光标位置=====================
void Gotoxy(int x, int y) {
	COORD  coord;
	coord.X = y;
	coord.Y = x;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, coord);
}
//======================隐藏光标=====================
void Hide(int n) {
	CONSOLE_CURSOR_INFO cursor_info = {1, n};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
} //n default 0
//======================修改颜色=====================
void Color(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
//========================初始化=======================
bool start_up() {
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD (2, 2), &wsadata))
		return 1;
	return 0;
}
//=====================查看ip信息================
void read_inet_config() {
	system("ipconfig");
	system("pause");
	return;
}
//=====================输入ip地址================
const char* in_ip() {
	system("cls");
	Gotoxy(0, 0);
	printf("请输入ip地址\n");
	Color(7, 0);
	printf("默认\n127.0.0.1");
	Gotoxy(2, 0);
	getline(std::cin, ippp);
	if (ippp.size() == 0)
		return "127.0.0.1";
	return ippp.data();
}
//======================输入端口号========================
u_short in_host() {
	system("cls");
	Gotoxy(0, 0);
	printf("请输入端口\n");
	Color(7, 0);
	printf("默认\n5005");
	Gotoxy(2, 0);
	std::string host;
	getline(std::cin, host);
	if (host.size() == 0)
		return (u_short)5005;
	return (u_short)atoi(host.data());
}
//=========================获取本地ip=============
const char* Local_ip() {
	char szText[256];
	int iRet;
	iRet = gethostname(szText, 256);
	int a = WSAGetLastError();
	if (iRet != 0) {
		printf("\ngethostname Failed!\n");
		return "127.0.0.1";
	}
	HOSTENT* host = gethostbyname(szText);
	if (NULL == host) {
		printf("\ngethostbyname Failed!\n");
		return "127.0.0.1";
	}
	in_addr PcAddr;
	for (int i = 0;; i++) {
		char* p = host->h_addr_list[i];
		if (NULL == p) {
			break;
		}
		memcpy(&(PcAddr.S_un.S_addr), p, host->h_length);
		char* szIP = ::inet_ntoa(PcAddr);
		return szIP;
	}
}
//=================创建一个客户端的接受和发送接口==========
bool make_a_local_socket(SOCKET &sockettt, char * ip_v4, u_short hst) {
	sockettt = socket(AF_INET, SOCK_STREAM, 0);
	return 0;
}
//=================创建一个地址包==========
bool make_a_address_pack(SOCKADDR_IN & ccaddr, char * ip_v4, u_short hst) {
	ccaddr = {0};
	ccaddr.sin_addr.S_un.S_addr = inet_addr(ip_v4);
	ccaddr.sin_family = AF_INET;
	ccaddr.sin_port = htons(hst);
	return 0;
}
//=====================尝试连接服务器================
bool first_connect(SOCKET ccsock, SOCKADDR_IN ssssaddr) {
	if (connect(ccsock, (SOCKADDR*)&ssssaddr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		printf("\nfailed to connect!\nError code=%d", WSAGetLastError());
		return 1;
	}
	return 0;
}
//======================等待并接受===============
void * receive_data(SOCKET rc) {
	memset(buf, 0, sizeof(buf));
	if (recv(rc, buf, sizeof(buf), 0) > 0)
		return (void*)&buf;
	else
		return 0;
}
//======================发送====================
bool send_data(SOCKET sdc, void * sddata) {
	send(sdc, (char*)sddata, sizeof(sddata), 0);
	return 0;
}
//================接口服务器化=======================
bool socket_fwq(SOCKET ssssock, SOCKADDR_IN ssssaddr) {
	bind(ssssock, (SOCKADDR*)&ssssaddr, sizeof(SOCKADDR));
	listen(ssssock, 10);
	return 0;
}
//===================1145141919810========================
