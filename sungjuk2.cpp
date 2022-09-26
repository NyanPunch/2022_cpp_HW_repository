/*******************************
���α׷���: ����ó�����α׷� 2
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 25
���α׷� ����: �л��� ������ �Է¹ް� �䱸���׿� �°� ���
********************************/
#include <iostream>
#include <string.h>
#define MAX_Stu 2			//�л� �ο���
#define MAX_Sub 3			//���� �����
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
	Subject Sub[3];			//����
	float avgGPA;			//������ ��� ����
};

void InputData(student s[]);			//�����Է��Լ�

void PrintMenu();						//NEW �޴���� 
void CalcGPA(Subject& Sub);				//NEW ������ ������� 
float CalcAveGPA(Subject* Sub);			//NEW �����л� ��� ���� ��� 
void PrintAllData(const student* pSt, int StudentNum);	//NEW ��ü�л� �Ż�/���� ��� 
void PrintOneData(const student& rSt);					//NEW �����л� �Ż�/���� ��� 
student* StdSearch(student* pSt, int StudentNum);		//NEW �л� �̸� �˻� �� �ش� �л� ������ �ִ°��� �ּ� ����

int main() {
	cout.precision(2);
	cout << fixed;
	
	PrintMenu();

	return 0;
}

void PrintMenu()		// �޴� ���
{
	struct student s[MAX_Stu];
	int flag = 0, menu = 0;
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
			InputData(s);
			break;
		case 2:
			//�л� ��ü ���� ���
			PrintAllData(s, MAX_Stu);
			break;
		case 3:
			//�л� �̸� �˻� �� ���
			student * SearchStd;
			SearchStd = StdSearch(s, MAX_Stu);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4:
			//���α׷� ����
			cout << "���α׷��� �����մϴ�\n";
		}
	}
}

void CalcGPA(Subject& Sub) {	//������ ���� ó�� �Լ�
	cout << "������� : ";
	cin >> Sub.subname;
	cout << "�������� : ";
	cin >> Sub.hakjum;
	cout << "������(A+ ~ F) : ";
	cin >> Sub.grade; cout << endl;
	if (strcmp(Sub.grade, "A+") == 0)
		Sub.GPA = Sub.hakjum * 4.5;
	else if ((strcmp(Sub.grade, "A0") == 0) || (strcmp(Sub.grade, "A") == 0))
		Sub.GPA = Sub.hakjum * 4.0;
	else if (strcmp(Sub.grade, "B+") == 0)
		Sub.GPA = Sub.hakjum * 3.5;
	else if ((strcmp(Sub.grade, "B0") == 0) || (strcmp(Sub.grade, "B") == 0))
		Sub.GPA = Sub.hakjum * 3.0;
	else if (strcmp(Sub.grade, "C+") == 0)
		Sub.GPA = Sub.hakjum * 2.5;
	else if ((strcmp(Sub.grade, "C0") == 0) || (strcmp(Sub.grade, "C") == 0))
		Sub.GPA = Sub.hakjum * 2.0;
	
}

float CalcAveGPA(Subject* Sub) {	//��� ���� ó�� �Լ�
	float sumGPA = 0;
	for (int i = 0; i < MAX_Sub; i++)
		sumGPA += Sub[i].GPA;
	return (sumGPA / MAX_Sub);
	//avgGPA = sumGPA / MAX_Sub
}

void InputData(student s[]) {			//���� �Է� �Լ� case 1:
	int i, j;							// i = �л� j = �л��� �� ����
	float AveGPA;
	for (i = 0; i < MAX_Stu; i++) {
		cout << endl << "* " << i + 1 << " �� ° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		cin >> s[i].stdname;
		cout << "�й� : ";
		cin >> s[i].hakbun;
		cout << endl << "* ������ ���� �� ���� �� �������, ��������, �������� �Է��ϼ���.\n";
		for (j = 0; j < MAX_Sub; j++) {
			CalcGPA(s[i].Sub[j]);  //���� ���� ó��
		}
		AveGPA = CalcAveGPA(s[i].Sub);	//��� ���� ó��
		s[i].avgGPA = AveGPA;			//i��° �л��� ��� ���� ����
	}
}

void PrintAllData(const student* pSt, int StudentNum) {		//��ü �л� ���� ���
	cout.width(10);
	cout << "��ü �л� ��������\n";
	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void PrintOneData(const student& rSt) {		//�л� ���� ���� ���
		cout << "=========================================\n";
		cout << "�̸� : " << rSt.stdname << " �й� : " << rSt.hakbun << endl;
		cout << "=========================================\n";
		cout.width(10); cout << "�����";
		cout.width(10); cout << "��������";
		cout.width(10); cout << "������";
		cout.width(10); cout << "��������" << endl;
		cout << "=========================================\n";

		for (int j = 0; j < MAX_Sub; j++) {				//���� �ݺ� ��¹�
			cout.width(10); cout << rSt.Sub[j].subname;
			cout.width(10); cout << rSt.Sub[j].hakjum;
			cout.width(10); cout << rSt.Sub[j].grade;
			cout.width(10); cout << rSt.Sub[j].GPA << endl;
		}
		cout << "=========================================\n";
		cout.width(35);
		cout << "�������  " << rSt.avgGPA << endl;
}

student* StdSearch(student* pSt, int StudentNum) {	//�̸��� �˻��ؼ� �ּ� ����
	char SearchName[30];
	cout << "ã�� �л��� �̸��� �Է����ּ���.\n �̸� : ";
	cin >> SearchName;
	int len = strlen(SearchName);	//�̸����̸�ŭ len�� ���� ����
	for (int i = 0; i < StudentNum; i++) {
		for (int j = 0; j < len; j++) {
			if (strlen(pSt[i].stdname) == len && (pSt[i].stdname[j] == SearchName[j]))	
				return &pSt[i]; //ã�� �̸��� �˻��� �̸��� ���ڼ��� ����, ����� �̸��� ���� �� �ش� �̸� ����
		}
	}
	return NULL;
}