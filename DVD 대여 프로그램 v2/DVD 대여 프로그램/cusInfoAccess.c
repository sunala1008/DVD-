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

void FreeCUS() // ���� �Ҵ� ����
{
	for (int i = 0; i < numOfCustomer; i++)
	{
		free(customerary[i]);
	}
}

// �� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreCusListToFile(void)
{
	int i;

	FILE * fp = fopen(CUS_BACKUP_FILE, "wb"); // ���̳ʸ��� ���ڴ�.
	if (fp == NULL)
		return;
	// �� �� �� �� �ϸ� �ȴ� (?
	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for (i = 0; i < numOfCustomer; i++)
		fwrite(customerary[i], sizeof(cusInfo), 1, fp);

	fclose(fp);
}


// �� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadCusListFromFile(void)
{
	int i;

	FILE * fp = fopen(CUS_BACKUP_FILE, "rb"); // ���̳ʸ��� �аڴ�.

	if (fp == NULL)
	{
		return;
	}

	fread(&numOfCustomer, sizeof(int), 1, fp);

	for (i = 0; i < numOfCustomer; i++)
	{
		customerary[i] = (cusInfo *)malloc(sizeof(cusInfo)); // ���� �Ҵ�
		fread(customerary[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}
