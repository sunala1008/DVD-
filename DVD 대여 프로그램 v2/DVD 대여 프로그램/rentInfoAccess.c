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

// �� �뿩 ��
void rental_menu()
{
	char cus[NAME_LEN];          // �뿩 �� ID
	char isbn[ISBN_LEN];         // �뿩 DVD ISBN
	unsigned int date;           // �뿩 ��¥

	int registDVD;
	int registCus;
	int rentState;

	printf("\n================ �� �� �� �� ================\n");

	printf("��  ID                   : ");
	gets(cus);

	if (!IsregitsID(cus))
	{
		puts("\n�� �������� �ʴ� ID �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}
	
	printf("��  ISBN                 : ");
	gets(isbn);

	dvdInfo *dp = GetDVDPtrByISBN(isbn);

	if (!IsRegistISBN(isbn))
	{
		printf("\n�� �������� �ʴ� DVD �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	if (dp->rentState == RENTED)
	{
		printf("\n�� �뿩���� DVD�̹Ƿ� �뿩�� �Ұ����մϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}
	
	printf("��  �뿩 ��¥ (YYYYMMDD) : ");
	scanf("%d", &date);

	SetDVDRented(isbn);

	AddRentList(isbn, cus, date);

	printf("\n�� DVD�� �뿩�Ǿ����ϴ�.\n");
	printf("=============================================\n");
	
	getchar();
	getchar();
}

// DVD �뿩
int SetDVDRented(char * ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;

	pDVD->rentState = RENTED;

	StoreDVDListToFile(); // �뿩 �� ���

	return 1;
}

// �뿩 ���� ����
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;

	numOfRentCus++;

	// �뿩 �̷��� �߰��� ��� ���
	StoreRentListToFile();
}



// �� �ݳ�  �� return
void re_turn_menu()
{
	char isbn[ISBN_LEN];

	int registDVD;
	int rentState;

	printf("\n================ �� �� �� �� ================\n");

	printf("�� �ݳ��� DVD�� ISBN�� �Է��ϼ���\n");
	printf("��  ISBN    : ");
	gets(isbn);

	rentState = GetDVDRentState(isbn);

	if (!IsRegistISBN(isbn))
	{
		printf("\n�� �������� �ʴ� DVD �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	if (rentState == RETURNED)
	{
		printf("\n�� �뿩���� ���� DVD�Դϴ�. ��\n");			
		printf("=============================================\n");
		getchar();
		return;
	}

	turnin(isbn);

	printf("\n�� DVD�� �ݳ��Ǿ����ϴ�.\n");
	printf("=============================================\n");	

	getchar();
	//getchar();//���� x
}

// DVD �ݳ�
void turnin(char * isbn)
{
	dvdInfo * rtp = GetDVDPtrByISBN(isbn);

	if (rtp == 0)
		return 0;

	rtp->rentState = RETURNED;

	StoreDVDListToFile(); // �ݳ� �� ���

	return 1;
}

// DVD �뿩 ���� ��ȸ
int GetDVDRentState(char * ISBN)
{
	dvdInfo * dp = GetDVDPtrByISBN(ISBN);

	if (dp == 0)
		return -1;

	return dp->rentState;
}



//  �� �˻� ��ȸ �� search
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
			printf("\n�� �޴��� �ٽ� ������ �ּ���. ��\n");
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

	printf("\n================ �� �� �� �� ================\n");

	printf("�� DVD�� ISBN�� �Է��ϼ���.\n");
	printf("��  ISBN    : ");
	gets(isbn);

	dvdInfo *infop = GetDVDPtrByISBN(isbn);

	if (infop == 0)
	{
		printf("\n�� �������� �ʴ� DVD �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}

	findcusID(isbn);

	printf("\n�� ��ȸ�� �Ϸ�Ǿ����ϴ�.\n");
	printf("=============================================\n");
	getchar();
}

// �˻� ���� : ISBN
void findcusID(char * isbn)
{
	int i;

	for (i = 0; i < numOfRentCus; i++)
	{
		if (!strcmp(rentList[i].ISBN, isbn))
		{
			cusInfo * cusp = GetCusPtrByID(rentList[i].cusID);

			printf("\n");
			printf("����������������������������������������������\n");
			printf("   �� ID        : %s \n", cusp->ID);
			printf("   �� Name      : %s \n", cusp->name);
			printf("   �� Phone     : %s \n", cusp->phoneNum);
			printf("   �� Rent day  : %d \n", rentList[i].rentDay);
			printf("����������������������������������������������\n");
		}
	}
}

void cus_sellect()
{
	char id[NAME_LEN];
	unsigned int date1 = 0;
	unsigned int date2 = 0;
	
	printf("\n================ �� �� �� �� ================\n");

	printf("�� ȸ�� ID�� �Ⱓ�� �Է��ϼ���.\n");
	printf("��  ID                         : ");
	gets(id);

	cusInfo * cselp = GetCusPtrByID(id);

	if (cselp == 0)
	{
		printf("\n�� �������� �ʴ� ID �Դϴ�. ��\n");
		printf("=============================================\n");
		getchar();
		return;
	}
	
	printf("�� ��ȸ ���� ��¥ (YYYYMMDD)   : ");
	scanf("%d", &date1);

	printf("�� ��ȸ ������ ��¥ (YYYYMMDD) : ");
	scanf("%d", &date2);

	if (date1 > date2)
	{
		swap(&date1, &date2);
	}
	
	findDVD(id, date1, date2);

	printf("\n�� ��ȸ�� �Ϸ�Ǿ����ϴ�.\n");
	printf("=============================================\n");
	getchar();
	getchar();
	
}

// �˻� ���� : �� ID �� �Ⱓ
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

// ���� �Է�
void StoreRentListToFile(void)
{
	FILE * fp = fopen(RENT_BACKUP_FILE, "wb");

	if (fp == NULL)
	{
		return;
	}

	// �̷°Ǽ�(numOfRentCus)�� fp�� (int�� ������) 1�� ��
	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
	// 


	fclose(fp);
}

// �뿩 �̷� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
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