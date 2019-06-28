#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"
#include "manager.h"
#include "screenOut.h"

enum { SIGNIN = 1, CUSCHECK, MAIN1 };

void CustomerMenu()
{
	int i = 0;

	while (1)
	{
		ShowCustomerMenu();
		scanf("%d", &i);
		getchar();

		switch (i)
		{
		case SIGNIN:
			RegisterCustomer();
			break;
		case CUSCHECK:
			SearchCusInfo();
			break;
		case MAIN1:
			break;
		default:
			printf("\n※ 메뉴를 다시 선택해 주세요. ※\n");
			getchar();
			continue;
		}

		if (i == MAIN1)
			break;
	}
}

enum { DVDREGI = 1, DVDCHECK, DVDRENT, DVDTURNIN, DVDRENTRECORD, MAIN2 };

void DVDMenu()
{
	int j = 0;

	while (1)
	{
		ShowDVDMenu();
		scanf("%d", &j);
		getchar();

		switch (j)
		{
		case DVDREGI:
			RegistDVD();
			break;
		case DVDCHECK:
			SearchDVDInfo();
			break;
		case DVDRENT:
			rental_menu();
			break;
		case DVDTURNIN:
			re_turn_menu();
			break;
		case DVDRENTRECORD:
			infomation();
			break;
		case MAIN2:
			break;
		default:
			printf("\n※ 메뉴를 다시 선택해 주세요. ※\n");
			getchar();
			continue;
		}

		if (j == MAIN2)
			break;
	}
}