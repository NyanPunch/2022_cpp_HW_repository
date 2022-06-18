/*******************************
���α׷���: �ǽ� 8-2 ������ �Լ� �߰�
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 09
���α׷� ����: Subject Class Test #2
������Ʈ ����: GetName() GetHakjum() GetGrade() GetGPA()
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
	/* ������ �Լ� �߰� */
	string GetName() { //����� ����
		return m_name;
	}
	int GetHakjum() { //���� ����
		return m_hakjum;
	}
	string GetGrade() { //��� ����
		return m_grade;
	}
	float GetGPA() { //���� ����
		return m_GPA;
	}
};

/* ���� �Լ� */
void main() {
	Subject sub1;

	sub1.Initialize("���� �ɸ���", 4, "A0");	//���� ���� �Է� �ʱ�ȭ

	/* �Ϲ� ��ü */
	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintTitle();
	sub1.PrintData();
	cout << "\n< ������ �Լ��� �̿��� ���� ��� >\n";
	cout << "\n���� �� : " << sub1.GetName();
	cout << "\n���� ���� : " << sub1.GetHakjum();
	cout << "\n���� ��� : " << sub1.GetGrade();
	cout << "\n���� ���� : " << sub1.GetGPA();

	Subject sub3[2];	//�迭 ����
	/* ��ü �迭 ������ �Լ� ��� */
	sub3[0].Initialize("��ǻ�� ����", 3, "C");

	cout << "\n< ������ �Լ��� �̿��� ���� ��� >\n";
	cout << "\n���� �� : " << sub3[0].GetName();
	cout << "\n���� ���� : " << sub3[0].GetHakjum();
	cout << "\n���� ��� : " << sub3[0].GetGrade();
	cout << "\n���� ���� : " << sub3[0].GetGPA();

	sub3[1].Initialize("�ڷᱸ��", 3, "A");

	cout << "\n���� �� : " << sub3[1].GetName();
	cout << "\n���� ���� : " << sub3[1].GetHakjum();
	cout << "\n���� ��� : " << sub3[1].GetGrade();
	cout << "\n���� ���� : " << sub3[1].GetGPA();
}
/* ��ü �ʱ�ȭ */
void Subject::Initialize()
{
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0f;
}
/* ��ü �ʱ�ȭ */
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
