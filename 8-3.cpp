/*******************************
프로그램명: 실습 8-3 학생 클래스 추가
작 성 자: 2019038054 김경민
작 성 일: 2022 05 10
프로그램 설명: Student Class #1
업데이트 내용: class Student{};
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
	string GetName() { //과목명 리턴
		return m_name;
	}	
	int GetHakjum() { //학점 리턴
		return m_hakjum;
	}
	string GetGrade() { //등급 리턴
		return m_grade;
	}
	float GetGPA() { //평점 리턴
		return m_GPA;
	}
};

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
	string GetName() {	//학생이름 리턴
		return m_name;
	}	
	int GetHakbun() {	//학번 리턴
		return m_hakbun;
	}	
	int GetSubNum() {	//과목수 리턴
		return m_subnum;
	}
	float GetAveGPA() { //평균평점 리턴
		return m_aveGPA;
	}
};
/*****************************
*		메인	함수		 *
*****************************/
void main() {
	Subject sub[2];
	sub[0].Initialize("컴퓨터", 3, "C");
	sub[1].Initialize("현대무용", 2, "A");

	Student st1, st2;
	st1.Initialize();
	/* st2 과목수 sub배열에 저장된 과목 2개 저장 */
	st2.Initialize("홍길동", 2013909845, 2, sub);

	/* st1 정보 입력 및 출력 */
	st1.InputData();
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();

	/* st2 정보 출력 */
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();

	/* 접근자 함수 이용 */
	cout << "\n< 접근자 함수를 이용한 출력 >\n";
	cout << "\n학생명 : " << st1.GetName();
	cout << "\n학번 : " << st1.GetHakbun();
	cout << "\n과목 수 : " << st1.GetSubNum();
	cout << "\n평균평점 : " << st1.GetAveGPA();

	/*동적 할당 해제*/
	st1.Remove();
}
/* 과목 멤버 함수 */
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
	m_GPA = 0.0f;
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
	cout << "\n--------------------------------------------\n";
	cout << " 교과목명\t학점수\t등급\t평점\n";
	cout << "--------------------------------------------\n";
}

void Subject::PrintData()
{
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

/*************************************
*		학생	멤버	함수		 *
**************************************/
void Student::Initialize()
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
}

void Student::Initialize(string str, int hakbun, int subnum, Subject* sub)
{
	m_name = str;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = sub;
	m_aveGPA = 0.0f;
	CalcAveGPA(); //평균 평점 계산하여 삽입
}

void Student::Remove()
{
	delete[] m_sub;
}

inline void Student::InputValue(int& i)
{
	cin >> i; cin.ignore();
}

inline void Student::InputValue(string& str)
{
	getline(cin, str);
}

void Student::InputData() //내부적으로 Subject Class의 InputData() 사용
{
	cout << "이름 : "; InputValue(m_name);
	cout << "학번 : "; InputValue(m_hakbun);
	cout << "과목 수 : "; InputValue(m_subnum);
	m_sub = new Subject[m_subnum];	//과목수 만큼 동적할당
	for (int i = 0; i < m_subnum; i++) {//과목수 만큼 과목정보 입력
		m_sub[i].InputData();	//과목클래스 사용
	}
	CalcAveGPA();	//평균평점 계산 함수 내부에서 m_aveGPA 입력
}

void Student::PrintData()
{
	cout << "============================================\n";
	cout << " 이름 : " << m_name << "\t 학번 : " << m_hakbun;
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "\t\t\t평균평점\t" << m_aveGPA;
}

void Student::CalcAveGPA() //m_GPA는 접근자 함수 사용해야 읽을 수 있음
{
	for (int i = 0; i < m_subnum; i++)
		m_aveGPA += m_sub[i].GetGPA();
	m_aveGPA = m_aveGPA / m_subnum;	/* 총 학점 / 과목수 */
}
