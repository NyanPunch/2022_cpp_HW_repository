/*******************************
���α׷���: �ǽ�#10
�� �� ��: 2019038054 ����
�� �� ��: 2022 05 20 ~ 2022 05 21
���α׷� ����: ����Ž��, ����, const, ��ü����
������Ʈ ����: SubSearch, �������, const ��� �߰�
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

void Data(const Student& s) {
	cout << s.GetName() << "�� ������ ������ �� " << s.GetSubNum() << "���� ";
	cout << "������ ������ ��������� " << s.GetAveGPA() << "�Դϴ�.\n";
}
/*****************************
*		����	�Լ�		 *
*****************************/
int main() {
	/* ���� ������ ���� */
	Subject sub1[2] = { Subject("��ǻ��",3,"C"),Subject("���빫��",2,"A") }; //�迭��ü
	Subject* sub2[2] = { new Subject(),new Subject("����",3,"C") };	//������ü
	/* �л� ������ ���� */
	Student st1; //����Ʈ
	Student st2("ȫ�浿", 2013909845, 2, sub1); //���ڻ����� sub1 ũ�⸸ŭ ��������� ȣ��
	Student* st3 = new Student[2]; //������ü�迭
	cout << "\nsub2[0] �Է�" << endl;
	sub2[0]->InputData();
	cout << "\nst1 �Է�" << endl;
	st1.InputData();
	cout << "\nst3 �Է�" << endl;
	for (int i = 0; i < 2; i++) (st3 + i)->InputData();

	cout << "\nsub1 ���� ���\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++)sub1[i].PrintData();
	cout << "\nsub2 ���� ���\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++)sub2[i]->PrintData(); //�����͹迭 "->" ����

	cout << "\n" << "st1 ���� ���" << "\n";
	st1.PrintData();
	cout << "\n" << "st2 ���� ���" << "\n";
	st2.PrintData();
	cout << "\n" << "st3 ���� ���" << "\n";
	for (int i = 0; i < 2; i++) (st3 + i)->PrintData();
}
