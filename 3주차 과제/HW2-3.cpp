/*******************************
프로그램명: const 포인터
작 성 자: 김경민
작 성 일: 2022 03 18
프로그램 설명: const와 포인터를 같이 쓸 때 주의점에 대해 알아본다
********************************/
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	
	//A problem

	const int* pint1;
	pint1 = &i1; //i1에 const를 부여, 값을 바꿀 수 없음
	*pint1 = 30; //i1의 값을 바꿀수 없어 에러

	//B problem

	int* const pint2 = &i1;	//const로 i1의 주소를 고정
	pint2 = &i2;	//다른 주소로 바꿀 수 없음
	*pint2 = 50;	//고정된 주소의 참조값은 수정 가능

	//C problem

	const int* const p = &i2; //i2의 주소와 값을 모두 고정
	p = &i1;	//주소를 바꿀 수 없음
	*p = 40;	//고정된 주소의 참조값을 바꿀 수 없음

	return 0;
}