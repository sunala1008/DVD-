/*
	���   : �� ���� ����ü
	�ۼ��� : Sun �븮
	�ۼ��� : 2019-03-22
	Ver.   : 2.0
*/

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum { ACTION = 1, COMIC, SF, ROMANTIC }; // ���� �帣 ����

enum { RENTED = 0, RETURNED };            // �뿩 ���� ����

typedef struct __dvdInfo
{   
	char ISBN[ISBN_LEN];      // DVD ISBN
	char title[TITLE_LEN];    // DVD title
	int genre;                // ���� �帣 ��� ����
	int rentState;            // �뿩 ���� ���� (�뿩, �ݳ�)
	
} dvdInfo;

typedef struct __dvdRentInfo  
{
	char cusID[ID_LEN];   // �� ID
	char ISBN[ISBN_LEN];  // DVD ISBN
	unsigned int rentDay; // �뿩�� 
}dvdRentInfo;

#endif // !__DVDINFO_H__
