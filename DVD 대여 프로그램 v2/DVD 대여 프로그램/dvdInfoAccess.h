/*
	���   : �� ���� ����ü
	�ۼ��� : Sun �븮
	�ۼ��� : 2019-03-11
	Ver.   : 1.0
*/

#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

/*
	��� : dvdInfo ������� �Ҵ� �� ����ü �迭�� ����
	��ȯ : ���� �� ��ϵ� ������ ��, ���� �� 0�� ��ȯ
*/
int AddDVDInfo(char * ISBN, char * title, int genre);

/*
	��� : �ش� ISBN�� ������ ��� �ִ� ������ �����͸� ��ȯ
	��ȯ : ��ϵ��� ���� ISBN�� ��� NULL �����͸� ��ȯ
*/
dvdInfo * GetDVDPtrByISBN(char *ISBN);

/*
	��� : �� ��ϵ� ISBN���� üũ
	��ȯ : ��Ǿ����� 1, �ƴϸ� 0�� ��ȯ
*/
int IsRegistISBN(char * ISBN);

// ���� �Ҵ� ����
void FreeDVD();


// �뿩 �Լ� 
int SetDVDRented(char * ISBN);

// �ݳ� �Լ�
void turnin(char * isbn);

// DVD �뿩/�ݳ� ���� ��ȸ
int GetDVDRentState(char * ISBN);

// DVD ��ü �̷� ��ȸ ���� �Լ�
void dvd_sellect();

// DVD ����Ʈ�� ���Ͽ� ���� �Լ�
// => DVD ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreDVDListToFile(void);

// DVD ����Ʈ�� ���Ͽ��� �ҷ����� �Լ�
// => DVD ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadDVDListFromFile(void);

// �Է� �޴� �Ⱓ ��¥ ����
void swap(int * per1, int * per2);

#endif // !__DVDACCESS_H__


