/*
	���   : �ܼ������ ���� �Լ����� ����
	�ۼ��� : Sun �븮
	�ۼ��� : 2019-03-22
	Ver.   : 2.0
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

/*
	��� : ���α׷��� ����ϱ� ���� �޴� ���
	��ȯ : void
*/
void ShowMenu(void);

/*
	��� : �� ���� ���
	��ȯ : cusInfo *pCus
*/
void ShowCustomerInfo(cusInfo * pCus);

/*
	��� : DVD ���� ���
	��ȯ : dvdInfo * pDVD
*/
void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowCustomerInfoContinue(cusInfo * pCus);

void ShowDVDRentInfo(dvdRentInfo dvd);

// �� �޴� ���
void ShowCustomerMenu();

// DVD �޴� ���
void ShowDVDMenu();

// DVD �뿩�̷� �˻� �޴� ���
void ShowDVDInforMenu();

// �帣 �޴� ���
void ShowGenreMenu();

#endif // !__SCREENOUT_H__


