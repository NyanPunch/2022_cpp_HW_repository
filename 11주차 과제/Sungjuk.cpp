/*******************************
���α׷���: �ǽ�#9-1
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 16
���α׷� ����: �����ڿ� �Ҹ���, �л�,���� Ŭ���� �����ڿ� �Ҹ��� ����.
������Ʈ ����: 
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

/*****************************
*		����	�Լ�		 *
*****************************/
int main() {
	Subject sub1("��ǻ��", 3, "C"); //���ڻ����� ȣ��
	Subject sub2(sub1); //��������� ȣ��
	cout << "\nsub1 ����\n";
	sub1.PrintData();
	cout << "\nsub2 ����\n";
	sub2.PrintData();
	sub2.Modify();	//sub2 ��������

	Student st2("ȫ�浿", 2013909845, 1, &sub1); //���ڻ�����
	Student st3("����", 2019038054, 1, &sub2); //���ڻ�����

	Student st1 = st2; //��������
	cout << "\nst1 ����\n";
	st1.PrintData();

	cout << "\nst2 ����\n";
	st2.PrintData();
	st2.Modify();		//st2�� �л������� ���������� �����Ѵ�.
	cout << "\n������ st2 ����\n";
	st2.PrintData();	//������ st2 ���
	cout << "\n";
	st1.PrintData();	//��������� st2�� �ٸ� ���� sub1�� ���

	cout << "\nst3 ����\n";
	st3.PrintData(); //������ sub2�� ������ �����ִ�.
	return 0;
}