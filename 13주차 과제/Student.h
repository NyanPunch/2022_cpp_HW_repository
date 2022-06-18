#ifndef Student_h
#define Student_h

#include <string>
#include <iostream>
#include "Subject.h"
#include "Interface.h"
using namespace std;

class Student : public IOInterface {
protected:
	string m_name;	//�л��̸�
	int m_hakbun;	//�й�
	int m_subnum;	//�����
	Subject* m_sub;	//��������
	float m_aveGPA;	//�������
public:
	/* ������ */
	Student();	//������ �ʱ�ȭ
	Student(string, int, int, Subject*); //������ �ʱ�ȭ
	Student(const Student& std);

	void InputValue(int&) const;
	void InputValue(string&) const;
	void InputData();
	void PrintData() const;
	void CalcAveGPA();
	/* ������ �Լ� �߰� */
	string GetName() const;	//�л��̸� ����
	int GetHakbun() const;	//�й� ����
	int GetSubNum() const;	//����� ����
	float GetAveGPA() const;	//������� ����
	/* friend func */
	//friend void ShowData(const Student&);
	/* #9 */
	void Modify();
	~Student();
	/* #10 */
	Subject* SubSearch(string subname) const;
};
#endif // !Student_h
