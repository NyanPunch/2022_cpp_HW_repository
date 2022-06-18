/*******************************
���α׷���: �Լ� �����ε� ����
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 09
���α׷� ����: ����� ó�� ����� ���ϴ� �Լ��� �����ε����� �����Ѵ�.
********************************/
#include <iostream>
#include <cstring>
using namespace std;

/* ���� �ּҰ� Ȯ�� */
int GetMin(int x, int y) {	
	return (x < y) ? x : y;
}
/* �Ǽ� �ּҰ� Ȯ�� */
double GetMin(double x, double y) {
	return (x < y) ? x : y;
}
/* ���ڿ� �ּҰ� Ȯ�� */
int GetMin(char* x, char* y) {
	if (strcmp(x, y) > 0)		//x�� Ŭ��
		return 1;
	else if (strcmp(x, y) < 0)	//y�� Ŭ��
		return -1;
}
/* ������ �迭 �ּҰ� ���� Ȯ�� */
int GetMin(int arr[],int size) {
	int min_a = arr[0];
	for (int i = 1; i < size; i++) {
		if (min_a > arr[i]) min_a = arr[i];
	}
	return min_a;
}

int main() {

	int i1, i2, min_i;
	cout << "�ΰ��� ������ �Է��ϼ��� : ";
	cin >> i1 >> i2;
	min_i = GetMin(i1, i2);
	cout << "�ּҰ��� " << min_i << "�Դϴ�.\n";
	
	double d1, d2, min_d;
	cout << "�ΰ��� �Ǽ��� �Է��ϼ��� : ";
	cin >> d1 >> d2;
	min_d = GetMin(d1, d2);
	cout << "�ּҰ��� " << min_d << "�Դϴ�.\n";

	char c1[10], c2[10], min_c[10];
	cout << "�ΰ��� ���ڿ��� �Է��ϼ���(�ִ�10��) : ";
	cin >> c1 >> c2;
	if (GetMin(c1, c2) == 1) //c1�� ũ�Ƿ� c2 ���
		cout << "�ּҰ��� " << c2 << "�Դϴ�.\n";
	else if (GetMin(c1, c2) == -1) //c2�� ũ�Ƿ� c1 ���
		cout << "�ּҰ��� " << c1 << "�Դϴ�.\n";

	int arr[10], min_arr;
	cout << "�迭�� ���� 10�� �Է� : ";
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	min_arr = GetMin(arr, 10);
	cout << "�ּҰ��� " << min_arr << "�Դϴ�.\n";

	return 0;
}