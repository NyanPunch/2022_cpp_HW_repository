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
	void Initialize();	//������� �ʱ�ȭ
	void Initialize(string, int, string); //���ڰ����� ������� �ʱ�ȭ
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
};

#endif // !Subject_h