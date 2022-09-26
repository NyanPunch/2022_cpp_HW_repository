/*******************************
���α׷���: ����ó�����α׷� 4
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 09
���α׷� ����: �л� �� �� ���� ���� ����ڰ� ���� �� �ְ� �����Ҵ�
���� ���� : InputData, InputValue �߰� 
********************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Subject {			//���� ���� ����ü
	char subname[30];		//���� ��
	int hakjum;				//���� ����
	char grade[10];			//���� ���
	float GPA;				//���� ����
};

struct student {			//�л� ���� ����ü
	char stdname[30];		//�̸�
	int hakbun;				//�й�
	Subject *Sub;			//����
	int SubNum;				//NEW ���� ��
	float aveGPA;			//������ ��� ����
};

int menu = 0;

void InputData(student* pSt,int StudentNum);	//�����Է��Լ�   /* CHANGE */
void PrintMenu();						//�޴���� 
void CalcGPA(Subject& Sub);				//������ ������� 
float CalcAveGPA(Subject* Sub, int SubNum);			//�����л� ��� ���� ��� /* CHANGE */
void PrintAllData(const student* pSt, int StudentNum);	//��ü�л� �Ż�/���� ��� 
void PrintOneData(const student& rSt);					//�����л� �Ż�/���� ��� 
student* StdSearch(student* pSt, int StudentNum);		//�л� �̸� �˻� �� �ش� �л� ������ �ִ°��� �ּ� ����
void PrintAllStdList(student* pSt, int StudentNum);
void ModifyStdInfo(student* pSt);

void InputValue(char* str) {
	cin >> str;
}
void InputValue(int& i) {
	cin >> i;
}

int main() {
	cout.precision(2);
	cout << fixed;

	PrintMenu();

	return 0;
}

void PrintMenu()		// �޴� ���
{
	struct student* Std = NULL;	//�л� ����ü ���� �޸� �Ҵ�
	int flag = 0, StdNum = 2;

	cout << "\n������ ����� �л� ���� �Է����ּ���. : ";
	cin >> StdNum;
	Std = new student[StdNum]; // ���� �޸� ���
	
	while (menu != 4) {
		cout << "\n===== �޴� =====\n"
			<< "1. �л� ���� �Է�\n"
			<< "2. ��ü �л� ���� ����\n"
			<< "3. �л� �̸� �˻�\n"
			<< "4. ���α׷� ����" << endl;

		cout << "���ϴ� ����� �Է��ϼ��� : ";
		cin >> menu;
		cout << endl;

		if (menu == 1)
			flag = 1;	//���� �� ���� �� ���� ���, �л� ���� �˻��� �Ϸ� �Ҷ�
		else if ((menu == 2) && (flag == 0) || (menu == 3) && (flag == 0)) {
			cout << "�л��� ������ �Էµ����� �ʽ��ϴ�. ������ ���� �Է����ּ���.\n" << endl;
			continue;	//������ 1�� �̵� �ذ� 
		}

		switch (menu) {
		case 1:
			//�л� ���� �Է�
			InputData(Std, StdNum);
			break;
		case 2:
			//�л� ��ü ���� ���
			PrintAllData(Std, StdNum);
			break;
		case 3:
			//�л� �̸� �˻� �� ���
			student * SearchStd;
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4:
			//���α׷� ����
			cout << "���α׷��� �����մϴ�\n";
			delete[] Std;	//�л� �Ҵ� ����
			Std = NULL;	//�����ϰ� NULL �ʱ�ȭ
		}
	}
}

/* ������ ���� ó�� */
void CalcGPA(Subject& Sub) {
	if (strcmp(Sub.grade, "A+") == 0)
		Sub.GPA = (float)Sub.hakjum * 4.5;
	else if ((strcmp(Sub.grade, "A0") == 0) || (strcmp(Sub.grade, "A") == 0))
		Sub.GPA = (float)Sub.hakjum * 4.0;
	else if (strcmp(Sub.grade, "B+") == 0)
		Sub.GPA = (float)Sub.hakjum * 3.5;
	else if ((strcmp(Sub.grade, "B0") == 0) || (strcmp(Sub.grade, "B") == 0))
		Sub.GPA = (float)Sub.hakjum * 3.0;
	else if (strcmp(Sub.grade, "C+") == 0)
		Sub.GPA = (float)Sub.hakjum * 2.5;
	else if ((strcmp(Sub.grade, "C0") == 0) || (strcmp(Sub.grade, "C") == 0))
		Sub.GPA = (float)Sub.hakjum * 2.0;
	else if (strcmp(Sub.grade, "D+") == 0)
		Sub.GPA = (float)Sub.hakjum * 1.5;
	else if ((strcmp(Sub.grade, "D0") == 0) || (strcmp(Sub.grade, "D") == 0))
		Sub.GPA = (float)Sub.hakjum * 1.0;
	else if (strcmp(Sub.grade, "F") == 0)
		Sub.GPA = (float)Sub.hakjum * 0;
}

/* ��� ó�� */
float CalcAveGPA(Subject* Sub, int SubNum) {
	float sumGPA = 0;
	for (int i = 0; i < SubNum; i++)
		sumGPA += Sub[i].GPA;
	return (sumGPA / SubNum);
	//aveGPA = sumGPA / MAX_Sub
}

void InputData(student *pSt,int StudentNum) {			//���� �Է� �Լ� case 1:
	int i, j;					// i = �л� j = �л��� �� ����
	float AveGPA;
	int SubNum;
	for (i = 0; i < StudentNum; i++) {
		cout << endl << "* " << i + 1 << " �� ° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : "; InputValue(pSt[i].stdname);
		cout << "�й� : "; InputValue(pSt[i].hakbun);
		cout << endl;

		cout << "������ ���� ���� �Է� : ";
		cin >> SubNum; //���� ��
		//n��° �л��� ����� ��ŭ ���� �Ҵ�
		pSt[i].Sub = new Subject[SubNum];
		pSt[i].SubNum = SubNum;

		//n��° �л��� �Է¹��� ���� �� ��ŭ ���� �Ҵ�.
		cout << "* ������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
		for (j = 0; j < SubNum; j++) {
			cout << "������� : "; InputValue(pSt[i].Sub[j].subname);
			cout << "�������� : "; InputValue(pSt[i].Sub[j].hakjum);
			cout << "������(A+ ~ F) : "; InputValue(pSt[i].Sub[j].grade);
			cout << endl;
			CalcGPA(pSt[i].Sub[j]);  //���� ���� ó��
		}
		AveGPA = CalcAveGPA(pSt[i].Sub, SubNum);	//��� ���� ó��
		pSt[i].aveGPA = AveGPA;			//i��° �л��� ��� ���� ����
	}
}

/* 2. ��ü �л� ���� ��� */
void PrintAllData(const student* pSt, int StudentNum) {
	cout.width(10);
	cout << "��ü �л� ��������\n";
	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

/* �л� ���� ���� ���*/
void PrintOneData(const student& rSt) {
	cout << "=========================================\n";
	cout << "�̸� : " << rSt.stdname << " �й� : " << rSt.hakbun << endl;
	cout << "=========================================\n";
	cout << "�����" << setw(10) << "��������" << setw(10) << "������ " << setw(10) << "��������" << endl;
	cout << "=========================================\n";

	for (int j = 0; j < rSt.SubNum; j++) {	//���� �ݺ� ��¹�
		cout << rSt.Sub[j].subname << setw(10) << rSt.Sub[j].hakjum << setw(10) << rSt.Sub[j].grade << setw(10) << rSt.Sub[j].GPA << endl;
	}
	cout << "=========================================\n";
	cout.width(35);
	cout << "�������  " << rSt.aveGPA << endl;
}

/* 3. �̸��� �˻��Ͽ� �л��� ���� ��� */
student* StdSearch(student* pSt, int StudentNum) {
	char SearchName[30];
	cout << "ã�� �л��� �̸��� �Է����ּ���.\n �̸� : ";
	InputValue(SearchName);
	int len = strlen(SearchName);	//�̸����̸�ŭ len�� ���� ����
	for (int i = 0; i < StudentNum; i++) {
		for (int j = 0; j < len; j++) {
			if (strlen(pSt[i].stdname) == len && (pSt[i].stdname[j] == SearchName[j]))
				return &pSt[i]; //ã�� �̸��� �˻��� �̸��� ���ڼ��� ����, ����� �̸��� ���� �� �ش� �̸� ����
		}
	}
	return NULL;
}

/* 4. ��ü �л��� ���: �й��� �̸��� ��� */
void PrintAllStdList(student* pSt, int StudentNum) {
	cout << "====================================\n"
		<< setw(10) << "�й�" << setw(10) << "�̸�\n"
		<< "====================================\n";
	for (int i = 0; i < StudentNum; i++, pSt++) {
		cout << setw(10) << pSt->hakbun << setw(10) << pSt->stdname << endl;
	}
	cout << "====================================\n";
}
/* 5. Ư�� �л��� �̸��� �й� ���� */
void ModifyStdInfo(student* pSt) {
	cout << "* <" << pSt->stdname << " " << pSt->hakbun << ">�� ������ �����ϼ���" << endl;
	cout << "�̸� : "; InputValue(pSt->stdname);
	cout << "�й� : "; InputValue(pSt->hakbun);
}