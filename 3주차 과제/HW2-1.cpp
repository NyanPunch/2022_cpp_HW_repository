/*******************************
���α׷���: ������ �⺻ ���丮��
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 18
���α׷� ����: �������� �⺻ ������ ���� ����
********************************/
#include <iostream>
using namespace std;

int main() {
	int arr[6] = { 1,2,3,4,5,6 };
	int* chr_ptr;

	chr_ptr = arr;

	chr_ptr++;	//�����Ͱ� arr+1�� �ּҸ� �Ҵ� ��

	cout << "chr_ptr++ �ϰ� �� �� ��¹�\n";

	cout << "chr_ptr = " << chr_ptr << " arr+1 = " << arr + 1 << endl;	//arr+1 �޸� �ּҰ� ���	
	cout << "*chr_ptr =" << *chr_ptr << " *(arr+1) = " << *(arr + 1) << endl;	//arr+1 �������� 2�� ���	
	cout << "arr = " << arr << endl;		//arr �ּҰ� ���
	cout << "arr + 4 = " << arr + 4 << endl;	//5��° �ּҰ� ���	
	cout << "&arr[3] = " << &arr[3] << endl;	//4��° �ּҰ� ���
	cout << "arr[4] = " << arr[4] << endl;		//5��° ������ ���			

	cout <<"*(chr_ptr+2) = " << *(chr_ptr + 2) << endl;	//arr[3] �� ���

	return 0;
}