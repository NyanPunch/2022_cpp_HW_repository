#ifndef Subject_h
#define Subject_h

#include <iostream>
#include <string>
#include "Interface.h"
using namespace std;

class Subject : public IOInterface{
protected:
	string m_name;	//�����
	int m_hakjum;	//����
	string m_grade;	//���
	float m_GPA;	//����
public:
	/* ������ */
	Subject();	//������� �ʱ�ȭ
	Subject(const string, const int, const string); //���ڰ����� ������� �ʱ�ȭ
	Subject(const Subject& sub);
	void InputValue(int&) const;
	void InputValue(string&) const;
	void InputData();	//������� �� �Է� InputValue�̿�
	void PrintData() const;	//������� �� ���
	void CalcGPA();		//���� ���
	/* ������ �Լ� �߰� */
	string GetName()const;	//����� ����
	int GetHakjum()const;	//���� ����
	string GetGrade()const; //��� ����
	float GetGPA()const;	//���� ����
	void SetSub(const Subject&);
	/* #9 */
	void Modify();
	~Subject();
	/* #10 */
	static void PrintTitle();	//��������� ���� ���
};

#endif // !Subject_h