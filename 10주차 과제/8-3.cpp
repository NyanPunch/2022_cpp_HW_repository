/*******************************
���α׷���: �ǽ� 8-3 �л� Ŭ���� �߰�
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 10
���α׷� ����: Student Class #1
������Ʈ ����: class Student{};
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

class Student {
protected:
	string m_name;	//�л��̸�
	int m_hakbun;	//�й�
	int m_subnum;	//�����
	Subject* m_sub;	//��������
	float m_aveGPA;	//�������
public:
	void Initialize();	//������ �ʱ�ȭ
	void Initialize(string, int, int, Subject*); //������ �ʱ�ȭ
	void Remove();		//�����Ҵ� �޸� ����
	void InputValue(int&);	
	void InputValue(string&);
	void InputData();
	void PrintData();
	void CalcAveGPA();
	/* ������ �Լ� �߰� */
	string GetName() {	//�л��̸� ����
		return m_name;
	}	
	int GetHakbun() {	//�й� ����
		return m_hakbun;
	}	
	int GetSubNum() {	//����� ����
		return m_subnum;
	}
	float GetAveGPA() { //������� ����
		return m_aveGPA;
	}
};
/*****************************
*		����	�Լ�		 *
*****************************/
void main() {
	Subject sub[2];
	sub[0].Initialize("��ǻ��", 3, "C");
	sub[1].Initialize("���빫��", 2, "A");

	Student st1, st2;
	st1.Initialize();
	/* st2 ����� sub�迭�� ����� ���� 2�� ���� */
	st2.Initialize("ȫ�浿", 2013909845, 2, sub);

	/* st1 ���� �Է� �� ��� */
	st1.InputData();
	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData();

	/* st2 ���� ��� */
	cout << "\n" << "st2 ����" << "\n";
	st2.PrintData();

	/* ������ �Լ� �̿� */
	cout << "\n< ������ �Լ��� �̿��� ��� >\n";
	cout << "\n�л��� : " << st1.GetName();
	cout << "\n�й� : " << st1.GetHakbun();
	cout << "\n���� �� : " << st1.GetSubNum();
	cout << "\n������� : " << st1.GetAveGPA();

	/*���� �Ҵ� ����*/
	st1.Remove();
}
/* ���� ��� �Լ� */
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
	m_GPA = 0.0f;
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
	cout << "\n--------------------------------------------\n";
	cout << " �������\t������\t���\t����\n";
	cout << "--------------------------------------------\n";
}

void Subject::PrintData()
{
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
