#ifndef Subject_h
#define Subject_h

#include <iostream>
#include <string>
#include "Interface.h"
using namespace std;

class Subject : public IOInterface{
protected:
	string m_name;	//과목명
	int m_hakjum;	//학점
	string m_grade;	//등급
	float m_GPA;	//평점
public:
	/* 생성자 */
	Subject();	//멤버변수 초기화
	Subject(const string, const int, const string); //인자값으로 멤버변수 초기화
	Subject(const Subject& sub);
	void InputValue(int&) const;
	void InputValue(string&) const;
	void InputData();	//멤버변수 값 입력 InputValue이용
	void PrintData() const;	//멤버변수 값 출력
	void CalcGPA();		//평점 계산
	/* 접근자 함수 추가 */
	string GetName()const;	//과목명 리턴
	int GetHakjum()const;	//학점 리턴
	string GetGrade()const; //등급 리턴
	float GetGPA()const;	//평점 리턴
	void SetSub(const Subject&);
	/* #9 */
	void Modify();
	~Subject();
	/* #10 */
	static void PrintTitle();	//멤버변수에 대한 출력
};

#endif // !Subject_h