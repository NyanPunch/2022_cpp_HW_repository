/*******************************
���α׷���: ����ó�����α׷� 3
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 09
���α׷� ����: �л��� ������ �Է¹ް� �䱸���׿� �°� ���
������Ʈ ����: PrintMenu, InputValue, PrintAllStdList, ModifyStdInfo
********************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#define MAX_Std 2			//�л� �ο���
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

int menu = 0; 

void InputData(student* pSt, int StudentNum);			//�����Է��Լ�
void CalcGPA(Subject& Sub);				//������ ������� 
float CalcAveGPA(Subject* Sub);			//�����л� ��� ���� ��� 
void PrintAllData(const student* pSt, int StudentNum);	//��ü�л� �Ż�/���� ��� 
void PrintOneData(const student& rSt);					//�����л� �Ż�/���� ��� 
student* StdSearch(student* pSt, int StudentNum);		//�л� �̸� �˻� �� �ش� �л� ������ �ִ°��� �ּ� ����
void PrintAllStdList(student* pSt, int StudentNum);
void ModifyStdInfo(student *pSt);
inline void PrintMenu();				//�޴����

inline void InputValue(char* str) {
	cin >> str;
}
inline void InputValue(int& i) {
	cin >> i;
}

int main() {
	cout.precision(2);
	cout << fixed;
	struct student s[MAX_Std];
	int flag = 0;
	while (menu != 6) {
		PrintMenu();
		if (menu == 1)
			flag = 1;	//���� �� ���� �� ���� ���, �л� ���� �˻��� �Ϸ� �Ҷ�
		else if ((menu == 2) && (flag == 0) || (menu == 3) && (flag == 0)) {
			cout << "�л��� ������ �Էµ����� �ʽ��ϴ�. ������ ���� �Է����ּ���.\n" << endl;
			continue;
		}

		switch (menu) {
		case 1:	//�л� ���� �Է�
			InputData(s, MAX_Std);
			break;
		case 2:	//�л� ��ü ���� ���
			PrintAllData(s, MAX_Std);
			break;
		case 3:	//�л� �̸� �˻� �� ���
			student * SearchStd;
			SearchStd = StdSearch(s, MAX_Std);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4:
			PrintAllStdList(s, MAX_Std);
			break;
		case 5:
			ModifyStdInfo(StdSearch(s, MAX_Std));
			break;
		case 6:
			cout << "���α׷��� �����մϴ�\n";
			break;
		default:
			cout << "�������� �ʴ� �����Դϴ�.\n";
			break;
		}
	}
	return 0;
}
/* �޴� */
inline void PrintMenu() {
	cout << "\n===== �޴� =====\n"
		<< "1. �л� ���� �Է�\n"
		<< "2. ��ü �л� ���� ����\n"
		<< "3. �л� �̸� �˻�\n"
		<< "4. ��ü �л� ��� ����\n"
		<< "5. �л� ���� ����\n"
		<< "6. ���α׷� ����" << endl;
	cout << "���ϴ� ����� �Է��ϼ��� : ";
	cin >> menu;
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
		Sub.GPA = (float)Sub.hakjum * 0.0;
}

/* ��� ó�� */
float CalcAveGPA(Subject* Sub) {
	float sumGPA = 0;
	for (int i = 0; i < MAX_Sub; i++)
		sumGPA += Sub[i].GPA;
	return (sumGPA / MAX_Sub);
	//avgGPA = sumGPA / MAX_Sub
}

/* 1. �л� ���� �Է� */
void InputData(student *pSt,int StudentNum) {
	int i, j;		// i = �л� j = �л��� �� ����
	float AveGPA;
	for (i = 0; i < MAX_Std; i++, pSt++) {
		cout << endl << "* " << i + 1 << " �� ° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : "; InputValue(pSt->stdname);
		cout << "�й� : "; InputValue(pSt->hakbun);

		cout << endl << "* ������ ���� �� ���� �� �������, ��������, �������� �Է��ϼ���.\n";
		for (j = 0; j < MAX_Sub; j++) {
			cout << "������� : "; InputValue(pSt->Sub[j].subname);
			cout << "�������� : "; InputValue(pSt->Sub[j].hakjum);
			cout << "������(A+ ~ F) : "; InputValue(pSt->Sub[j].grade); cout << endl;
			CalcGPA(pSt->Sub[j]);  //���� ���� ó��
		}
		AveGPA = CalcAveGPA(pSt->Sub);	//��� ���� ó��
		pSt->avgGPA = AveGPA;			//i��° �л��� ��� ���� ����
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

	for (int j = 0; j < MAX_Sub; j++) {	//���� �ݺ� ��¹�
		cout << rSt.Sub[j].subname << setw(10) << rSt.Sub[j].hakjum<< setw(10) << rSt.Sub[j].grade<< setw(10) << rSt.Sub[j].GPA << endl;
	}
	cout << "=========================================\n";
	cout.width(35);
	cout << "�������  " << rSt.avgGPA << endl;
}

/* 3. �̸��� �˻��Ͽ� �л��� ���� ��� */
student* StdSearch(student* pSt, int StudentNum) {
	char SearchName[30];
	cout << "ã�� �л��� �̸��� �Է����ּ���.\n �̸� : ";
	InputValue(SearchName);
	int len = strlen(SearchName);	//�̸����̸�ŭ len�� ���� ����
	for (int i = 0; i < StudentNum; i++,pSt++) {
		for (int j = 0; j < len; j++) {
			if (strlen(pSt->stdname) == len && (pSt->stdname[j] == SearchName[j]))
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
	for (int i = 0; i < StudentNum; i++,pSt++) {
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