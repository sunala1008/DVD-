#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

enum {CUSTOMER = 1, DVD, QUIT};

int main()
{
	int inputMenu = 0;
	InitData();

	while (1)
	{
		ShowMenu();
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu)
		{
		case CUSTOMER:
			CustomerMenu();
			break;
		case DVD:
			DVDMenu();
			break;
		case QUIT:
			printf("\n�� �̿����ּż� �����մϴ�. ��\n\n");
			break;
		default:
			printf("\n�� �޴��� �ٽ� ������ �ּ���. ��\n");
			getchar();
			continue;
		}

		if (inputMenu == QUIT)
		{
			FreeCUS(); // ���� �Ҵ� ����
			FreeDVD(); // ���� �Ҵ� ����

			break;
		}
	}

	return 0;
}
