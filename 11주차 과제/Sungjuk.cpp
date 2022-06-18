/*******************************
프로그램명: 실습#9-1
작 성 자: 2019038054 김경민
작 성 일: 2022 05 16
프로그램 설명: 생성자와 소멸자, 학생,과목 클래스 생성자와 소멸자 생성.
업데이트 내용: 
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

/*****************************
*		메인	함수		 *
*****************************/
int main() {
	Subject sub1("컴퓨터", 3, "C"); //인자생성자 호출
	Subject sub2(sub1); //복사생성자 호출
	cout << "\nsub1 정보\n";
	sub1.PrintData();
	cout << "\nsub2 정보\n";
	sub2.PrintData();
	sub2.Modify();	//sub2 정보수정

	Student st2("홍길동", 2013909845, 1, &sub1); //인자생성자
	Student st3("김경민", 2019038054, 1, &sub2); //인자생성자

	Student st1 = st2; //깊은복사
	cout << "\nst1 정보\n";
	st1.PrintData();

	cout << "\nst2 정보\n";
	st2.PrintData();
	st2.Modify();		//st2의 학생정보나 과목정보를 수정한다.
	cout << "\n수정된 st2 정보\n";
	st2.PrintData();	//수정된 st2 출력
	cout << "\n";
	st1.PrintData();	//깊은복사로 st2와 다른 기존 sub1값 출력

	cout << "\nst3 정보\n";
	st3.PrintData(); //수정된 sub2의 정보를 갖고있다.
	return 0;
}