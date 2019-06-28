/*
	기능   : 고객 관리 구조체
	작성자 : Sun 대리
	작성일 : 2019-03-22
	Ver.   : 2.0
*/

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum { ACTION = 1, COMIC, SF, ROMANTIC }; // 도서 장르 정보

enum { RENTED = 0, RETURNED };            // 대여 상태 정보

typedef struct __dvdInfo
{   
	char ISBN[ISBN_LEN];      // DVD ISBN
	char title[TITLE_LEN];    // DVD title
	int genre;                // 도서 장르 멤버 변수
	int rentState;            // 대여 가능 여부 (대여, 반납)
	
} dvdInfo;

typedef struct __dvdRentInfo  
{
	char cusID[ID_LEN];   // 고객 ID
	char ISBN[ISBN_LEN];  // DVD ISBN
	unsigned int rentDay; // 대여일 
}dvdRentInfo;

#endif // !__DVDINFO_H__
