/*******************************
���α׷���: ����ó�����α׷�
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 04 ~ 2022 03 11
���α׷� ����: �л��� ������ �Է¹ް� �䱸���׿� �°� ���
********************************/
#include <iostream>
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

void inputdata(student s[]);			//�����Է��Լ�
void print_list(student s[]);			//��������Լ�
void cal_grade(student s[]);			//��������Լ�

int main() {
	student s[MAX_Stu];
	cout.precision(2);
	cout << fixed;
	int flag = 0;
	while (1) {
		cout << "\n===== �޴� =====\n"
			<< "1. �л� ���� �Է�\n"
			<< "2. ��ü �л� ���� ����\n"
			<< "3. ���α׷� ����" << endl;

		cout << "���ϴ� ����� �Է��ϼ��� : ";
		
		int menu;
		cin >> menu;
		cout << endl;
		
		if (menu == 1)		//���� �� ���� �� ���� ����� �Ϸ� �Ҷ�
			flag = 1;
		else if ((menu == 2) && (flag == 0)) {
			cout << "�л� ���� ���� �Է����ּ���\n" << "���� �Է¶����� �̵��մϴ�." << endl;
			menu = 1;		//break ��� �� ����� ������ 1�� �̵�
			flag = 1;
		}
		
		switch (menu) {
		case 1:
			inputdata(s);
			cal_grade(s);		
			break;
		case 2:
			print_list(s);
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "\n1~3���� �Է��ϼ���.\n";		// 1 ~ 3 �� �Է� �� ��� (��ȣ�� �ش�, ���� �Է½� ���ѷ���)
			break;
		}
	}
	return 0;
}

void inputdata(student s[]) {						//���� �Է� �Լ� case 1:
	int i, j;							// i = �л� j = �л��� �� ����

	for (i = 0; i < MAX_Stu; i++) {		
		cout << endl << "* " << i + 1 << " �� ° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		cin >> s[i].stdname;
		cout << "�й� : ";
		cin >> s[i].hakbun;
		cout << endl << "* ������ ���� �� ���� �� �������, ��������, �������� �Է��ϼ���.\n";
		for (j = 0; j < MAX_Sub; j++) {
			cout << "������� : ";
			cin >> s[i].Sub[j].subname;
			cout << "�������� : ";
			cin >> s[i].Sub[j].hakjum;
			cout << "������(A+ ~ F) : ";
			cin >> s[i].Sub[j].grade; cout << endl;

			//���� ���� ó��	//���� //���� �ذ�
			if (strcmp(s[i].Sub[j].grade, "A+") == 0)
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 4.5;
			else if ((strcmp(s[i].Sub[j].grade, "A0") == 0) || (strcmp(s[i].Sub[j].grade, "A") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 4.0;
			else if ((strcmp(s[i].Sub[j].grade, "B+") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 3.5;
			else if ((strcmp(s[i].Sub[j].grade, "B0") == 0) || (strcmp(s[i].Sub[j].grade, "B") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 3.0;
			else if ((strcmp(s[i].Sub[j].grade, "C+") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 2.5;
			else if ((strcmp(s[i].Sub[j].grade, "C0") == 0) || (strcmp(s[i].Sub[j].grade, "C") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 2.0;
			else if ((strcmp(s[i].Sub[j].grade, "D+") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 1.5;
			else if ((strcmp(s[i].Sub[j].grade, "D0") == 0) || (strcmp(s[i].Sub[j].grade, "D") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 1.0;
			else if ((strcmp(s[i].Sub[j].grade, "F") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 0.0;
		}
	}
}


void cal_grade(student s[]) {		//������� ��� �Լ� //���� �ذ�
	int i, j;

	for (i = 0; i < MAX_Stu; i++) {
		for (j = 0; j < MAX_Sub; j++) {
			s[i].avgGPA = s[i].Sub[j].GPA / s[i].Sub[j].hakjum;
		}
	}
}

void print_list(student s[]) {						//�л� ���� ����Լ� case 2:
	cout.width(10);
	cout << "��ü �л� ��������\n";

	int i, j;

	for (i = 0; i < MAX_Stu; i++) {					//�л� �ݺ� ��¹�
		cout << "=========================================\n";
		cout << "�̸� : " << s[i].stdname << " �й� : " << s[i].hakbun << endl;
		cout << "=========================================\n";
		cout.width(10); cout << "�����";
		cout.width(10); cout << "��������";
		cout.width(10); cout << "������";
		cout.width(10); cout << "��������" << endl;
		cout << "=========================================\n";

		for (j = 0; j < MAX_Sub; j++) {				//���� �ݺ� ��¹�
			cout.width(10); cout << s[i].Sub[j].subname;
			cout.width(10); cout << s[i].Sub[j].hakjum;
			cout.width(10); cout << s[i].Sub[j].grade;
			cout.width(10); cout << s[i].Sub[j].GPA << endl;
		}
		cout << "=========================================\n";
		cout.width(35);
		cout << "�������  " << s[i].avgGPA << endl;
	}
}