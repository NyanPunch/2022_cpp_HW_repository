/*******************************
���α׷���: �ǽ� 8-1
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 09
���α׷� ����: Subject Class Test
********************************/

#include <iostream>
#include <string>
using namespace std;

class Subject {
protected:
	string m_name;	//�����
	int m_hakjum;	//����
	string m_grade;	//���
	float m_GPA;	//����
public:
	void Initialize();	//������� �ʱ�ȭ
	void Initialize(string, int, string); //���ڰ����� ������� �ʱ�ȭ
	void InputValue(int&);
	void InputValue(string&);
	void InputData();	//������� �� �Է� InputValue�̿�
	void PrintTitle();	//��������� ���� ���
	void PrintData();	//������� �� ���
	void CalcGPA();		//���� ���
};

void main() {
	Subject sub1, sub2, sub3[2], *sub4;
	int i;

	sub1.Initialize(); //���� �ʱ�ȭ
	sub2.Initialize("���� �ɸ���", 4, "A0");	//���� ���� �Է� �ʱ�ȭ
	for (i = 0; i < 2; i++) 
		sub3[i].Initialize("��ǻ�� ����", 3, "C"); //�迭 [0], [1] ������ �� �Է�
	sub4 = new Subject[2];	//���� �Ҵ�

	/* 1. �Ϲ� ��ü */
	sub1.InputData(); //���� �Է�
	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintTitle();
	sub1.PrintData();

	/* 2. ���ڰ� ���� �Ϲ� ��ü */
	cout << "\n" << "sub2 ����" << "\n";
	sub2.PrintTitle();
	sub2.PrintData();	//sub2.Initialize ��� 

	/* 3. ��ü �迭 */
	cout << "\n" << "sub3 ����" << "\n";
	sub3[0].PrintTitle();	//Ÿ��Ʋ ���
	for (i = 0; i < 2; i++) sub3[i].PrintData(); // �迭 [0], [1] ���

	/* 4. ��ü ������ */
	for (i = 0; i < 2; i++)(sub4 + i)->InputData(); //�� ������ ���� �Է�
	cout << "\n" << "sub4 ����" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++)(sub4 + i)->PrintData(); //�� ���� ���

	delete[] sub4;
}

void Subject::Initialize()
{
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0;
}

void Subject::Initialize(string name, int hakjum, string grade)
{
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA(); //�ش���� ���� ���
}

inline void Subject::InputValue(int& i)
{
	cin >> i; cin.ignore(); //���� ����
}

inline void Subject::InputValue(string& str)
{
	getline(cin, str);
}

void Subject::InputData()
{
	cout << "\n����� : "; InputValue(m_name);
	cout << "���� : "; InputValue(m_hakjum);
	cout << "��� : "; InputValue(m_grade);
	CalcGPA();
}

void Subject::PrintTitle()
{
	cout << "--------------------------------------------\n";
	cout << " �������     ������   ���     ����\n";
	cout << "--------------------------------------------\n";
}

void Subject::PrintData()
{
	cout << " " << m_name << "\t" << m_hakjum << "\t" << m_grade << "\t" << m_GPA << endl;
	cout << "--------------------------------------------\n";
}

void Subject::CalcGPA()
{
	if (m_grade == "A+")
		m_GPA = m_hakjum * 4.5;
	else if (m_grade == "A" || m_grade == "A0")
		m_GPA = m_hakjum * 4.0;
	else if (m_grade == "B+")
		m_GPA = m_hakjum * 3.5;
	else if (m_grade == "B" || m_grade == "B0")
		m_GPA = m_hakjum * 3.0;
	else if (m_grade == "C+")
		m_GPA = m_hakjum * 2.5;
	else if (m_grade == "C" || m_grade == "C0")
		m_GPA = m_hakjum * 2.0;
	else if (m_grade == "D+")
		m_GPA = m_hakjum * 1.5;
	else if (m_grade == "D" || m_grade == "D0")
		m_GPA = m_hakjum * 1.0;
	else if (m_grade == "F")
		m_GPA = m_hakjum * 0.0;
}