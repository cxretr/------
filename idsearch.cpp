#include"idsearch.h"

extern char *title;
#define MAX_ADDRESS_SIZE 100

void DrawSystemMenu()
{
	DrawFrame(title);
	//标题的设置
	SetCurPos((60-4-strlen(title))/2, 1);
	printf("%s", title);
	//退出设置
	SetCurPos((60-4-strlen("exit 退出系统."))/2 ,17);
	printf("%s", "exit 退出系统.");

	SetCurPos(10, 5);
	printf("%s", "请输入身份证号:");
}

void Search(char *id, char *addr)
{
	//首先验证id有效性//

	FILE *fp = fopen("id.dat", "r");
	if(fp == NULL)
	{
		
		SetCurPos((60 - 10 - strlen("归属地为:")) / 2, 10);
		printf("数据库文件不存在....\n");
		return;
	}
	char info[7] = {0}; //000000
	strncpy(info, id, 6);

	char *result;
	char dest[MAX_ADDRESS_SIZE] = {0};
	while(!feof(fp))
	{
		fgets(dest, MAX_ADDRESS_SIZE, fp);
		result = strstr(dest, info);
		if(result != NULL)
		{
			strcpy(addr, result+7);
			break;
		}
		else {
			strcpy(addr,"无效身份证");
		}
		memset(dest, 0, MAX_ADDRESS_SIZE);
	}

	fclose(fp);
}
void SearchID()
{
	DrawSystemMenu();
	char id[19] = {0};
	scanf("%s", id);

	char address[MAX_ADDRESS_SIZE] = {0};
	Search(id, address);

	DrawRow(2, 8);
	SetCurPos((60-4-strlen("归属地为:"))/2, 9);
	printf("%s", "归属地为:");
	SetCurPos((60-4-strlen(address))/2, 10);
	printf("%s", address);

	SetCurPos((60-4-strlen("请按任意键继续..."))/2, 12);
	system("pause");
}

//char *id = "410103198902291933";
bool Check(char *id)
{
	int len = strlen(id);
	if(len != 18)
		return false;
	           //0 1 2  3 4 5 6 7 8 9 10 11 12 13 14 15 16
	int W[17] = {7,9,10,5,8,4,2,1,6,3,7, 9, 10,5, 8, 4, 2};
	int C[11] = {1,0,88,9,8,7,6,5,4,3,2};

	//1加权求和
	int sum = 0;
	for(int i=0; i<17; ++i)
	{
		sum += (id[i]-'0')*W[i];
	}
	//2 取模
	int mod = sum % 11;

	//3 校验
	if(C[mod] == (id[17]-'0'))
		return true;
	return false;
}
void CheckID()
{
	DrawSystemMenu();
	char id[19] = {0};
	scanf("%s", id);

	bool flag = Check(id); // true  false

	DrawRow(2, 8);
	if(flag)
	{
		SetCurPos((60-4-strlen("此身份证为:合 法"))/2, 9);
		printf("%s", "此身份证为:合 法");

	}
	else
	{
		system("color 04");
		SetCurPos((60-4-strlen("此身份证为:非 法"))/2, 9);
		printf("%s", "此身份证为:非 法");
	}

	SetCurPos((60-4-strlen("请按任意键继续..."))/2, 12);
	system("pause");
}