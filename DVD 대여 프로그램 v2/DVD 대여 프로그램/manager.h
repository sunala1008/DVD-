/*
	���   : �� ���� ���� ó�� �Լ����� ����
	�ۼ��� : Sun �븮
	�ۼ��� : 2019-03-22
	Ver.   : 2.0

	- ���� cusManager�� dvdManager�� ��ħ
*/

#ifndef __CUSMGR_H__
#define __CUSMGR_H__

/*
	��� : �ű� ȸ�� ����
	��ȯ : void
*/
void RegisterCustomer();

/*
	��� : ID�� ���� ȸ�� �˻�
	��ȯ : void
*/
void SearchCusInfo();

// �� ID�� �Ⱓ���� ��ȸ ���� �Լ�
void cus_sellect();

void RegistDVD();

void SearchDVDInfo();

// ������ ���� �Լ�
void InitData(void);

// �� �޴� 
void CustomerMenu();

#endif // !__CUSMGR_H__


