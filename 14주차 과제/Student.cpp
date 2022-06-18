#include "Student.h"
using namespace std;
/*************************************
*		학생	멤버	함수		 *
**************************************/
Student::Student()
{
	cout << "\n학생 생성자 호출\n";
	this->m_name = "";
	this->m_hakbun = 0;
	this->m_subnum = 0;
	this->m_sub = NULL;
	this->m_aveGPA = 0.0f;
}
/* 깊은 복사가 가능하게 생성 */
Student::Student(string m_name, int m_hakbun, int m_subnum, Subject* m_sub)
{
	cout << "\n학생 인자생성자 호출\n";
	this->m_name = m_name;
	this->m_hakbun = m_hakbun;
	this->m_subnum = m_subnum;
	this->m_sub = new Subject[m_subnum];
	for (int i = 0; i < this->m_subnum; i++)
		this->m_sub[i].SetSub(m_sub[i]);
	this->m_aveGPA = 0.0f;
	CalcAveGPA(); //평균 평점 계산하여 삽입
}
/* 깊은 복사를 하도록 */
Student::Student(const Student& std)
{
	cout << "\n학생 복사생성자 호출\n";
	this->m_name = std.m_name;
	this->m_hakbun = std.m_hakbun;
	this->m_subnum = std.m_subnum;
	this->m_sub = new Subject[std.m_subnum];
	for (int i = 0; i < this->m_subnum; i++)
		this->m_sub[i].SetSub(std.m_sub[i]);
	CalcAveGPA();
}
/* 소멸자 */
Student::~Student()
{
	cout << "\n학생 소멸자 호출\n";
	delete[] m_sub;					
}

inline void Student::InputValue(int& i) const
{
	cin >> i; cin.ignore();
}

inline void Student::InputValue(string& str) const
{
	getline(cin, str);
}

void Student::InputData() //순수 가상 함수 재정의
{	
	cout << "\n";
	cout << "이름 : "; InputValue(m_name);
	cout << "학번 : "; InputValue(m_hakbun);
	cout << "과목 수 : "; InputValue(m_subnum);
	m_sub = new Subject[m_subnum];	//과목수 만큼 동적할당
	for (int i = 0; i < m_subnum; i++) {//과목수 만큼 과목정보 입력
		m_sub[i].InputData();	//과목클래스 사용
	}
	CalcAveGPA();	//평균평점 계산 함수 내부에서 m_aveGPA 입력
}

void Student::PrintData() const
{
	cout << "\n============================================\n";
	cout << " 이름 : " << m_name << "\t 학번 : " << m_hakbun;
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "\t\t\t평균평점\t" << m_aveGPA << endl;
}

void Student::CalcAveGPA() //m_GPA는 접근자 함수 사용해야 읽을 수 있음
{
	if (m_aveGPA > 0.0) m_aveGPA = 0.0;	//전처리 초기화
	for (int i = 0; i < m_subnum; i++)
		m_aveGPA += m_sub[i].GetGPA();
	m_aveGPA = m_aveGPA / m_subnum;	/* 총 학점 / 과목수 */
}

string Student::GetName() const{	//학생이름 리턴
	return m_name;
}

int Student::GetHakbun() const {	//학번 리턴
	return m_hakbun;
}

int Student::GetSubNum() const {	//과목수 리턴
	return m_subnum;
}

float Student::GetAveGPA() const { //평균평점 리턴
	return m_aveGPA;
}

void Student::Modify() { //수정하는 학생은 정해진 상태로 호출됨
	/* 학생정보, 과목정보 문자열 입력받고 해당 부분 수정 */
	string TYPE;
	cout << "\n수정할 정보를 입력하세요<학생정보/과목정보/모두> : ";
	getline(cin, TYPE);
	if (TYPE == "학생정보" || TYPE == "모두") {
		cout << "\n < " << m_name << " " << m_hakbun << " >의 정보를 수정하세요\n";
		cout << "이름 : "; InputValue(this->m_name);
		cout << "학번 : "; InputValue(this->m_hakbun);
	}
	if (TYPE == "과목정보" || TYPE == "모두") {
		string SearchSub; //과목검색
		cout << "\n수정할 과목명을 입력하세요. "; getline(cin, SearchSub);
		Subject* ptr = SubSearch(SearchSub);
		if(ptr)	ptr->Modify(); //과목검색시 NULL이 리턴되지 않으면 정보 수정
		//this->m_sub->Modify();
		CalcAveGPA();
	}
}

Subject* Student::SubSearch(string subname) const { //subname == searchSub
	int i, temp = 0;
	for (i = 0; i < this->m_subnum; i++) { //return == 메모리주소 전달할것
		if (this->m_sub[i].GetName().compare(subname) == 0) {
			temp = 1; break;
		}
	}
	if (temp == 1) return &(this->m_sub[i]);
	cout << "\n찾으시는 교과목이 없습니다!\n";
	return NULL;
}