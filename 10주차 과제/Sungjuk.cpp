/*******************************
���α׷���: �ǽ� 8-4 ���� ����
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 11
���α׷� ����: �� Ŭ���� ���� ������Ͽ� �ҽ����� ���� ������
������Ʈ ����: Student.cpp Subject.cpp Sungjuk.cpp Student.h Subject.h
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

/*****************************
*		����	�Լ�		 *
*****************************/
int main() {
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

	return 0;
}