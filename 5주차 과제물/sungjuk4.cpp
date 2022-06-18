/*******************************
프로그램명: 성적처리프로그램 4
작 성 자: 2019038054 김경민
작 성 일: 2022 04 09
프로그램 설명: 학생 수 와 과목 수를 사용자가 정할 수 있게 동적할당
수정 내용 : InputData, InputValue 추가 
********************************/
#include <iostream>
#include <string.h>
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
	Subject *Sub;			//과목
	int SubNum;				//NEW 과목 수
	float aveGPA;			//교과목 평균 평점
};

void InputData(student* pSt,int StudentNum);	//성적입력함수   /* CHANGE */
void PrintMenu();						//메뉴출력 
void CalcGPA(Subject& Sub);				//교과목 평점계산 
float CalcAveGPA(Subject* Sub, int SubNum);			//개인학생 평균 평점 계산 /* CHANGE */
void PrintAllData(const student* pSt, int StudentNum);	//전체학생 신상/성적 출력 
void PrintOneData(const student& rSt);					//개인학생 신상/성적 출력 
student* StdSearch(student* pSt, int StudentNum);		//학생 이름 검색 후 해당 학생 정보가 있는곳의 주소 리턴

void InputValue(char* str) {
	cin >> str;
}
void InputValue(int& i) {
	cin >> i;
}

int main() {
	cout.precision(2);
	cout << fixed;

	PrintMenu();

	return 0;
}

void PrintMenu()		// 메뉴 출력
{
	struct student* Std = NULL;	//학생 구조체 동적 메모리 할당
	int flag = 0, menu = 0, StdNum = 2;

	cout << "\n정보를 등록할 학생 수를 입력해주세요. : ";
	cin >> StdNum;
	Std = new student[StdNum]; // 동적 메모리 사용
	
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
			InputData(Std, StdNum);
			break;
		case 2:
			//학생 전체 정보 출력
			PrintAllData(Std, StdNum);
			break;
		case 3:
			//학생 이름 검색 후 출력
			student * SearchStd;
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4:
			//프로그램 종료
			cout << "프로그램을 종료합니다\n";
			delete[] Std;	//학생 할당 해제
			Std = NULL;	//안전하게 NULL 초기화
		}
	}
}

void CalcGPA(Subject& Sub) {	//교과목 성적 처리 함수
	if (strcmp(Sub.grade, "A+") == 0)
		Sub.GPA = (float)Sub.hakjum * 4.5;
	else if ((strcmp(Sub.grade, "A0") == 0) || (strcmp(Sub.grade, "A") == 0))
		Sub.GPA = (float)Sub.hakjum * 4.0;
	else if (strcmp(Sub.grade, "B+") == 0)
		Sub.GPA = (float)Sub.hakjum * 3.5;
	else if ((strcmp(Sub.grade, "B0") == 0) || (strcmp(Sub.grade, "B") == 0))
		Sub.GPA = (float)Sub.hakjum * 3.0;
	else if (strcmp(Sub.grade, "C+") == 0)
		Sub.GPA = (float)Sub.hakjum * 2.5;
	else if ((strcmp(Sub.grade, "C0") == 0) || (strcmp(Sub.grade, "C") == 0))
		Sub.GPA = (float)Sub.hakjum * 2.0;
}

float CalcAveGPA(Subject* Sub,int SubNum) {	//평균 평점 처리 함수
	float sumGPA = 0;
	for (int i = 0; i < SubNum; i++)
		sumGPA += Sub[i].GPA;	
	return (sumGPA / SubNum);
	//aveGPA = sumGPA / MAX_Sub
}

void InputData(student *pSt,int StudentNum) {			//정보 입력 함수 case 1:
	int i, j;					// i = 학생 j = 학생의 세 과목
	float AveGPA;
	int SubNum;
	for (i = 0; i < StudentNum; i++) {
		cout << endl << "* " << i + 1 << " 번 째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : "; InputValue(pSt[i].stdname);
		cout << "학번 : "; InputValue(pSt[i].hakbun);
		cout << endl;

		cout << "수강한 과목 수를 입력 : ";
		cin >> SubNum; //과목 수
		//n번째 학생의 과목수 만큼 동적 할당
		pSt[i].Sub = new Subject[SubNum];
		pSt[i].SubNum = SubNum;

		//n번째 학생의 입력받은 과목 수 만큼 동적 할당.
		cout << "* 수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (j = 0; j < SubNum; j++) {
			cout << "교과목명 : "; InputValue(pSt[i].Sub[j].subname);
			cout << "과목학점 : "; InputValue(pSt[i].Sub[j].hakjum);
			cout << "과목등급(A+ ~ F) : "; InputValue(pSt[i].Sub[j].grade);
			cout << endl;
			CalcGPA(pSt[i].Sub[j]);  //과목 평점 처리
		}
		AveGPA = CalcAveGPA(pSt[i].Sub, SubNum);	//평균 평점 처리
		pSt[i].aveGPA = AveGPA;			//i번째 학생의 평균 평점 기입
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

	for (int j = 0; j < rSt.SubNum; j++) {				//과목 반복 출력문
		cout.width(10); cout << rSt.Sub[j].subname;
		cout.width(10); cout << rSt.Sub[j].hakjum;
		cout.width(10); cout << rSt.Sub[j].grade;
		cout.width(10); cout << rSt.Sub[j].GPA << endl;
	}
	cout << "=========================================\n";
	cout.width(35);
	cout << "평균평점  " << rSt.aveGPA << endl;
}

student* StdSearch(student* pSt, int StudentNum) {	//이름을 검색해서 주소 리턴
	char SearchName[30];
	cout << "찾을 학생의 이름을 입력해주세요.\n 이름 : ";
	InputValue(SearchName);
	int len = strlen(SearchName);	//이름길이만큼 len에 숫자 저장
	for (int i = 0; i < StudentNum; i++) {
		for (int j = 0; j < len; j++) {
			if (strlen(pSt[i].stdname) == len && (pSt[i].stdname[j] == SearchName[j]))
				return &pSt[i]; //찾는 이름과 검색한 이름의 글자수가 같고, 저장된 이름이 같을 시 해당 이름 리턴
		}
	}
	return NULL;
}
