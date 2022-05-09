/*******************************
프로그램명: 실습 8-2 접근자 함수 추가
작 성 자: 2019038054 김경민
작 성 일: 2022 05 09
프로그램 설명: Subject Class Test #2
업데이트 내용: GetName() GetHakjum() GetGrade() GetGPA()
********************************/
#include <iostream>
#include <string>
using namespace std;

class Subject {
protected:
	string m_name;	//과목명
	int m_hakjum;	//학점
	string m_grade;	//등급
	float m_GPA;	//평점
public:
	void Initialize();	//멤버변수 초기화
	void Initialize(string, int, string); //인자값으로 멤버변수 초기화
	void InputValue(int&);
	void InputValue(string&);
	void InputData();	//멤버변수 값 입력 InputValue이용
	void PrintTitle();	//멤버변수에 대한 출력
	void PrintData();	//멤버변수 값 출력
	void CalcGPA();		//평점 계산
	/* 접근자 함수 추가 */
	string GetName();	//과목명 리턴
	int GetHakjum();	//학점 리턴
	string GetGrade();	//등급 리턴
	float GetGPA();		//평점 리턴
};

/* 메인 함수 */
void main() {
	Subject sub1;

	sub1.Initialize("범죄 심리학", 4, "A0");	//직접 변수 입력 초기화

	/* 일반 객체 */
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle();
	sub1.PrintData();
	cout << "\n< 접근자 함수를 이용한 정보 출력 >\n";
	cout << "\n과목 명 : " << sub1.GetName();
	cout << "\n과목 학점 : " << sub1.GetHakjum();
	cout << "\n과목 등급 : " << sub1.GetGrade();
	cout << "\n과목 평점 : " << sub1.GetGPA();
}
/* 객체 초기화 */
void Subject::Initialize()
{
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0f;
}
/* 객체 초기화 */
void Subject::Initialize(string name, int hakjum, string grade)
{
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA(); //해당과목 평점 계산
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
	cout << "--------------------------------------------\n";
	cout << " 교과목명     학점수   등급     평점\n";
	cout << "--------------------------------------------\n";
}

void Subject::PrintData()
{
	cout << " " << m_name << "\t" << m_hakjum << "\t" << m_grade << "\t" << m_GPA << endl;
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
/* 접근자 함수 4개 추가 */
string Subject::GetName()
{
	return m_name;
}

int Subject::GetHakjum()
{
	return m_hakjum;
}

string Subject::GetGrade()
{
	return m_grade;
}

float Subject::GetGPA()
{
	return m_GPA;
}
