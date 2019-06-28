#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

/*
	기능 : DVD 대여 정보를 저장하는 함수
	반환 : void
*/
void AddRentList(char * ISBN, char * cusID, int rentDay);

/*
	기능 : 특정 ISBN의 DVD 대여 고객 정보 출력 함수
*/
void findcusID(char * isbn);

/*
	기능 : 일정 기간 안에 이뤄진 특정 고객의
		DVD 대여 정보 출력
*/
void findDVD(char * ID, unsigned int start, unsigned int end);

// 대여 리스트를 파일에 쓰는 함수
// => 대여 이력 리스트를 파일에 백업하는 함수
void StoreRentListToFile(void);

// 대여 리스트를 파일에서 불러오는 함수
// => 대여 이력 리스트를 파일로부터 복구하는 함수
void LoadRentListFromFile(void);

// 검색 출력시 기간 정렬
//void date_swap(dvdRentInfo dvdary);

#endif // !__RENTACCESS_H__
