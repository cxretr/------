#include"idsearch.h"

char *title = "身份查询验证系统";
#define MAX_CMD_SIZE 10

int main(int argc, char *argv[])
{
	char select[MAX_CMD_SIZE] = {0};
	while(1)
	{
		DrawFrame(title);
		DrawMenu();

		scanf("%s", select);
		if(strcmp(select,"1") == 0)
		{
			SearchID();
		}
		else if(strcmp(select, "2") == 0)
		{
			CheckID();
		}
		else if(strcmp(select, "exit") == 0)
			break;
		else {
			printf("输入有误\n");
			system("pause");
		}
	}

	SystemEnd();
	return 0;
}
