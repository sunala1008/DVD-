#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

void InitData(void)
{
	LoadCusListFromFile();
	LoadDVDListFromFile();
	LoadRentListFromFile();
}

void RegisterCustomer()
{
	char id[ID_LEN];
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	printf("\n================ 정 보 입 력 ================\n");

	printf("▷  ID    : ");
	scanf("%s", id);
		
	if (IsregitsID(id))
	{
		puts("\n※ 해당 ID는 사용 중 입니다.※ \n");
		printf("=============================================\n");
		getchar();
		getchar();
		return;
	}

	printf("▷  Name  : ");
	scanf("%s", name);
		
	printf("▷  Phone : ");
	scanf("%s", phone);
		
	AddCusInfo(id, name, phone);

	if (!AddCusInfo(id, name, phone))
	{
		printf("\n※ 데이터 저장이 실패하였습니다.※\n");
		getchar();
		return;
	}

	printf("\n▶ 회원 가입이 완료되었습니다. \n");
	printf("=============================================\n");
	getchar();
	getchar();
}

void SearchCusInfo()
{
	char id[ID_LEN];
	
	printf("\n▶ 찾을 회원의 ID를 입력하세요.\n");
	printf("▷  ID    : ");
	scanf("%s", id);

	cusInfo *idp = GetCusPtrByID(id);

	if (idp == 0)
	{
		printf("\n※ 존재하지 않는 ID 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		getchar();
		return;
	}

	ShowCustomerInfo(idp);
	
	printf("\n▶ 조회가 완료되었습니다.\n");
	printf("=============================================\n");
	getchar();
}

void RegistDVD()
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("\n================ 정 보 입 력 ================\n");
	printf("\n");
	ShowGenreMenu();
	printf("▷ ISBN     : ");
	gets(ISBN);
	
	if (IsRegistISBN(ISBN))
	{
		puts("\n※ 해당 DVD는 이미 등록되어있습니다. ※\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	printf("▷ Title    : ");
	gets(title);
	
	printf("▷ Genre    : ");
	scanf("%d", &genre);

	AddDVDInfo(ISBN, title, genre);

	if (!AddDVDInfo(ISBN, title, genre))
	{
		printf("\n※ 데이터 저장에 실패하였습니다. ※\n");
		getchar();
		return;
	}
	
	printf("\n▶ DVD 등록이 완료되었습니다.\n");
	printf("=============================================\n");
	
	getchar();
	getchar();
}


void SearchDVDInfo()
{
	char ISBN[ISBN_LEN];
	
	dvdInfo *isbnp;
	
	printf("\n================ 정 보 입 력 ================\n");

	printf("\n▶ 찾을 DVD의 ISBN를 입력하세요.\n");
	printf("▷ ISBN     : ");
	scanf("%s", ISBN);

	isbnp = GetDVDPtrByISBN(ISBN);

	if (isbnp == 0)
	{
		printf("\n※ 존재하지 않는 DVD 입니다. ※\n");
		printf("=============================================\n");
		getchar();
		getchar();
		return;
	}

	ShowDVDInfo(isbnp);
	
	printf("\n▶ 조회가 완료되었습니다.\n");
	printf("=============================================\n");
	getchar();
}