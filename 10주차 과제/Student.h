#ifndef Student_h
#define Student_h

#include <string>
#include <iostream>
#include "Subject.h"
using namespace std;

class Student {
protected:
	string m_name;	//학생이름
	int m_hakbun;	//학번
	int m_subnum;	//과목수
	Subject* m_sub;	//과목정보
	float m_aveGPA;	//평균평점
public:
	void Initialize();	//변수값 초기화
	void Initialize(string, int, int, Subject*); //변수값 초기화
	void Remove();		//동적할당 메모리 해제
	void InputValue(int&);
	void InputValue(string&);
	void InputData();
	void PrintData();
	void CalcAveGPA();
	/* 접근자 함수 추가 */
	string GetName();	//학생이름 리턴
	int GetHakbun();	//학번 리턴
	int GetSubNum();	//과목수 리턴
	float GetAveGPA();	//평균평점 리턴

	friend void ShowData(const Student&); //friend 함수 생성
};
#endif // !Student_h
