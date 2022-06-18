/*******************************
프로그램명: 실습#10
작 성 자: 2019038054 김경민
작 성 일: 2022 05 20 ~ 2022 05 21
프로그램 설명: 과목탐색, 정적, const, 객체생성
업데이트 내용: SubSearch, 정적멤버, const 멤버 추가
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

void Data(const Student& s) {
	cout << s.GetName() << "이 수강한 과목은 총 " << s.GetSubNum() << "개로 ";
	cout << "수강한 과목의 평균평점은 " << s.GetAveGPA() << "입니다.\n";
}
/*****************************
*		메인	함수		 *
*****************************/
int main() {
	/* 과목 생성자 생성 */
	Subject sub1[2] = { Subject("컴퓨터",3,"C"),Subject("현대무용",2,"A") }; //배열객체
	Subject* sub2[2] = { new Subject(),new Subject("수학",3,"C") };	//동적객체
	/* 학생 생성자 생성 */
	Student st1; //디폴트
	Student st2("홍길동", 2013909845, 2, sub1); //인자생성자 sub1 크기만큼 과목생성자 호출
	Student* st3 = new Student[2]; //동적객체배열
	cout << "\nsub2[0] 입력" << endl;
	sub2[0]->InputData();
	cout << "\nst1 입력" << endl;
	st1.InputData();
	cout << "\nst3 입력" << endl;
	for (int i = 0; i < 2; i++) (st3 + i)->InputData();

	cout << "\nsub1 정보 출력\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++)sub1[i].PrintData();
	cout << "\nsub2 정보 출력\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++)sub2[i]->PrintData(); //포인터배열 "->" 주의

	cout << "\n" << "st1 정보 출력" << "\n";
	st1.PrintData();
	cout << "\n" << "st2 정보 출력" << "\n";
	st2.PrintData();
	cout << "\n" << "st3 정보 출력" << "\n";
	for (int i = 0; i < 2; i++) (st3 + i)->PrintData();
}
