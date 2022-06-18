#ifndef GradeManager_h
#define GradeManager_h

#include <iostream>
#include <string>
#include "Student.h"

class GradeManager {
protected:
	Student* m_std;	//��ü �л� ������ ��� ����
	int m_stdnum;	//�����ϰ� �ִ� ��ü �л� ��
public:
	GradeManager();
	GradeManager(int m_stdnum);
	~GradeManager();
	void Execute();	//�л� ������ �����ϴ� �Լ�
protected:
	static void PrintMenu();		//�޴� ���
	Student* StdSearch(string stdname) const; //���ϴ� �л� �˻�
	void PrintAllStdList() const;	//��ü �л� ��� ���
	void Modify();					//���ϴ� �л��� ���� ����
};
#endif // !GradeManager_h