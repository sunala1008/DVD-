#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

/*
	��� : DVD �뿩 ������ �����ϴ� �Լ�
	��ȯ : void
*/
void AddRentList(char * ISBN, char * cusID, int rentDay);

/*
	��� : Ư�� ISBN�� DVD �뿩 �� ���� ��� �Լ�
*/
void findcusID(char * isbn);

/*
	��� : ���� �Ⱓ �ȿ� �̷��� Ư�� ����
		DVD �뿩 ���� ���
*/
void findDVD(char * ID, unsigned int start, unsigned int end);

// �뿩 ����Ʈ�� ���Ͽ� ���� �Լ�
// => �뿩 �̷� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreRentListToFile(void);

// �뿩 ����Ʈ�� ���Ͽ��� �ҷ����� �Լ�
// => �뿩 �̷� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadRentListFromFile(void);

// �˻� ��½� �Ⱓ ����
//void date_swap(dvdRentInfo dvdary);

#endif // !__RENTACCESS_H__
