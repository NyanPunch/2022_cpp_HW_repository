#include "Student.h"
using namespace std;
/*************************************
*		�л�	���	�Լ�		 *
**************************************/
Student::Student()
{
	cout << "\n�л� ������ ȣ��\n";
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
}
/* ���� ���簡 �����ϰ� ���� */
Student::Student(string str, int hakbun, int subnum, Subject* sub)
{
	cout << "\n�л� ���ڻ����� ȣ��\n";
	m_name = str;	
	m_hakbun = hakbun; 
	m_subnum = subnum; 
	m_sub = new Subject[m_subnum];
	for (int i = 0; i < m_subnum; i++)
		this->m_sub[i] = sub[i];
	m_aveGPA = 0.0f;
	CalcAveGPA(); //��� ���� ����Ͽ� ����
}
/* ���� ���縦 �ϵ��� */
Student::Student(const Student& std)
{
	cout << "\n�л� ��������� ȣ��\n";
	this->m_name = std.m_name;
	this->m_hakbun = std.m_hakbun;
	this->m_subnum = std.m_subnum;
	this->m_sub = new Subject[this->m_subnum];	
	for (int i = 0; i < this->m_subnum; i++)
		this->m_sub[i] = Subject(std.m_sub[i]);
	CalcAveGPA();
}
/* �Ҹ��� */
Student::~Student()
{
	cout << "\n�л� �Ҹ��� ȣ��\n";
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
	cout << "\n============================================\n";
	cout << " �̸� : " << m_name << "\t �й� : " << m_hakbun;
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "\t\t\t�������\t" << m_aveGPA;
}

void Student::CalcAveGPA() //m_GPA�� ������ �Լ� ����ؾ� ���� �� ����
{
	if (m_aveGPA > 0.0) m_aveGPA = 0.0;	//��ó�� �ʱ�ȭ
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

void Student::Modify() { //�����ϴ� �л��� ������ ���·� ȣ���
	/* �л�����, �������� ���ڿ� �Է¹ް� �ش� �κ� ���� */
	string TYPE;
	cout << "\n������ ������ �Է��ϼ���<�л�����/��������/���> : ";
	getline(cin, TYPE);
	if (TYPE == "�л�����" || TYPE == "���") {
		cout << "\n < " << m_name << " " << m_hakbun << " >�� ������ �����ϼ���\n";
		cout << "�̸� : "; InputValue(this->m_name);
		cout << "�й� : "; InputValue(this->m_hakbun);
	}
	if (TYPE == "��������" || TYPE == "���") {
		this->m_sub->Modify(); //�������� ����
		CalcAveGPA();
	}
}