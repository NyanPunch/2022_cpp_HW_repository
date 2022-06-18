#include "Subject.h"
using namespace std;
/* ���� ��� �Լ� */
Subject::Subject()
{
	cout << "\n���� ������ ȣ��\n";
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0f;
}

Subject::Subject(string name, int hakjum, string grade)
{
	cout << "\n���� ���ڻ����� ȣ��\n";
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	m_GPA = 0.0f;
	CalcGPA(); //�ش���� ���� ���
}

Subject::Subject(const Subject& sub)
{
	cout << "\n���� ��������� ȣ��\n";
	this->m_name = sub.m_name;
	this->m_hakjum = sub.m_hakjum;
	this->m_grade = sub.m_grade;
	this->m_GPA = sub.m_GPA;
	CalcGPA();
}

Subject::~Subject()
{
	cout << "\n���� �Ҹ��� ȣ��\n";
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
	cout << "\n--------------------------------------------\n";
	cout << " �������\t������\t���\t����\n";
}

void Subject::PrintData()
{
	cout << "--------------------------------------------\n";
	cout << " " << m_name << " \t" << m_hakjum << "\t" << m_grade << "\t" << m_GPA << endl;
	cout << "--------------------------------------------\n";
}
/* ���� ��� */
void Subject::CalcGPA()
{
	if (m_grade == "A+")
		m_GPA = m_hakjum * 4.5f;
	else if (m_grade == "A" || m_grade == "A0")
		m_GPA = m_hakjum * 4.0f;
	else if (m_grade == "B+")
		m_GPA = m_hakjum * 3.5f;
	else if (m_grade == "B" || m_grade == "B0")
		m_GPA = m_hakjum * 3.0f;
	else if (m_grade == "C+")
		m_GPA = m_hakjum * 2.5f;
	else if (m_grade == "C" || m_grade == "C0")
		m_GPA = m_hakjum * 2.0f;
	else if (m_grade == "D+")
		m_GPA = m_hakjum * 1.5f;
	else if (m_grade == "D" || m_grade == "D0")
		m_GPA = m_hakjum * 1.0f;
	else if (m_grade == "F")
		m_GPA = m_hakjum * 0.0f;
}

string Subject::GetName()	//����� ����
{
	return m_name;
}

int Subject::GetHakjum()	//���� ����
{
	return m_hakjum;
}

string Subject::GetGrade()	//��� ����
{
	return m_grade;
}

float Subject::GetGPA()		//���� ����
{
	return m_GPA;
}

/* �������� ���� */
void Subject::Modify() {
	cout << "\n < " << m_name << ", " << m_hakjum << ", " << m_grade << " >�� ������ �����ϼ���.\n";
	cout << "������� : "; InputValue(this->m_name);
	cout << "�������� : "; InputValue(this->m_hakjum);
	cout << "������ : "; InputValue(this->m_grade);
	CalcGPA();
}