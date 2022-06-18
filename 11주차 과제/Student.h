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
	/* 생성자 */
	Student();	//변수값 초기화
	Student(string, int, int, Subject*); //변수값 초기화
	Student(const Student& std);

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

	/* friend func */
	//friend void ShowData(const Student&);
	/* #9 */
	void Modify();
	~Student();
};
#endif // !Student_h
