#include "Student.h"
#include <string>
using namespace std;
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

string Student::GetName() {	//학생이름 리턴
	return m_name;
}

int Student::GetHakbun() {	//학번 리턴
	return m_hakbun;
}

int Student::GetSubNum() {	//과목수 리턴
	return m_subnum;
}

float Student::GetAveGPA() { //평균평점 리턴
	return m_aveGPA;
}