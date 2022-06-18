/*******************************
���α׷���: �ǽ� 8-5 friend �Լ�
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 11
���α׷� ����: Student Class friend �Լ� ����
������Ʈ ����: ShowData(), Student.h->friend ShowData ����
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

void ShowData(const Student&);

/*****************************
*		����	�Լ�		 *
*****************************/
int main() {
	/* �Ϲ� ��ü */
	Student st;

	st.Initialize();
	st.InputData();
	st.PrintData();
	ShowData(st);

	st.Remove();
	/* �迭 ��ü */
	Subject sub[2];
	sub[0].Initialize("��ǻ�� ����", 3, "A0");
	sub[1].Initialize("��ü����", 3, "A");

	st.Initialize("����", 2019038054, 2, sub);
	st.PrintData();
	ShowData(st);

	/* ������ ��ü */
	Student* pSt;
	pSt = new Student[2];

	for (int i = 0; i < 2; i++) {
		(pSt + i)->Initialize();
		(pSt + i)->InputData();
	}
	for (int i = 0; i < 2; i++) {
		(pSt + i)->PrintData();
		ShowData(pSt[i]);
	}

	return 0;
}

void ShowData(const Student& s) { // �������α׷��� �ִ� �����Լ�
	cout << "\n\n" << s.m_name << "�� ������ ������ �� " << s.m_subnum << "���� ";
	cout << "������ ������ ���������" << s.m_aveGPA << "�Դϴ�.\n";
}