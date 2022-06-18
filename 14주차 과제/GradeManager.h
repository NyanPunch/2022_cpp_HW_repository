#ifndef GradeManager_h
#define GradeManager_h

#include <iostream>
#include <string>
#include "Student.h"

class GradeManager {
protected:
	Student* m_std;	//전체 학생 정보를 담고 있음
	int m_stdnum;	//관리하고 있는 전체 학생 수
public:
	GradeManager();
	GradeManager(int m_stdnum);
	~GradeManager();
	void Execute();	//학생 성적을 관리하는 함수
protected:
	static void PrintMenu();		//메뉴 출력
	Student* StdSearch(string stdname) const; //원하는 학생 검색
	void PrintAllStdList() const;	//저체 학생 목록 출력
	void Modify();					//원하는 학생의 정보 수정
};
#endif // !GradeManager_h