#ifndef Subject_h
#define Subject_h

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
	/* ������ */
	Subject();	//������� �ʱ�ȭ
	Subject(string, int, string); //���ڰ����� ������� �ʱ�ȭ
	Subject(const Subject& sub);
	void InputValue(int&);
	void InputValue(string&);
	void InputData();	//������� �� �Է� InputValue�̿�
	void PrintTitle();	//��������� ���� ���
	void PrintData();	//������� �� ���
	void CalcGPA();		//���� ���
	/* ������ �Լ� �߰� */
	string GetName();	//����� ����
	int GetHakjum();	//���� ����
	string GetGrade(); //��� ����
	float GetGPA();		//���� ����

	/* #9 */
	void Modify();
	~Subject();
};

#endif // !Subject_h