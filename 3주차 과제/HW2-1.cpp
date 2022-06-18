/*******************************
프로그램명: 포인터 기본 개념리뷰
작 성 자: 2019038054 김경민
작 성 일: 2022 03 18
프로그램 설명: 포인터의 기본 원리에 대한 이해
********************************/
#include <iostream>
using namespace std;

int main() {
	int arr[6] = { 1,2,3,4,5,6 };
	int* chr_ptr;

	chr_ptr = arr;

	chr_ptr++;	//포인터가 arr+1의 주소를 할당 중

	cout << "chr_ptr++ 하고 난 뒤 출력물\n";

	cout << "chr_ptr = " << chr_ptr << " arr+1 = " << arr + 1 << endl;	//arr+1 메모리 주소값 출력	
	cout << "*chr_ptr =" << *chr_ptr << " *(arr+1) = " << *(arr + 1) << endl;	//arr+1 참조값인 2를 출력	
	cout << "arr = " << arr << endl;		//arr 주소값 출력
	cout << "arr + 4 = " << arr + 4 << endl;	//5번째 주소값 출력	
	cout << "&arr[3] = " << &arr[3] << endl;	//4번째 주소값 출력
	cout << "arr[4] = " << arr[4] << endl;		//5번째 참조값 출력			

	cout <<"*(chr_ptr+2) = " << *(chr_ptr + 2) << endl;	//arr[3] 값 출력

	return 0;
}