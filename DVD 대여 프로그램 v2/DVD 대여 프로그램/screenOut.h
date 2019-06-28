/*
	기능   : 콘솔출력을 위한 함수들의 선언
	작성자 : Sun 대리
	작성일 : 2019-03-22
	Ver.   : 2.0
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

/*
	기능 : 프로그램을 사용하기 위한 메뉴 출력
	반환 : void
*/
void ShowMenu(void);

/*
	기능 : 고객 정보 출력
	반환 : cusInfo *pCus
*/
void ShowCustomerInfo(cusInfo * pCus);

/*
	기능 : DVD 정보 출력
	반환 : dvdInfo * pDVD
*/
void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowCustomerInfoContinue(cusInfo * pCus);

void ShowDVDRentInfo(dvdRentInfo dvd);

// 고객 메뉴 출력
void ShowCustomerMenu();

// DVD 메뉴 출력
void ShowDVDMenu();

// DVD 대여이력 검색 메뉴 출력
void ShowDVDInforMenu();

// 장르 메뉴 출력
void ShowGenreMenu();

#endif // !__SCREENOUT_H__


