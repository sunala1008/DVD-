#include "common.h"
#include "dvdInfo.h"
#include "manager.h"
#include "screenOut.h"
#include "dvdInfoAccess.h"

#define MAX_DVD 100
#define DVD_BACKUP_FILE "dvdInfo.dat"

static dvdInfo *dvdary[MAX_DVD];
static int numOfDVD = 0;

int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo *dp;

	if (numOfDVD >= MAX_DVD) // realloc?
		return 0; 

	dp = (dvdInfo *)malloc(sizeof(dvdInfo));
	strcpy(dp->ISBN, ISBN);
	strcpy(dp->title, title);
	dp->genre = genre; 

	dp->rentState = RETURNED; 

	dvdary[numOfDVD++] = dp;

	StoreDVDListToFile();

	return numOfDVD;
}

dvdInfo * GetDVDPtrByISBN(char *ISBN)
{
	int i;

	for (i = 0; i < numOfDVD; i++)
	{   
		if (!strcmp(dvdary[i]->ISBN, ISBN))
			return dvdary[i];
	}

	return (dvdInfo *)0;
}

int IsRegistISBN(char * ISBN)
{
	dvdInfo * dp = GetDVDPtrByISBN(ISBN);

	if (dp == 0)
		return 0;
	else
		return 1;
}

void FreeDVD() // 동적 할당 해제
{
	for (int i = 0; i < numOfDVD; i++)
	{
		free(dvdary[i]);
	}
}

// 입력 받은 날짜 기간 정렬
void swap(int * per1, int * per2)
{
	int temp;

	if (per1 > per2)
	{
		temp = *per1;
		*per1 = *per2;
		*per2 = temp;
	}
}

// DVD 리스트를 파일에 백업하는 함수
void StoreDVDListToFile(void)
{
	int i;

	FILE * fp = fopen(DVD_BACKUP_FILE, "wb");

	if (fp == NULL)
	{
		return;
	}

	//건 수
	fwrite(&numOfDVD, sizeof(int), 1, fp);

	for (i = 0; i < numOfDVD; i++)
	{                                   // ┌ 한 번 씩
		fwrite(dvdary[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}

// DVD 리스트를 파일로부터 복구하는 함수
void LoadDVDListFromFile(void)
{
	int i;

	FILE * fp = fopen(DVD_BACKUP_FILE, "rb");

	if (fp == NULL)
	{
		return;
	}

	// 몇 건인지를 읽어서 저장
	fread(&numOfDVD, sizeof(int), 1, fp);

	for (i = 0; i < numOfDVD; i++)
	{
		dvdary[i] = (dvdInfo *)malloc(sizeof(dvdInfo));
		fread(dvdary[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}