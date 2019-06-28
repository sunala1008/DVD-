/*
	기능   : 고객 관리 구조체
	작성자 : Sun 대리
	작성일 : 2019-03-11
	Ver.   : 1.0
*/

#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

/*
	기능 : dvdInfo 저장공간 할당 및 구조체 배열에 저장
	반환 : 성공 시 등록된 정보의 수, 실패 시 0을 반환
*/
int AddDVDInfo(char * ISBN, char * title, int genre);

/*
	기능 : 해당 ISBN의 정보를 담고 있는 변수의 포인터를 반환
	반환 : 등록되지 않은 ISBN의 경우 NULL 포인터를 반환
*/
dvdInfo * GetDVDPtrByISBN(char *ISBN);

/*
	기능 : 기 등록된 ISBN인지 체크
	반환 : 등독되었으면 1, 아니면 0을 반환
*/
int IsRegistISBN(char * ISBN);

// 동적 할당 해제
void FreeDVD();


// 대여 함수 
int SetDVDRented(char * ISBN);

// 반납 함수
void turnin(char * isbn);

// DVD 대여/반납 상태 조회
int GetDVDRentState(char * ISBN);

// DVD 전체 이력 조회 메인 함수
void dvd_sellect();

// DVD 리스트를 파일에 쓰는 함수
// => DVD 리스트를 파일에 백업하는 함수
void StoreDVDListToFile(void);

// DVD 리스트를 파일에서 불러오는 함수
// => DVD 리스트를 파일로부터 복구하는 함수
void LoadDVDListFromFile(void);

// 입력 받는 기간 날짜 정렬
void swap(int * per1, int * per2);

#endif // !__DVDACCESS_H__


