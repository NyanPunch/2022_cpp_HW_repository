#include "Student.h"
#include <string>
using namespace std;
/*************************************
*		�л�	���	�Լ�		 *
**************************************/
void Student::Initialize()
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
}

void Student::Initialize(string str, int hakbun, int subnum, Subject* sub)
{
	m_name = str;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = sub;
	m_aveGPA = 0.0f;
	CalcAveGPA(); //��� ���� ����Ͽ� ����
}

void Student::Remove()
{
	delete[] m_sub;
}

inline void Student::InputValue(int& i)
{
	cin >> i; cin.ignore();
}

inline void Student::InputValue(string& str)
{
	getline(cin, str);
}

void Student::InputData() //���������� Subject Class�� InputData() ���
{
	cout << "�̸� : "; InputValue(m_name);
	cout << "�й� : "; InputValue(m_hakbun);
	cout << "���� �� : "; InputValue(m_subnum);
	m_sub = new Subject[m_subnum];	//����� ��ŭ �����Ҵ�
	for (int i = 0; i < m_subnum; i++) {//����� ��ŭ �������� �Է�
		m_sub[i].InputData();	//����Ŭ���� ���
	}
	CalcAveGPA();	//������� ��� �Լ� ���ο��� m_aveGPA �Է�
}

void Student::PrintData()
{
	cout << "============================================\n";
	cout << " �̸� : " << m_name << "\t �й� : " << m_hakbun;
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "\t\t\t�������\t" << m_aveGPA;
}

void Student::CalcAveGPA() //m_GPA�� ������ �Լ� ����ؾ� ���� �� ����
{
	for (int i = 0; i < m_subnum; i++)
		m_aveGPA += m_sub[i].GetGPA();
	m_aveGPA = m_aveGPA / m_subnum;	/* �� ���� / ����� */
}

string Student::GetName() {	//�л��̸� ����
	return m_name;
}

int Student::GetHakbun() {	//�й� ����
	return m_hakbun;
}

int Student::GetSubNum() {	//����� ����
	return m_subnum;
}

float Student::GetAveGPA() { //������� ����
	return m_aveGPA;
}