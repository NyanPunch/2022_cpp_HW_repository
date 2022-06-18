/*******************************
���α׷���: ����ó�����α׷� 5
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 25 ~ 2022 04 29
���α׷� ����: �л��� ������ �Է¹ް� �䱸���׿� �°� ���
������Ʈ ����: string�Լ� �̿�, getline() ���, ModifyStdInfo(), 
********************************/
#include <iostream>
#include <string>			
#include <iomanip>
#include <cstring>

using namespace std;

struct Subject {			//���� ���� ����ü
	string subname;		    //���� ��			/* string ���� */
	int hakjum;				//���� ����
	char grade[10];			//���� ���
	float GPA;				//���� ����
};

struct student {			//�л� ���� ����ü
	string stdname;		    //�̸�				/* string ���� */
	int hakbun;				//�й�
	Subject* Sub;			//����
	int SubNum;				//���� ��
	float aveGPA;			//������ ��� ����
};

int menu = 0;

void InputData(student* pSt, int StudentNum);			//�����Է��Լ�
void CalcGPA(Subject& Sub);								//������ �������
float CalcAveGPA(Subject* Sub, int SubNum);				//�����л� ��� ���� ���
void PrintAllData(const student* pSt, int StudentNum);	//��ü�л� ��� 
void PrintOneData(const student& rSt);					//�����л� ���
void PrintAllStdList(student* pSt, int StudentNum);		//�л� ����Ʈ
void ModifyStdInfo(student* pSt);						//�л� ���� ����
student* StdSearch(student* pSt, int StudentNum);		//�л� �˻�
Subject* SubSearch(const student* pSt);					//���� �˻�

inline void InputValue(char* str) {
	cin >> str; cin.ignore();
}
inline void InputValue(int& i) {
	cin >> i; cin.ignore();
}
inline void InputValue(string& str) {
	getline(cin, str);
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
	InputValue(menu);
}

int main() {
	cout.precision(2);
	cout << fixed;
	struct student* Std = NULL;	//�л� ����ü ���� �޸� �Ҵ�
	int flag = 0, StdNum = 2;

	cout << "\n������ ����� �л� ���� �Է����ּ���. : ";
	cin >> StdNum;
	Std = new student[StdNum]; // ���� �޸� ���
	
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
			InputData(Std, StdNum);
			break;
		case 2:	//�л� ��ü ���� ���
			PrintAllData(Std, StdNum);
			break;
		case 3:	//�л� �̸� �˻� �� ���
			student * SearchStd;
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4: //�л� ����Ʈ ���
			PrintAllStdList(Std, StdNum);
			break;
		case 5: //�л� ���� ����
			ModifyStdInfo(StdSearch(Std, StdNum));
			break;
		case 6:
			cout << "\n���α׷��� �����մϴ�\n";
			break;
		default:
			cout << "�������� �ʴ� �����Դϴ�.\n";
			break;
		}
	}
	return 0;
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
}

/* 1. �л� ���� �Է� */
void InputData(student* pSt, int StudentNum) {
	int i, j;			// i = �л� j = �л��� �� ����
	float AveGPA;
	int SubNum;
	for (i = 0; i < StudentNum; i++) {
		cout << endl << "* " << i + 1 << " �� ° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : "; InputValue(pSt[i].stdname);
		cout << "�й� : "; InputValue(pSt[i].hakbun);
		cout << endl;

		cout << "������ ���� ���� �Է� : ";
		InputValue(SubNum);
		pSt[i].SubNum = SubNum; //i��° �л� ����� ����
		/* i�� �л��� ����� ��ŭ ���� �Ҵ� */
		pSt[i].Sub = new Subject[SubNum];

		//n��° �л��� �Է¹��� ���� �� ��ŭ ���� �Ҵ�.
		cout << "\n* ������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
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
	cout << "\n��ü �л� ��������\n";
	for (int i = 0; i < StudentNum; i++, pSt++) PrintOneData(*pSt);
}

/* �л� ���� ���� ���*/
void PrintOneData(const student& rSt) {
	cout << "\n=========================================\n";
	cout << setw(10) << "�̸� : " << rSt.stdname << " �й� : " << rSt.hakbun << endl;
	cout << "=========================================\n";
	cout << setw(10) << "�����" << setw(10) << "��������" << setw(10) << "������ " << setw(10) << "��������" << endl;
	cout << "=========================================\n";

	for (int j = 0; j < rSt.SubNum; j++)	//���� �ݺ� ��¹�
		cout << rSt.Sub[j].subname << setw(10) << rSt.Sub[j].hakjum << setw(10) << rSt.Sub[j].grade << setw(10) << rSt.Sub[j].GPA << endl;
	cout << "=========================================\n";
	cout.width(35);
	cout << "�������  " << rSt.aveGPA << endl;
}

/* 3. �̸��� �˻��Ͽ� �л��� ���� ��� */
student* StdSearch(student* pSt, int StudentNum) {
	string SearchName;
	cout << "\nã�� �л��� �̸��� �Է����ּ���.\n�̸� : ";
	InputValue(SearchName);
	for (int i = 0; i < StudentNum; i++) {
		if (pSt[i].stdname.size() == SearchName.size() && pSt[i].stdname == SearchName) //Searchname�� �̸��� ���ڼ��� ����, ����� �̸��� ���� �� �ش� �̸� ����
			return &pSt[i]; 
	}
	return NULL;
}

/* 4. ��ü �л��� ���: �й��� �̸��� ��� */
void PrintAllStdList(student* pSt, int StudentNum) {
	cout << "\n====================================\n"
		<< setw(10) << "�й�" << setw(10) << "�̸�\n"
		<< "====================================\n";
	for (int i = 0; i < StudentNum; i++, pSt++) 
		cout << setw(10) << pSt->hakbun << setw(10) << pSt->stdname << endl;
	cout << "====================================\n";
}

/* 5. Ư�� �л��� �̸��� �й� ���� */
void ModifyStdInfo(student* pSt) {
	/* �л�����, �������� ���ڿ� �Է¹ް� ���� */
	if (pSt != NULL) {
		string TYPE;

		cout << "������ ������ �Է��ϼ���<�л�����/��������> : ";
		InputValue(TYPE);
		/*�л����� or �������� ����*/
		if (TYPE == "�л�����") {
			cout << "\n* <" << pSt->stdname << " " << pSt->hakbun << ">�� ������ �����ϼ���" << endl;
			cout << "�̸� : "; InputValue(pSt->stdname);
			cout << "�й� : "; InputValue(pSt->hakbun);
		}
		else if (TYPE == "��������") {
			Subject* Sub = SubSearch(pSt);
			if (Sub != NULL) {
				cout << "* <" << pSt->Sub->subname << ", ����: " << pSt->Sub->hakjum << ", ���: " << pSt->Sub->grade << ">�� ������ �����ϼ���" << endl;
				cout << "������� : "; InputValue(pSt->Sub->subname);
				cout << "�������� : "; InputValue(pSt->Sub->hakjum);
				cout << "������ : "; InputValue(pSt->Sub->grade);
				CalcGPA(*Sub);
				int SubNum = pSt->SubNum;  
				pSt->aveGPA = CalcAveGPA(Sub,SubNum);
			}
		}
	}
}
/* �л��� �������� ���� �Լ� */
Subject* SubSearch(const student* pSt) {
	string SearchSub;
	cout << "�˻��� ���� �̸� : ";
	InputValue(SearchSub);
	int SubNum = pSt->SubNum;
	for (int i = 0; i < SubNum;i++) {
		if (pSt->Sub[i].subname.size() == SearchSub.size() && pSt->Sub[i].subname == SearchSub)
			return &pSt->Sub[i];
	}
	return NULL;
}
