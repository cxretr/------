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
	system(buffer); //����ϵͳ����
	system("mode con cols=60 lines=20"); //���ÿ���̨�ĳ��ȺͿ��
	system("color 0F");//������ɫ

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
	//�����Լ����������ʵ��
	//���������
	SetCurPos((60-4-strlen(title))/2, 1);
	printf("%s", title);
	//�˳�����
	SetCurPos((60-4-strlen("exit �˳�ϵͳ."))/2 ,17);
	printf("%s", "exit �˳�ϵͳ.");

	//���û�ӭ��Ϣ
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

		//���ӵ���ʱ����
		//
	}


	SetCurPos((60-4-strlen("[1] ���֤�����ز�ѯ"))/2,7);
	printf("%s", "[1] ���֤�����ز�ѯ");
	SetCurPos((60-4-strlen("[2] ���֤�Ϸ�����֤"))/2,9);
	printf("%s", "[2] ���֤�Ϸ�����֤");
	DrawRow(2, 14);
	SetCurPos((60-4-strlen("������:>"))/2, 15);
	printf("%s", "������:>");
}