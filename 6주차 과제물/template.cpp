/*******************************
프로그램명: 함수 템플릿 이해
작 성 자: 2019038054 김경민
작 성 일: 2022 04 09
프로그램 설명: 동일한 알고리즘을 구현하는 함수를 함수 템플릿으로 구현한다.
********************************/
#include <iostream>
using namespace std;

template <class T>	
void sort(T *arr,T size) {	//버블 정렬 템플릿
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
	cout << "정렬 결과 : ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

}

void getinteger() { //정수 배열 입력
	int arr[5], size = 5;
	cout << "5개의 정수를 입력하세요 : ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	sort(arr, size);
}

void getdouble() {	//실수 배열 입력
	double arr[5], size = 5;
	cout << "5개의 실수를 입력하세요 : ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	sort(arr, size);
}

int main() {

	int menu = 0;
	while (menu != 3) {
		cout << "\n1. 정수 정렬\n" << "2. 실수 정렬\n" << "3. 종료\n";
		cout << "메뉴 선택 : ";
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
			cout << "지원하지 않는 형식입니다.";
			break;
		}	
	}
	return 0;
}