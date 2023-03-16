#include"sysframe.h"

void SetCurPos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO  cursor_info = {100, 0};
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor_info);
}

void DrawCol(int x, int y)
{
	int i;
	for(i=0; i<20; ++i)
	{
		SetCurPos(x, y+i);
		printf("||");
	}
}

void DrawRow(int x, int y)
{
	int i;
	for(i=0; i<56; ++i)
	{
		SetCurPos(x+i, y);
		printf("=");
	}
}

void DrawFrame(char *title)
{
	char buffer[MAX_TITLE_SIZE+6+1] = "title "; //6:title%20  1:\0
	strcat(buffer, title);
	system(buffer); //设置系统标题
	system("mode con cols=60 lines=20"); //设置控制台的长度和宽度
	system("color 0F");//设置颜色

	DrawCol(0, 0);
	DrawCol(58, 0);
	DrawRow(2, 0);
	DrawRow(2, 2);
	DrawRow(2, 16);
	DrawRow(2, 18);
}

void SystemEnd()
{
	SetCurPos(0, 19);
}

extern char *title;
bool   first_login = true;
void DrawMenu()
{
	//根据自己的需求进行实现
	//标题的设置
	SetCurPos((60-4-strlen(title))/2, 1);
	printf("%s", title);
	//退出设置
	SetCurPos((60-4-strlen("exit 退出系统."))/2 ,17);
	printf("%s", "exit 退出系统.");

	//设置欢迎信息
	if(first_login)
	{
		SetCurPos((60-4-strlen("cx"))/2, 7);
		printf("%s", "cx");
		char *welcome = "W e l C o m e  !";
		SetCurPos((60-4-strlen(welcome))/2, 9);

		char *p = welcome;
		while(*p != '\0')
		{
			printf("%c", *p++);
			Sleep(200);
		}
		first_login = false;
		Sleep(1000);

		//增加倒计时功能
		//
	}


	SetCurPos((60-4-strlen("[1] 身份证归属地查询"))/2,7);
	printf("%s", "[1] 身份证归属地查询");
	SetCurPos((60-4-strlen("[2] 身份证合法性验证"))/2,9);
	printf("%s", "[2] 身份证合法性验证");
	DrawRow(2, 14);
	SetCurPos((60-4-strlen("请输入:>"))/2, 15);
	printf("%s", "请输入:>");
}