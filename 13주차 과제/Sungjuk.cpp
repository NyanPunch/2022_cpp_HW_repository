/*******************************
���α׷���: �ǽ�#11
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 27
���α׷� ����: ���Ŭ����
������Ʈ ����: Interface.h, Student.cpp->Modify()
********************************/
#include "Student.h"
#include "Subject.h"
#include "Interface.h"
using namespace std;

/*****************************
*		����	�Լ�		 *
*****************************/
int main() {
	Subject sub("��ǻ��", 3, "C");
	cout << "-------------------------\n";
	cout << "m_data : " << sub.GetData();							//IOInterface Ŭ������ GetData��� Data �Է��� ���� �ʾ� �����Ⱚ ���
	cout << "\n������ �̸� : " << sub.Subject::GetName();			//SubjectŬ������ GetName�Լ� ��� : "��ǻ��"
	cout << "\n�θ�Ŭ������ �̸� : " << sub.IOInterface::GetName(); //IOInterfaceŬ���� GetName�Լ� ��� : "��ǻ��"
	cout << "\n-------------------------\n";

	Student std("����", 2019038054, 1, &sub);
	cout << "-------------------------\n";
	cout << "m_data : " << std.GetData();							//IOInterface Ŭ������ GetData��� Data �Է��� ���� �ʾ� �����Ⱚ ���
	cout << "\n�л� �̸� : " << std.Student::GetName();				//StudentŬ������ GetName�Լ� ��� : "����"
	cout << "\n�θ�Ŭ������ �̸� : " << std.IOInterface::GetName(); //IOInterfaceŬ���� GetName�Լ� ��� : "����"
	cout << "\n-------------------------\n";
}

/* 11-4 �����Լ�
	Subject sub("��ǻ��", 3, "C");
	Student std("����", 2019038054, 1, &sub);

	std.PrintData();
	std.Modify(); //������� �� ����
	std.PrintData();
*/