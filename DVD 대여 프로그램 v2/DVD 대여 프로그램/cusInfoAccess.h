/*
	���   : �� ���� ���� �� ���� �Լ����� ����
	�ۼ��� : Sun �븮
	�ۼ��� : 2019-03-22
	Ver.   : 2.0
*/

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

/*
	��� : cusInfo �Ҵ� �� ����
	��ȯ : ���� �� ��ϵ� ������ ����, ���� �� 0�� ��ȯ
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	��� : �ش� �� ID ������ ������ �ִ� �����͸� ��ȯ
	��ȯ : ��� ���� ���� ID�� ��� NULL ������ ��ȯ
*/
cusInfo * GetCusPtrByID(char * ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� 1, �ƴϸ� 0�� ��ȯ
*/
int IsregitsID(char * ID);

// �� ����Ʈ�� ���Ͽ� ���� �Լ�
// => �� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreCusListToFile(void);

// �� ����Ʈ�� ���Ͽ��� �ҷ����� �Լ�
// => �� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadCusListFromFile(void);

void FreeCUS();

#endif // !__CUSACCESS_H__
