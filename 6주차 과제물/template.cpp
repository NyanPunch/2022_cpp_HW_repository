/*******************************
���α׷���: �Լ� ���ø� ����
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 09
���α׷� ����: ������ �˰����� �����ϴ� �Լ��� �Լ� ���ø����� �����Ѵ�.
********************************/
#include <iostream>
using namespace std;

template <class T>	
void sort(T *arr,T size) {	//���� ���� ���ø�
	T temp;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "���� ��� : ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

}

void getinteger() { //���� �迭 �Է�
	int arr[5], size = 5;
	cout << "5���� ������ �Է��ϼ��� : ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	sort(arr, size);
}

void getdouble() {	//�Ǽ� �迭 �Է�
	double arr[5], size = 5;
	cout << "5���� �Ǽ��� �Է��ϼ��� : ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	sort(arr, size);
}

int main() {

	int menu = 0;
	while (menu != 3) {
		cout << "\n1. ���� ����\n" << "2. �Ǽ� ����\n" << "3. ����\n";
		cout << "�޴� ���� : ";
		cin >> menu;

		switch (menu) {
		case 1:
			getinteger();
			break;
		case 2:
			getdouble();
			break;
		case 3:
			break;
		default:
			cout << "�������� �ʴ� �����Դϴ�.";
			break;
		}	
	}
	return 0;
}