#include "common.h"
#include "cusInfo.h"
#include "manager.h"
#include "cusInfoAccess.h"

#define MAX_CUSTOMER  100
#define CUS_BACKUP_FILE "cusInfo.dat"

static cusInfo *customerary[MAX_CUSTOMER];
static int numOfCustomer = 0;

int AddCusInfo(char * ID, char * name, char * num)
{
	cusInfo *cp;

	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	cp = (cusInfo *)malloc(sizeof(cusInfo));
	strcpy(cp->ID, ID);
	strcpy(cp->name, name);
	strcpy(cp->phoneNum, num);

	customerary[numOfCustomer++] = cp;

	StoreCusListToFile();

	return numOfCustomer;
}

cusInfo * GetCusPtrByID(char * ID)
{
	int i;

	for (i = 0; i < numOfCustomer; i++)
	{  
		if (!strcmp(customerary[i]->ID, ID))
			return customerary[i];
	}

	return (cusInfo *)0; 
}

int IsregitsID(char * ID)
{
	cusInfo * cp = GetCusPtrByID(ID);

	if (cp == 0)
		return 0; 
	else
		return 1;
}

void FreeCUS() // 동적 할당 해제
{
	for (int i = 0; i < numOfCustomer; i++)
	{
		free(customerary[i]);
	}
}

// 고객 리스트를 파일에 백업하는 함수
void StoreCusListToFile(void)
{
	int i;

	FILE * fp = fopen(CUS_BACKUP_FILE, "wb"); // 바이너리로 쓰겠다.
	if (fp == NULL)
		return;
	// ┌ 한 번 만 하면 된다 (?
	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for (i = 0; i < numOfCustomer; i++)
		fwrite(customerary[i], sizeof(cusInfo), 1, fp);

	fclose(fp);
}


// 고객 리스트를 파일로부터 복구하는 함수
void LoadCusListFromFile(void)
{
	int i;

	FILE * fp = fopen(CUS_BACKUP_FILE, "rb"); // 바이너리로 읽겠다.

	if (fp == NULL)
	{
		return;
	}

	fread(&numOfCustomer, sizeof(int), 1, fp);

	for (i = 0; i < numOfCustomer; i++)
	{
		customerary[i] = (cusInfo *)malloc(sizeof(cusInfo)); // 공간 할당
		fread(customerary[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}
