/*
	기능   : 고객 관련 업무 처리 함수들의 선언
	작성자 : Sun 대리
	작성일 : 2019-03-22
	Ver.   : 2.0

	- 기존 cusManager와 dvdManager를 합침
*/

#ifndef __CUSMGR_H__
#define __CUSMGR_H__

/*
	기능 : 신규 회원 가입
	반환 : void
*/
void RegisterCustomer();

/*
	기능 : ID를 통한 회원 검색
	반환 : void
*/
void SearchCusInfo();

// 고객 ID와 기간으로 조회 메인 함수
void cus_sellect();

void RegistDVD();

void SearchDVDInfo();

// 데이터 복구 함수
void InitData(void);

// 고객 메뉴 
void CustomerMenu();

#endif // !__CUSMGR_H__


