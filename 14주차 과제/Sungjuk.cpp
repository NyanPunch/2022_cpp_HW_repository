/*******************************
���α׷���: �ǽ�#12
�� �� ��: 2019038054 ����
�� �� ��: 2022 06 01
���α׷� ����: ���� �Լ� �����, �߻� Ŭ���� �����, �������� Ŭ���� �߰�
������Ʈ ����: Interface.h GradeManager.h/.cpp
********************************/
#include "Student.h"
#include "Subject.h"
#include "Interface.h"
#include "GradeManager.h"
using namespace std;

/*****************************
*		����	�Լ�		 *
*****************************/
int main() {
	int stdnum;
	cout << "�Է��� �л� ���� �Է� : ";
	cin >> stdnum; cin.ignore();
	GradeManager GradeMgr(stdnum);
	GradeMgr.Execute();
}

/*
	Student std;
	std.InputData();

	IOInterface* IO[2] = { new Subject("������",3,"A+"), &std };

	for (int i = 0; i < 2; i++) {
		cout << "\n* " << i + 1 << "��° ������ : \n";
		IO[i]->PrintData(); //�Ļ�Ŭ���� ����Լ� ȣ���Ű��
	}
*/