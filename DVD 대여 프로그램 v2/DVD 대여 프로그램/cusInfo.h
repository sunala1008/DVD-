/*
	기능   : 고객 관리 구조체
	작성자 : Sun 대리
	작성일 : 2019-03-22
	Ver.   : 2.0
*/

#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN 30
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __cusInfo
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

} cusInfo;
#endif // !__CUSINFO_H__