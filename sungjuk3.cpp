/*******************************
프로그램명: 성적처리프로그램 3
작 성 자: 2019038054 김경민
작 성 일: 2022 04 09
프로그램 설명: 학생의 정보를 입력받고 요구사항에 맞게 출력
업데이트 내용: PrintMenu, InputValue, PrintAllStdList, ModifyStdInfo
********************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#define MAX_Std 2			//학생 인원수
#define MAX_Sub 1			//수강 과목수
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

int menu = 0; 

void InputData(student* pSt, int StudentNum);			//성적입력함수
void CalcGPA(Subject& Sub);				//교과목 평점계산 
float CalcAveGPA(Subject* Sub);			//개인학생 평균 평점 계산 
void PrintAllData(const student* pSt, int StudentNum);	//전체학생 신상/성적 출력 
void PrintOneData(const student& rSt);					//개인학생 신상/성적 출력 
student* StdSearch(student* pSt, int StudentNum);		//학생 이름 검색 후 해당 학생 정보가 있는곳의 주소 리턴
void PrintAllStdList(student* pSt, int StudentNum);
void ModifyStdInfo(student *pSt);
inline void PrintMenu();				//메뉴출력

void InputValue(char* str) {
	cin >> str;
}
void InputValue(int& i) {
	cin >> i;
}

int main() {
	cout.precision(2);
	cout << fixed;
	struct student s[MAX_Std];
	int flag = 0;
	while (menu != 6) {
		PrintMenu();
		if (menu == 1)
			flag = 1;	//성적 미 기입 및 성적 출력, 학생 정보 검색을 하려 할때
		else if ((menu == 2) && (flag == 0) || (menu == 3) && (flag == 0)) {
			cout << "학생의 정보가 입력돼있지 않습니다. 정보를 먼저 입력해주세요.\n" << endl;
			continue;
		}

		switch (menu) {
		case 1:	//학생 정보 입력
			InputData(s, MAX_Std);
			break;
		case 2:	//학생 전체 정보 출력
			PrintAllData(s, MAX_Std);
			break;
		case 3:	//학생 이름 검색 후 출력
			student * SearchStd;
			SearchStd = StdSearch(s, MAX_Std);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4:
			PrintAllStdList(s, MAX_Std);
			break;
		case 5:
			ModifyStdInfo(StdSearch(s, MAX_Std));
			break;
		case 6:
			cout << "프로그램을 종료합니다\n";
			break;
		default:
			cout << "지원하지 않는 형식입니다.\n";
			break;
		}
	}
	return 0;
}
/* 메뉴 */
void PrintMenu()
{
	cout << "\n===== 메뉴 =====\n"
		<< "1. 학생 성적 입력\n"
		<< "2. 전체 학생 성적 보기\n"
		<< "3. 학생 이름 검색\n"
		<< "4. 전체 학생 목록 보기\n"
		<< "5. 학생 정보 수정\n"
		<< "6. 프로그램 종료" << endl;
	cout << "원하는 기능을 입력하세요 : ";
	cin >> menu;
}

/* 교과목 성적 처리 */
void CalcGPA(Subject& Sub) {
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

/* 평균 처리 */
float CalcAveGPA(Subject* Sub) {
	float sumGPA = 0;
	for (int i = 0; i < MAX_Sub; i++)
		sumGPA += Sub[i].GPA;
	return (sumGPA / MAX_Sub);
	//avgGPA = sumGPA / MAX_Sub
}

/* 1. 학생 정보 입력 */
void InputData(student *pSt,int StudentNum) {
	int i, j;		// i = 학생 j = 학생의 세 과목
	float AveGPA;
	for (i = 0; i < MAX_Std; i++, pSt++) {
		cout << endl << "* " << i + 1 << " 번 째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : "; InputValue(pSt->stdname);
		cout << "학번 : "; InputValue(pSt->hakbun);

		cout << endl << "* 수강한 과목 세 개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (j = 0; j < MAX_Sub; j++) {
			cout << "교과목명 : "; InputValue(pSt->Sub[j].subname);
			cout << "과목학점 : "; InputValue(pSt->Sub[j].hakjum);
			cout << "과목등급(A+ ~ F) : "; InputValue(pSt->Sub[j].grade); cout << endl;
			CalcGPA(pSt->Sub[j]);  //과목 평점 처리
		}
		AveGPA = CalcAveGPA(pSt->Sub);	//평균 평점 처리
		pSt->avgGPA = AveGPA;			//i번째 학생의 평균 평점 기입
	}
}
/* 2. 전체 학생 정보 출력 */
void PrintAllData(const student* pSt, int StudentNum) {
	cout.width(10);
	cout << "전체 학생 성적보기\n";
	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}
/* 학생 개인 정보 출력*/
void PrintOneData(const student& rSt) {
	cout << "=========================================\n";
	cout << "이름 : " << rSt.stdname << " 학번 : " << rSt.hakbun << endl;
	cout << "=========================================\n";
	cout << "과목명" << setw(10) << "과목학점" << setw(10) << "과목등급 " << setw(10) << "과목평점" << endl;
	cout << "=========================================\n";

	for (int j = 0; j < MAX_Sub; j++) {	//과목 반복 출력문
		cout << rSt.Sub[j].subname << setw(10) << rSt.Sub[j].hakjum<< setw(10) << rSt.Sub[j].grade<< setw(10) << rSt.Sub[j].GPA << endl;
	}
	cout << "=========================================\n";
	cout.width(35);
	cout << "평균평점  " << rSt.avgGPA << endl;
}

/* 3. 이름을 검색하여 학생의 정보 출력 */
student* StdSearch(student* pSt, int StudentNum) {
	char SearchName[30];
	cout << "찾을 학생의 이름을 입력해주세요.\n 이름 : ";
	InputValue(SearchName);
	int len = strlen(SearchName);	//이름길이만큼 len에 숫자 저장
	for (int i = 0; i < StudentNum; i++,pSt++) {
		for (int j = 0; j < len; j++) {
			if (strlen(pSt->stdname) == len && (pSt->stdname[j] == SearchName[j]))
				return &pSt[i]; //찾는 이름과 검색한 이름의 글자수가 같고, 저장된 이름이 같을 시 해당 이름 리턴
		}
	}
	return NULL;
}

/* 4. 전체 학생의 목록: 학번과 이름을 출력 */
void PrintAllStdList(student* pSt, int StudentNum) {
	cout << "====================================\n"
		<< setw(10) << "학번" << setw(10) << "이름\n"
		<< "====================================\n";
	for (int i = 0; i < StudentNum; i++,pSt++) {
		cout << setw(10) << pSt->hakbun << setw(10) << pSt->stdname << endl;
	}
	cout << "====================================\n";
}
/* 5. 특정 학생의 이름과 학번 수정 */
void ModifyStdInfo(student* pSt) {
	cout << "* <" << pSt->stdname << " " << pSt->hakbun << ">의 정보를 수정하세요" << endl;
	cout << "이름 : "; InputValue(pSt->stdname);
	cout << "학번 : "; InputValue(pSt->hakbun);
}
