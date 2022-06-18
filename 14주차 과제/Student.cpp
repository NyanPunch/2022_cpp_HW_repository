#include "Student.h"
using namespace std;
/*************************************
*		�л�	���	�Լ�		 *
**************************************/
Student::Student()
{
	cout << "\n�л� ������ ȣ��\n";
	this->m_name = "";
	this->m_hakbun = 0;
	this->m_subnum = 0;
	this->m_sub = NULL;
	this->m_aveGPA = 0.0f;
}
/* ���� ���簡 �����ϰ� ���� */
Student::Student(string m_name, int m_hakbun, int m_subnum, Subject* m_sub)
{
	cout << "\n�л� ���ڻ����� ȣ��\n";
	this->m_name = m_name;
	this->m_hakbun = m_hakbun;
	this->m_subnum = m_subnum;
	this->m_sub = new Subject[m_subnum];
	for (int i = 0; i < this->m_subnum; i++)
		this->m_sub[i].SetSub(m_sub[i]);
	this->m_aveGPA = 0.0f;
	CalcAveGPA(); //��� ���� ����Ͽ� ����
}
/* ���� ���縦 �ϵ��� */
Student::Student(const Student& std)
{
	cout << "\n�л� ��������� ȣ��\n";
	this->m_name = std.m_name;
	this->m_hakbun = std.m_hakbun;
	this->m_subnum = std.m_subnum;
	this->m_sub = new Subject[std.m_subnum];
	for (int i = 0; i < this->m_subnum; i++)
		this->m_sub[i].SetSub(std.m_sub[i]);
	CalcAveGPA();
}
/* �Ҹ��� */
Student::~Student()
{
	cout << "\n�л� �Ҹ��� ȣ��\n";
	delete[] m_sub;					
}

inline void Student::InputValue(int& i) const
{
	cin >> i; cin.ignore();
}

inline void Student::InputValue(string& str) const
{
	getline(cin, str);
}

void Student::InputData() //���� ���� �Լ� ������
{	
	cout << "\n";
	cout << "�̸� : "; InputValue(m_name);
	cout << "�й� : "; InputValue(m_hakbun);
	cout << "���� �� : "; InputValue(m_subnum);
	m_sub = new Subject[m_subnum];	//����� ��ŭ �����Ҵ�
	for (int i = 0; i < m_subnum; i++) {//����� ��ŭ �������� �Է�
		m_sub[i].InputData();	//����Ŭ���� ���
	}
	CalcAveGPA();	//������� ��� �Լ� ���ο��� m_aveGPA �Է�
}

void Student::PrintData() const
{
	cout << "\n============================================\n";
	cout << " �̸� : " << m_name << "\t �й� : " << m_hakbun;
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "\t\t\t�������\t" << m_aveGPA << endl;
}

void Student::CalcAveGPA() //m_GPA�� ������ �Լ� ����ؾ� ���� �� ����
{
	if (m_aveGPA > 0.0) m_aveGPA = 0.0;	//��ó�� �ʱ�ȭ
	for (int i = 0; i < m_subnum; i++)
		m_aveGPA += m_sub[i].GetGPA();
	m_aveGPA = m_aveGPA / m_subnum;	/* �� ���� / ����� */
}

string Student::GetName() const{	//�л��̸� ����
	return m_name;
}

int Student::GetHakbun() const {	//�й� ����
	return m_hakbun;
}

int Student::GetSubNum() const {	//����� ����
	return m_subnum;
}

float Student::GetAveGPA() const { //������� ����
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
		string SearchSub; //����˻�
		cout << "\n������ ������� �Է��ϼ���. "; getline(cin, SearchSub);
		Subject* ptr = SubSearch(SearchSub);
		if(ptr)	ptr->Modify(); //����˻��� NULL�� ���ϵ��� ������ ���� ����
		//this->m_sub->Modify();
		CalcAveGPA();
	}
}

Subject* Student::SubSearch(string subname) const { //subname == searchSub
	int i, temp = 0;
	for (i = 0; i < this->m_subnum; i++) { //return == �޸��ּ� �����Ұ�
		if (this->m_sub[i].GetName().compare(subname) == 0) {
			temp = 1; break;
		}
	}
	if (temp == 1) return &(this->m_sub[i]);
	cout << "\nã���ô� �������� �����ϴ�!\n";
	return NULL;
}