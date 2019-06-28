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
			printf("\n♬ 이용해주셔서 감사합니다. ♬\n\n");
			break;
		default:
			printf("\n※ 메뉴를 다시 선택해 주세요. ※\n");
			getchar();
			continue;
		}

		if (inputMenu == QUIT)
		{
			FreeCUS(); // 동적 할당 해제
			FreeDVD(); // 동적 할당 해제

			break;
		}
	}

	return 0;
}
