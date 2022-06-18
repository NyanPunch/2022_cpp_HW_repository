/*******************************
프로그램명: 실습#11
작 성 자: 2019038054 김경민
작 성 일: 2022 05 27
프로그램 설명: 상속클래스
업데이트 내용: Interface.h, Student.cpp->Modify()
********************************/
#include "Student.h"
#include "Subject.h"
#include "Interface.h"
using namespace std;

/*****************************
*		메인	함수		 *
*****************************/
int main() {
	Subject sub("컴퓨터", 3, "C");
	cout << "-------------------------\n";
	cout << "m_data : " << sub.GetData();							//IOInterface 클래스에 GetData출력 Data 입력을 받지 않아 쓰레기값 출력
	cout << "\n교과목 이름 : " << sub.Subject::GetName();			//Subject클래스에 GetName함수 출력 : "컴퓨터"
	cout << "\n부모클래스의 이름 : " << sub.IOInterface::GetName(); //IOInterface클래스 GetName함수 출력 : "컴퓨터"
	cout << "\n-------------------------\n";

	Student std("김경민", 2019038054, 1, &sub);
	cout << "-------------------------\n";
	cout << "m_data : " << std.GetData();							//IOInterface 클래스에 GetData출력 Data 입력을 받지 않아 쓰레기값 출력
	cout << "\n학생 이름 : " << std.Student::GetName();				//Student클래스에 GetName함수 출력 : "김경민"
	cout << "\n부모클래스의 이름 : " << std.IOInterface::GetName(); //IOInterface클래스 GetName함수 출력 : "김경민"
	cout << "\n-------------------------\n";
}

/* 11-4 메인함수
	Subject sub("컴퓨터", 3, "C");
	Student std("김경민", 2019038054, 1, &sub);

	std.PrintData();
	std.Modify(); //멤버변수 값 수정
	std.PrintData();
*/