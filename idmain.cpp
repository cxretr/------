#include"idsearch.h"

char *title = "��ݲ�ѯ��֤ϵͳ";
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
			printf("��������\n");
			system("pause");
		}
	}

	SystemEnd();
	return 0;
}
