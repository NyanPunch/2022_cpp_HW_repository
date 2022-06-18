/*******************************
프로그램명: 실습 8-5 friend 함수
작 성 자: 2019038054 김경민
작 성 일: 2022 05 11
프로그램 설명: Student Class friend 함수 지정
업데이트 내용: ShowData(), Student.h->friend ShowData 생성
********************************/
#include "Student.h"
#include "Subject.h"
using namespace std;

void ShowData(const Student&);

/*****************************
*		메인	함수		 *
*****************************/
int main() {
	/* 일반 객체 */
	Student st;

	st.Initialize();
	st.InputData();
	st.PrintData();
	ShowData(st);

	st.Remove();
	/* 배열 객체 */
	Subject sub[2];
	sub[0].Initialize("컴퓨터 구조", 3, "A0");
	sub[1].Initialize("객체지향", 3, "A");

	st.Initialize("김경민", 2019038054, 2, sub);
	st.PrintData();
	ShowData(st);

	/* 포인터 객체 */
	Student* pSt;
	pSt = new Student[2];

	for (int i = 0; i < 2; i++) {
		(pSt + i)->Initialize();
		(pSt + i)->InputData();
	}
	for (int i = 0; i < 2; i++) {
		(pSt + i)->PrintData();
		ShowData(pSt[i]);
	}

	return 0;
}

void ShowData(const Student& s) { // 응용프로그램에 있는 전역함수
	cout << "\n\n" << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";
	cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
}