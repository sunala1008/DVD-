#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"
#include "manager.h"

#define RENT_LEN 100
#define RENT_BACKUP_FILE "rentInfo.dat"

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

enum { DVDSEL = 1, CUSSEL, MAIN3 };

// ↓ 대여 ↓
void rental_menu()
{
	char cus[NAME_LEN];          // 대여 고객 ID
	char isbn[ISBN_LEN];         // 대여 DVD ISBN
	unsigned int date;           // 대여 날짜

	int registDVD;
	int registCus;
	int rentState;

	printf("\n================ 정 보 입 력 ================\n");

	printf("▷  ID                   : ");
	gets(cus);

	if (!IsregitsID(cus))
	{
		puts("\n※ 존재하지 않는 ID 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}
	
	printf("▷  ISBN                 : ");
	gets(isbn);

	dvdInfo *dp = GetDVDPtrByISBN(isbn);

	if (!IsRegistISBN(isbn))
	{
		printf("\n※ 존재하지 않는 DVD 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	if (dp->rentState == RENTED)
	{
		printf("\n※ 대여중인 DVD이므로 대여가 불가능합니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}
	
	printf("▷  대여 날짜 (YYYYMMDD) : ");
	scanf("%d", &date);

	SetDVDRented(isbn);

	AddRentList(isbn, cus, date);

	printf("\n▶ DVD가 대여되었습니다.\n");
	printf("=============================================\n");
	
	getchar();
	getchar();
}

// DVD 대여
int SetDVDRented(char * ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;

	pDVD->rentState = RENTED;

	StoreDVDListToFile(); // 대여 시 백업

	return 1;
}

// 대여 정보 저장
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;

	numOfRentCus++;

	// 대여 이력이 추가될 경우 백업
	StoreRentListToFile();
}



// ↓ 반납  ↓ return
void re_turn_menu()
{
	char isbn[ISBN_LEN];

	int registDVD;
	int rentState;

	printf("\n================ 정 보 입 력 ================\n");

	printf("▶ 반납할 DVD의 ISBN을 입력하세요\n");
	printf("▷  ISBN    : ");
	gets(isbn);

	rentState = GetDVDRentState(isbn);

	if (!IsRegistISBN(isbn))
	{
		printf("\n※ 존재하지 않는 DVD 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	if (rentState == RETURNED)
	{
		printf("\n※ 대여되지 않은 DVD입니다. ※\n");			
		printf("=============================================\n");
		getchar();
		return;
	}

	turnin(isbn);

	printf("\n▶ DVD가 반납되었습니다.\n");
	printf("=============================================\n");	

	getchar();
	//getchar();//여기 x
}

// DVD 반납
void turnin(char * isbn)
{
	dvdInfo * rtp = GetDVDPtrByISBN(isbn);

	if (rtp == 0)
		return 0;

	rtp->rentState = RETURNED;

	StoreDVDListToFile(); // 반납 시 백업

	return 1;
}

// DVD 대여 상태 조회
int GetDVDRentState(char * ISBN)
{
	dvdInfo * dp = GetDVDPtrByISBN(ISBN);

	if (dp == 0)
		return -1;

	return dp->rentState;
}



//  ↓ 검색 조회 ↓ search
void infomation()
{
	int j;
	
	while (1)
	{
		ShowDVDInforMenu();
		scanf("%d", &j);
		getchar();

		switch (j)
		{
		case DVDSEL:
			dvd_sellect();
			break;
		case CUSSEL:
			cus_sellect();
			break;
		case MAIN3:
			break;
		default:
			printf("\n※ 메뉴를 다시 선택해 주세요. ※\n");
			getchar();
			continue;
		}
		
		if (j == MAIN3)
			break;
	}
}

void dvd_sellect()
{
	char isbn[ISBN_LEN];

	printf("\n================ 정 보 입 력 ================\n");

	printf("▶ DVD의 ISBN를 입력하세요.\n");
	printf("▷  ISBN    : ");
	gets(isbn);

	dvdInfo *infop = GetDVDPtrByISBN(isbn);

	if (infop == 0)
	{
		printf("\n※ 존재하지 않는 DVD 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	findcusID(isbn);

	printf("\n▶ 조회가 완료되었습니다.\n");
	printf("=============================================\n");
	getchar();
}

// 검색 조건 : ISBN
void findcusID(char * isbn)
{
	int i;

	for (i = 0; i < numOfRentCus; i++)
	{
		if (!strcmp(rentList[i].ISBN, isbn))
		{
			cusInfo * cusp = GetCusPtrByID(rentList[i].cusID);

			printf("\n");
			printf("┌─────────────────────┐\n");
			printf("   ▶ ID        : %s \n", cusp->ID);
			printf("   ▶ Name      : %s \n", cusp->name);
			printf("   ▶ Phone     : %s \n", cusp->phoneNum);
			printf("   ▶ Rent day  : %d \n", rentList[i].rentDay);
			printf("└─────────────────────┘\n");
		}
	}
}

void cus_sellect()
{
	char id[NAME_LEN];
	unsigned int date1 = 0;
	unsigned int date2 = 0;
	
	printf("\n================ 정 보 입 력 ================\n");

	printf("▶ 회원 ID와 기간을 입력하세요.\n");
	printf("▷  ID                         : ");
	gets(id);

	cusInfo * cselp = GetCusPtrByID(id);

	if (cselp == 0)
	{
		printf("\n※ 존재하지 않는 ID 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}
	
	printf("▷ 조회 시작 날짜 (YYYYMMDD)   : ");
	scanf("%d", &date1);

	printf("▷ 조회 마지막 날짜 (YYYYMMDD) : ");
	scanf("%d", &date2);

	if (date1 > date2)
	{
		swap(&date1, &date2);
	}
	
	findDVD(id, date1, date2);

	printf("\n▶ 조회가 완료되었습니다.\n");
	printf("=============================================\n");
	getchar();
	getchar();
	
}

// 검색 조건 : 고객 ID 와 기간
void findDVD(char * ID, unsigned int start, unsigned int end)
{
	int i;

	for (i = 0; i < numOfRentCus; i++)
	{
		if (!strcmp(rentList[i].cusID, ID))
		{
			if (start <= rentList[i].rentDay && rentList[i].rentDay <= end)
				ShowDVDRentInfo(rentList[i]);
		}
	}
}

/*
void date_swap(dvdRentInfo dvdary)
{
	//dvdRentInfo * rentary[RENT_LEN];

	int o, i;

	dvdRentInfo * temp;

	for (o = 0; o < RENT_LEN - 1; o++)
	{
		for (i = 0; i < (RENT_LEN - o) - 1; i++)
		{
			if (rentList[i].rentDay > rentList[i + 1].rentDay)
			{
				temp = rentList[i].rentDay;
				rentList[i].rentDay = rentList[i + 1].rentDay;
				rentList[i + 1].rentDay = temp;
			}
		}
	}
}
*/

// 파일 입력
void StoreRentListToFile(void)
{
	FILE * fp = fopen(RENT_BACKUP_FILE, "wb");

	if (fp == NULL)
	{
		return;
	}

	// 이력건수(numOfRentCus)를 fp에 (int형 사이즈) 1건 씀
	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
	// 


	fclose(fp);
}

// 대여 이력 리스트를 파일로부터 복구하는 함수
void LoadRentListFromFile(void)
{
	FILE * fp = fopen(RENT_BACKUP_FILE, "rb");

	if (fp == NULL)
	{
		return;
	}

	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);

	fclose(fp);
}