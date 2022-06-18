/*******************************
프로그램명: 실습#12
작 성 자: 2019038054 김경민
작 성 일: 2022 06 01
프로그램 설명: 가상 함수 만들기, 추상 클래스 만들기, 성적관리 클래스 추가
업데이트 내용: Interface.h GradeManager.h/.cpp
********************************/
#include "Student.h"
#include "Subject.h"
#include "Interface.h"
#include "GradeManager.h"
using namespace std;

/*****************************
*		메인	함수		 *
*****************************/
int main() {
	int stdnum;
	cout << "입력할 학생 수를 입력 : ";
	cin >> stdnum; cin.ignore();
	GradeManager GradeMgr(stdnum);
	GradeMgr.Execute();
}

/*
	Student std;
	std.InputData();

	IOInterface* IO[2] = { new Subject("사진학",3,"A+"), &std };

	for (int i = 0; i < 2; i++) {
		cout << "\n* " << i + 1 << "번째 데이터 : \n";
		IO[i]->PrintData(); //파생클래스 멤버함수 호출시키기
	}
*/