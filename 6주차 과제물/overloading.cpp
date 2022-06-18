/*******************************
프로그램명: 함수 오버로딩 이해
작 성 자: 2019038054 김경민
작 성 일: 2022 04 09
프로그램 설명: 비슷한 처리 결과를 구하는 함수를 오버로딩으로 구현한다.
********************************/
#include <iostream>
#include <cstring>
using namespace std;

/* 정수 최소값 확인 */
int GetMin(int x, int y) {	
	return (x < y) ? x : y;
}
/* 실수 최소값 확인 */
double GetMin(double x, double y) {
	return (x < y) ? x : y;
}
/* 문자열 최소값 확인 */
int GetMin(char* x, char* y) {
	if (strcmp(x, y) > 0)		//x가 클때
		return 1;
	else if (strcmp(x, y) < 0)	//y가 클때
		return -1;
}
/* 정수형 배열 최소값 원소 확인 */
int GetMin(int arr[],int size) {
	int min_a = arr[0];
	for (int i = 1; i < size; i++) {
		if (min_a > arr[i]) min_a = arr[i];
	}
	return min_a;
}

int main() {

	int i1, i2, min_i;
	cout << "두개의 정수를 입력하세요 : ";
	cin >> i1 >> i2;
	min_i = GetMin(i1, i2);
	cout << "최소값은 " << min_i << "입니다.\n";
	
	double d1, d2, min_d;
	cout << "두개의 실수를 입력하세요 : ";
	cin >> d1 >> d2;
	min_d = GetMin(d1, d2);
	cout << "최소값은 " << min_d << "입니다.\n";

	char c1[10], c2[10], min_c[10];
	cout << "두개의 문자열을 입력하세요(최대10자) : ";
	cin >> c1 >> c2;
	if (GetMin(c1, c2) == 1) //c1이 크므로 c2 출력
		cout << "최소값은 " << c2 << "입니다.\n";
	else if (GetMin(c1, c2) == -1) //c2가 크므로 c1 출력
		cout << "최소값은 " << c1 << "입니다.\n";

	int arr[10], min_arr;
	cout << "배열의 원소 10개 입력 : ";
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	min_arr = GetMin(arr, 10);
	cout << "최소값은 " << min_arr << "입니다.\n";

	return 0;
}