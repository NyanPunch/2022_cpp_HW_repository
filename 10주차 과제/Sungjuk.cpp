/*******************************
프로그램명: 실습 8-4 파일 분할
작 성 자: 2019038054 김경민
작 성 일: 2022 05 11
프로그램 설명: 각 클래스 별로 헤더파일와 소스파일 분할 컴파일
업데이트 내용: Student.cpp Subject.cpp Sungjuk.cpp Student.h Subject.h
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

/*****************************
*		메인	함수		 *
*****************************/
int main() {
	Subject sub[2];
	sub[0].Initialize("컴퓨터", 3, "C");
	sub[1].Initialize("현대무용", 2, "A");

	Student st1, st2;
	st1.Initialize();
	/* st2 과목수 sub배열에 저장된 과목 2개 저장 */
	st2.Initialize("홍길동", 2013909845, 2, sub);

	/* st1 정보 입력 및 출력 */
	st1.InputData();
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();

	/* st2 정보 출력 */
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();

	/* 접근자 함수 이용 */
	cout << "\n< 접근자 함수를 이용한 출력 >\n";
	cout << "\n학생명 : " << st1.GetName();
	cout << "\n학번 : " << st1.GetHakbun();
	cout << "\n과목 수 : " << st1.GetSubNum();
	cout << "\n평균평점 : " << st1.GetAveGPA();

	/*동적 할당 해제*/
	st1.Remove();

	return 0;
}