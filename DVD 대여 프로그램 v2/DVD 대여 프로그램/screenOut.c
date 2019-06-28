#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

void ShowMenu()
{
	system("cls"); // stdlib.h 안에 있음
	
	printf("┌─────── 메 인  메 뉴 ───────┐\n");
	printf("│                                          │\n");
	printf("│              1. 회원 메뉴                │\n");
	printf("│                                          │\n");
	printf("│              2. DVD  메뉴                │\n");
	printf("│                                          │\n");
	printf("│              3. 종     료                │\n");
	printf("│                                          │\n");
	printf("└─────────────────────┘\n");
	printf("▷ 선택  >>  ");
}

void ShowCustomerMenu()
{
	system("cls");

	printf("┌─────── 회 원  메 뉴 ───────┐\n");
	printf("│                                          │\n");
	printf("│              1. 회원 가입                │\n");
	printf("│                                          │\n");
	printf("│              2. 회원 조회                │\n");
	printf("│                                          │\n");
	printf("│              3. 메인 메뉴                │\n");
	printf("│                                          │\n");
	printf("└─────────────────────┘\n");
	printf("▷ 선택  >>  ");
}

void ShowDVDMenu()
{
	system("cls");

	printf("┌───────   DVD 메 뉴  ───────┐\n");
	printf("│                                          │\n");
	printf("│              1. DVD 등록                 │\n");
	printf("│                                          │\n");
	printf("│              2. DVD 조회                 │\n");
	printf("│                                          │\n");
	printf("│              3. DVD 대여                 │\n");
	printf("│                                          │\n");
	printf("│              4. DVD 반납                 │\n");
	printf("│                                          │\n");
	printf("│              5. DVD 대여 조회            │\n");
	printf("│                                          │\n");
	printf("│              6. 메 인 메 뉴              │\n");
	printf("│                                          │\n");
	printf("└─────────────────────┘\n");
	printf("▷ 선택  >>  ");
}

void ShowDVDInforMenu()
{
	system("cls");

	printf("┌──────  DVD  대여 조회  ──────┐\n");
	printf("│                                          │\n");
	printf("│       1. DVD 대여 이력 조회              │\n");
	printf("│                                          │\n");
	printf("│       2. 회원별 대여 DVD 이력 조회       │\n");
	printf("│                                          │\n");
	printf("│       3. DVD 메 뉴                       │\n");
	printf("│                                          │\n");
	printf("└─────────────────────┘\n");
	printf("▷ 선택  >>  ");
}

void ShowCustomerInfo(cusInfo *pCus)  // 고객 정보 출력
{
	printf("\n");
	printf("┌─────────────────────┐\n");
	printf("  ▶ ID        : %s\n", pCus->ID);
	printf("  ▶ Name      : %s\n", pCus->name);
	printf("  ▶ Phone     : %s\n", pCus->phoneNum);
	printf("└─────────────────────┘\n");

	getchar();
}

void ShowDVDInfo(dvdInfo * pDVD)     // DVD 정보 출력
{
	printf("\n");
	printf("┌─────────────────────┐\n");

	printf("   ▶ ISBN      : %s\n", pDVD->ISBN);
	printf("   ▶ Title     : %s\n", pDVD->title);
	
	ShowGenre(pDVD->genre);

	if (pDVD->rentState == RENTED)
	{
		printf("   ▶ 대여 중인 DVD 입니다.\n");
	}
	else
		printf("   ▶ 대여 가능한 DVD 입니다.\n");
	printf("└─────────────────────┘\n");
	getchar();
}

void ShowGenreMenu()
{
	printf("┌──────   장        르   ──────┐\n");
	printf("│                                          │\n");
	printf("│        1. ACTION        2. COMIC         │\n");
	printf("│                                          │\n");
	printf("│        3. SF            4. ROMANTIC      │\n");
	printf("│                                          │\n");
	printf("└─────────────────────┘\n");
}


void ShowGenre(int gen)             // 장르 출력
{
	if (gen == 1)
	{
		printf("   ▶ Gerne     : ACTION \n");
	}
	if (gen == 2)
	{
		printf("   ▶ Gerne     : COMIC \n");
	}
	if (gen == 3)
	{
		printf("   ▶ Gerne     : SF \n");
	}
	if (gen == 4)
	{
		printf("   ▶ Gerne     : ROMANTIC \n");
	}
}

void ShowCustomerInfoContinue(cusInfo * pCus)
{
	printf("┌─────────────────────┐\n");
	printf("   ▶ ID     : %s \n", pCus->ID);
	printf("   ▶ Name   : %s \n", pCus->name);
	printf("   ▶ Phone  : %s \n", pCus->phoneNum);
	printf("└─────────────────────┘\n\n");
}

void ShowDVDRentInfo(dvdRentInfo dvd)
{
	printf("┌─────────────────────┐\n");
	printf("   ▶ ID     : %s \n", dvd.cusID);
	printf("   ▶ ISBN   : %s \n", dvd.ISBN);
	printf("   ▶ 대여일 : %u \n", dvd.rentDay);
	printf("└─────────────────────┘\n");
}