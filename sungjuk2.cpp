/*******************************
프로그램명: 성적처리프로그램 2
작 성 자: 2019038054 김경민
작 성 일: 2022 03 25
프로그램 설명: 학생의 정보를 입력받고 요구사항에 맞게 출력
********************************/
#include <iostream>
#include <string.h>
#define MAX_Stu 2			//학생 인원수
#define MAX_Sub 3			//수강 과목수
using namespace std;

struct Subject {			//과목 정보 구조체
	char subname[30];		//과목 명
	int hakjum;				//과목 학점
	char grade[10];			//과목 등급
	float GPA;				//과목 평점
};

struct student {			//학생 정보 구조체
	char stdname[30];		//이름
	int hakbun;				//학번
	Subject Sub[3];			//과목
	float avgGPA;			//교과목 평균 평점
};

void InputData(student s[]);			//성적입력함수

void PrintMenu();						//NEW 메뉴출력 
void CalcGPA(Subject& Sub);				//NEW 교과목 평점계산 
float CalcAveGPA(Subject* Sub);			//NEW 개인학생 평균 평점 계산 
void PrintAllData(const student* pSt, int StudentNum);	//NEW 전체학생 신상/성적 출력 
void PrintOneData(const student& rSt);					//NEW 개인학생 신상/성적 출력 
student* StdSearch(student* pSt, int StudentNum);		//NEW 학생 이름 검색 후 해당 학생 정보가 있는곳의 주소 리턴

int main() {
	cout.precision(2);
	cout << fixed;
	
	PrintMenu();

	return 0;
}

void PrintMenu()		// 메뉴 출력
{
	struct student s[MAX_Stu];
	int flag = 0, menu = 0;
	while (menu != 4) {
		cout << "\n===== 메뉴 =====\n"
			<< "1. 학생 성적 입력\n"
			<< "2. 전체 학생 성적 보기\n"
			<< "3. 학생 이름 검색\n"
			<< "4. 프로그램 종료" << endl;

		cout << "원하는 기능을 입력하세요 : ";
		cin >> menu;
		cout << endl;

		if (menu == 1)		
			flag = 1;	//성적 미 기입 및 성적 출력, 학생 정보 검색을 하려 할때
		else if ((menu == 2) && (flag == 0) || (menu == 3) && (flag == 0)) { 
			cout << "학생의 정보가 입력돼있지 않습니다. 정보를 먼저 입력해주세요.\n" << endl;
			continue;	//강제로 1번 이동 해결 
		}

		switch (menu) {
		case 1:
			//학생 정보 입력
			InputData(s);
			break;
		case 2:
			//학생 전체 정보 출력
			PrintAllData(s, MAX_Stu);
			break;
		case 3:
			//학생 이름 검색 후 출력
			student * SearchStd;
			SearchStd = StdSearch(s, MAX_Stu);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4:
			//프로그램 종료
			cout << "프로그램을 종료합니다\n";
		}
	}
}

void CalcGPA(Subject& Sub) {	//교과목 성적 처리 함수
	cout << "교과목명 : ";
	cin >> Sub.subname;
	cout << "과목학점 : ";
	cin >> Sub.hakjum;
	cout << "과목등급(A+ ~ F) : ";
	cin >> Sub.grade; cout << endl;
	if (strcmp(Sub.grade, "A+") == 0)
		Sub.GPA = Sub.hakjum * 4.5;
	else if ((strcmp(Sub.grade, "A0") == 0) || (strcmp(Sub.grade, "A") == 0))
		Sub.GPA = Sub.hakjum * 4.0;
	else if (strcmp(Sub.grade, "B+") == 0)
		Sub.GPA = Sub.hakjum * 3.5;
	else if ((strcmp(Sub.grade, "B0") == 0) || (strcmp(Sub.grade, "B") == 0))
		Sub.GPA = Sub.hakjum * 3.0;
	else if (strcmp(Sub.grade, "C+") == 0)
		Sub.GPA = Sub.hakjum * 2.5;
	else if ((strcmp(Sub.grade, "C0") == 0) || (strcmp(Sub.grade, "C") == 0))
		Sub.GPA = Sub.hakjum * 2.0;
	
}

float CalcAveGPA(Subject* Sub) {	//평균 평점 처리 함수
	float sumGPA = 0;
	for (int i = 0; i < MAX_Sub; i++)
		sumGPA += Sub[i].GPA;
	return (sumGPA / MAX_Sub);
	//avgGPA = sumGPA / MAX_Sub
}

void InputData(student s[]) {			//정보 입력 함수 case 1:
	int i, j;							// i = 학생 j = 학생의 세 과목
	float AveGPA;
	for (i = 0; i < MAX_Stu; i++) {
		cout << endl << "* " << i + 1 << " 번 째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		cin >> s[i].stdname;
		cout << "학번 : ";
		cin >> s[i].hakbun;
		cout << endl << "* 수강한 과목 세 개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (j = 0; j < MAX_Sub; j++) {
			CalcGPA(s[i].Sub[j]);  //과목 평점 처리
		}
		AveGPA = CalcAveGPA(s[i].Sub);	//평균 평점 처리
		s[i].avgGPA = AveGPA;			//i번째 학생의 평균 평점 기입
	}
}

void PrintAllData(const student* pSt, int StudentNum) {		//전체 학생 성적 출력
	cout.width(10);
	cout << "전체 학생 성적보기\n";
	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void PrintOneData(const student& rSt) {		//학생 개인 정보 출력
		cout << "=========================================\n";
		cout << "이름 : " << rSt.stdname << " 학번 : " << rSt.hakbun << endl;
		cout << "=========================================\n";
		cout.width(10); cout << "과목명";
		cout.width(10); cout << "과목학점";
		cout.width(10); cout << "과목등급";
		cout.width(10); cout << "과목평점" << endl;
		cout << "=========================================\n";

		for (int j = 0; j < MAX_Sub; j++) {				//과목 반복 출력문
			cout.width(10); cout << rSt.Sub[j].subname;
			cout.width(10); cout << rSt.Sub[j].hakjum;
			cout.width(10); cout << rSt.Sub[j].grade;
			cout.width(10); cout << rSt.Sub[j].GPA << endl;
		}
		cout << "=========================================\n";
		cout.width(35);
		cout << "평균평점  " << rSt.avgGPA << endl;
}

student* StdSearch(student* pSt, int StudentNum) {	//이름을 검색해서 주소 리턴
	char SearchName[30];
	cout << "찾을 학생의 이름을 입력해주세요.\n 이름 : ";
	cin >> SearchName;
	int len = strlen(SearchName);	//이름길이만큼 len에 숫자 저장
	for (int i = 0; i < StudentNum; i++) {
		for (int j = 0; j < len; j++) {
			if (strlen(pSt[i].stdname) == len && (pSt[i].stdname[j] == SearchName[j]))	
				return &pSt[i]; //찾는 이름과 검색한 이름의 글자수가 같고, 저장된 이름이 같을 시 해당 이름 리턴
		}
	}
	return NULL;
}