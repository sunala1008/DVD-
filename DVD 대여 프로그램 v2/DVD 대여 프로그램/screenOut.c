#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

void ShowMenu()
{
	system("cls"); // stdlib.h �ȿ� ����
	
	printf("���������������� �� ��  �� �� ����������������\n");
	printf("��                                          ��\n");
	printf("��              1. ȸ�� �޴�                ��\n");
	printf("��                                          ��\n");
	printf("��              2. DVD  �޴�                ��\n");
	printf("��                                          ��\n");
	printf("��              3. ��     ��                ��\n");
	printf("��                                          ��\n");
	printf("����������������������������������������������\n");
	printf("�� ����  >>  ");
}

void ShowCustomerMenu()
{
	system("cls");

	printf("���������������� ȸ ��  �� �� ����������������\n");
	printf("��                                          ��\n");
	printf("��              1. ȸ�� ����                ��\n");
	printf("��                                          ��\n");
	printf("��              2. ȸ�� ��ȸ                ��\n");
	printf("��                                          ��\n");
	printf("��              3. ���� �޴�                ��\n");
	printf("��                                          ��\n");
	printf("����������������������������������������������\n");
	printf("�� ����  >>  ");
}

void ShowDVDMenu()
{
	system("cls");

	printf("����������������   DVD �� ��  ����������������\n");
	printf("��                                          ��\n");
	printf("��              1. DVD ���                 ��\n");
	printf("��                                          ��\n");
	printf("��              2. DVD ��ȸ                 ��\n");
	printf("��                                          ��\n");
	printf("��              3. DVD �뿩                 ��\n");
	printf("��                                          ��\n");
	printf("��              4. DVD �ݳ�                 ��\n");
	printf("��                                          ��\n");
	printf("��              5. DVD �뿩 ��ȸ            ��\n");
	printf("��                                          ��\n");
	printf("��              6. �� �� �� ��              ��\n");
	printf("��                                          ��\n");
	printf("����������������������������������������������\n");
	printf("�� ����  >>  ");
}

void ShowDVDInforMenu()
{
	system("cls");

	printf("��������������  DVD  �뿩 ��ȸ  ��������������\n");
	printf("��                                          ��\n");
	printf("��       1. DVD �뿩 �̷� ��ȸ              ��\n");
	printf("��                                          ��\n");
	printf("��       2. ȸ���� �뿩 DVD �̷� ��ȸ       ��\n");
	printf("��                                          ��\n");
	printf("��       3. DVD �� ��                       ��\n");
	printf("��                                          ��\n");
	printf("����������������������������������������������\n");
	printf("�� ����  >>  ");
}

void ShowCustomerInfo(cusInfo *pCus)  // �� ���� ���
{
	printf("\n");
	printf("����������������������������������������������\n");
	printf("  �� ID        : %s\n", pCus->ID);
	printf("  �� Name      : %s\n", pCus->name);
	printf("  �� Phone     : %s\n", pCus->phoneNum);
	printf("����������������������������������������������\n");

	getchar();
}

void ShowDVDInfo(dvdInfo * pDVD)     // DVD ���� ���
{
	printf("\n");
	printf("����������������������������������������������\n");

	printf("   �� ISBN      : %s\n", pDVD->ISBN);
	printf("   �� Title     : %s\n", pDVD->title);
	
	ShowGenre(pDVD->genre);

	if (pDVD->rentState == RENTED)
	{
		printf("   �� �뿩 ���� DVD �Դϴ�.\n");
	}
	else
		printf("   �� �뿩 ������ DVD �Դϴ�.\n");
	printf("����������������������������������������������\n");
	getchar();
}

void ShowGenreMenu()
{
	printf("��������������   ��        ��   ��������������\n");
	printf("��                                          ��\n");
	printf("��        1. ACTION        2. COMIC         ��\n");
	printf("��                                          ��\n");
	printf("��        3. SF            4. ROMANTIC      ��\n");
	printf("��                                          ��\n");
	printf("����������������������������������������������\n");
}


void ShowGenre(int gen)             // �帣 ���
{
	if (gen == 1)
	{
		printf("   �� Gerne     : ACTION \n");
	}
	if (gen == 2)
	{
		printf("   �� Gerne     : COMIC \n");
	}
	if (gen == 3)
	{
		printf("   �� Gerne     : SF \n");
	}
	if (gen == 4)
	{
		printf("   �� Gerne     : ROMANTIC \n");
	}
}

void ShowCustomerInfoContinue(cusInfo * pCus)
{
	printf("����������������������������������������������\n");
	printf("   �� ID     : %s \n", pCus->ID);
	printf("   �� Name   : %s \n", pCus->name);
	printf("   �� Phone  : %s \n", pCus->phoneNum);
	printf("����������������������������������������������\n\n");
}

void ShowDVDRentInfo(dvdRentInfo dvd)
{
	printf("����������������������������������������������\n");
	printf("   �� ID     : %s \n", dvd.cusID);
	printf("   �� ISBN   : %s \n", dvd.ISBN);
	printf("   �� �뿩�� : %u \n", dvd.rentDay);
	printf("����������������������������������������������\n");
}