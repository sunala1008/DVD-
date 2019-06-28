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

	printf("\n================ �� �� �� �� ================\n");

	printf("��  ID    : ");
	scanf("%s", id);
		
	if (IsregitsID(id))
	{
		puts("\n�� �ش� ID�� ��� �� �Դϴ�.�� \n");
		printf("=============================================\n");
		getchar();
		getchar();
		return;
	}

	printf("��  Name  : ");
	scanf("%s", name);
		
	printf("��  Phone : ");
	scanf("%s", phone);
		
	AddCusInfo(id, name, phone);

	if (!AddCusInfo(id, name, phone))
	{
		printf("\n�� ������ ������ �����Ͽ����ϴ�.��\n");
		getchar();
		return;
	}

	printf("\n�� ȸ�� ������ �Ϸ�Ǿ����ϴ�. \n");
	printf("=============================================\n");
	getchar();
	getchar();
}

void SearchCusInfo()
{
	char id[ID_LEN];
	
	printf("\n�� ã�� ȸ���� ID�� �Է��ϼ���.\n");
	printf("��  ID    : ");
	scanf("%s", id);

	cusInfo *idp = GetCusPtrByID(id);

	if (idp == 0)
	{
		printf("\n�� �������� �ʴ� ID �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		getchar();
		return;
	}

	ShowCustomerInfo(idp);
	
	printf("\n�� ��ȸ�� �Ϸ�Ǿ����ϴ�.\n");
	printf("=============================================\n");
	getchar();
}

void RegistDVD()
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("\n================ �� �� �� �� ================\n");
	printf("\n");
	ShowGenreMenu();
	printf("�� ISBN     : ");
	gets(ISBN);
	
	if (IsRegistISBN(ISBN))
	{
		puts("\n�� �ش� DVD�� �̹� ��ϵǾ��ֽ��ϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	printf("�� Title    : ");
	gets(title);
	
	printf("�� Genre    : ");
	scanf("%d", &genre);

	AddDVDInfo(ISBN, title, genre);

	if (!AddDVDInfo(ISBN, title, genre))
	{
		printf("\n�� ������ ���忡 �����Ͽ����ϴ�. ��\n");
		getchar();
		return;
	}
	
	printf("\n�� DVD ����� �Ϸ�Ǿ����ϴ�.\n");
	printf("=============================================\n");
	
	getchar();
	getchar();
}


void SearchDVDInfo()
{
	char ISBN[ISBN_LEN];
	
	dvdInfo *isbnp;
	
	printf("\n================ �� �� �� �� ================\n");

	printf("\n�� ã�� DVD�� ISBN�� �Է��ϼ���.\n");
	printf("�� ISBN     : ");
	scanf("%s", ISBN);

	isbnp = GetDVDPtrByISBN(ISBN);

	if (isbnp == 0)
	{
		printf("\n�� �������� �ʴ� DVD �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		getchar();
		return;
	}

	ShowDVDInfo(isbnp);
	
	printf("\n�� ��ȸ�� �Ϸ�Ǿ����ϴ�.\n");
	printf("=============================================\n");
	getchar();
}