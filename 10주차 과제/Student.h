#ifndef Student_h
#define Student_h

#include <string>
#include <iostream>
#include "Subject.h"
using namespace std;

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
	string GetName();	//�л��̸� ����
	int GetHakbun();	//�й� ����
	int GetSubNum();	//����� ����
	float GetAveGPA();	//������� ����

	friend void ShowData(const Student&); //friend �Լ� ����
};
#endif // !Student_h
