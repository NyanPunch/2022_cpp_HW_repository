#include "Subject.h"
using namespace std;
/* 과목 멤버 함수 */
Subject::Subject()
{
	cout << "\n과목 생성자 호출\n";
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0f;
}

Subject::Subject(string name, int hakjum, string grade)
{
	cout << "\n과목 인자생성자 호출\n";
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	m_GPA = 0.0f;
	CalcGPA(); //해당과목 평점 계산
}

Subject::Subject(const Subject& sub)
{
	cout << "\n과목 복사생성자 호출\n";
	this->m_name = sub.m_name;
	this->m_hakjum = sub.m_hakjum;
	this->m_grade = sub.m_grade;
	this->m_GPA = sub.m_GPA;
	CalcGPA();
}

Subject::~Subject()
{
	cout << "\n과목 소멸자 호출\n";
}

inline void Subject::InputValue(int& i)
{
	cin >> i; cin.ignore(); //버퍼 정리
}

inline void Subject::InputValue(string& str)
{
	getline(cin, str);
}

void Subject::InputData()
{
	cout << "\n과목명 : "; InputValue(m_name);
	cout << "학점 : "; InputValue(m_hakjum);
	cout << "등급 : "; InputValue(m_grade);
	CalcGPA();
}

void Subject::PrintTitle()
{
	cout << "\n--------------------------------------------\n";
	cout << " 교과목명\t학점수\t등급\t평점\n";
}

void Subject::PrintData()
{
	cout << "--------------------------------------------\n";
	cout << " " << m_name << " \t" << m_hakjum << "\t" << m_grade << "\t" << m_GPA << endl;
	cout << "--------------------------------------------\n";
}
/* 평점 계산 */
void Subject::CalcGPA()
{
	if (m_grade == "A+")
		m_GPA = m_hakjum * 4.5f;
	else if (m_grade == "A" || m_grade == "A0")
		m_GPA = m_hakjum * 4.0f;
	else if (m_grade == "B+")
		m_GPA = m_hakjum * 3.5f;
	else if (m_grade == "B" || m_grade == "B0")
		m_GPA = m_hakjum * 3.0f;
	else if (m_grade == "C+")
		m_GPA = m_hakjum * 2.5f;
	else if (m_grade == "C" || m_grade == "C0")
		m_GPA = m_hakjum * 2.0f;
	else if (m_grade == "D+")
		m_GPA = m_hakjum * 1.5f;
	else if (m_grade == "D" || m_grade == "D0")
		m_GPA = m_hakjum * 1.0f;
	else if (m_grade == "F")
		m_GPA = m_hakjum * 0.0f;
}

string Subject::GetName()	//과목명 리턴
{
	return m_name;
}

int Subject::GetHakjum()	//학점 리턴
{
	return m_hakjum;
}

string Subject::GetGrade()	//등급 리턴
{
	return m_grade;
}

float Subject::GetGPA()		//평점 리턴
{
	return m_GPA;
}

/* 과목정보 수정 */
void Subject::Modify() {
	cout << "\n < " << m_name << ", " << m_hakjum << ", " << m_grade << " >의 정보를 수정하세요.\n";
	cout << "교과목명 : "; InputValue(this->m_name);
	cout << "과목학점 : "; InputValue(this->m_hakjum);
	cout << "과목등급 : "; InputValue(this->m_grade);
	CalcGPA();
}