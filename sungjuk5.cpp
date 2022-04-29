/*******************************
프로그램명: 성적처리프로그램 5
작 성 자: 2019038054 김경민
작 성 일: 2022 04 25
프로그램 설명: 학생의 정보를 입력받고 요구사항에 맞게 출력
업데이트 내용: string함수 이용, getline() 사용, ModifyStdInfo(), 
********************************/
#include <iostream>
#include <string>			
#include <iomanip>
#include <cstring>

using namespace std;

struct Subject {			//과목 정보 구조체
	string subname;		    //과목 명			/* string 변경 */
	int hakjum;				//과목 학점
	char grade[10];			//과목 등급
	float GPA;				//과목 평점
};

struct student {			//학생 정보 구조체
	string stdname;		    //이름				/* string 변경 */
	int hakbun;				//학번
	Subject* Sub;			//과목
	int SubNum;				//과목 수
	float aveGPA;			//교과목 평균 평점
};

int menu = 0;

void InputData(student* pSt, int StudentNum);			//성적입력함수
void CalcGPA(Subject& Sub);								//교과목 평점계산
float CalcAveGPA(Subject* Sub, int SubNum);				//개인학생 평균 평점 계산
void PrintAllData(const student* pSt, int StudentNum);	//전체학생 출력 
void PrintOneData(const student& rSt);					//개인학생 출력
void PrintAllStdList(student* pSt, int StudentNum);		//학생 리스트
void ModifyStdInfo(student* pSt);						//학생 정보 수정
student* StdSearch(student* pSt, int StudentNum);		//학생 검색
Subject* SubSearch(const student* pSt);					//과목 검색

inline void InputValue(char* str) {
	cin >> str; cin.ignore();
}
inline void InputValue(int& i) {
	cin >> i; cin.ignore();
}
inline void InputValue(string& str) {
	getline(cin, str);
}
	/* 메뉴 */
inline void PrintMenu() {
	cout << "\n===== 메뉴 =====\n"
		<< "1. 학생 성적 입력\n"
		<< "2. 전체 학생 성적 보기\n"
		<< "3. 학생 이름 검색\n"
		<< "4. 전체 학생 목록 보기\n"
		<< "5. 학생 정보 수정\n"
		<< "6. 프로그램 종료" << endl;
	cout << "원하는 기능을 입력하세요 : ";
	InputValue(menu);
}

int main() {
	cout.precision(2);
	cout << fixed;
	struct student* Std = NULL;	//학생 구조체 동적 메모리 할당
	int flag = 0, StdNum = 2;

	cout << "\n정보를 등록할 학생 수를 입력해주세요. : ";
	cin >> StdNum;
	Std = new student[StdNum]; // 동적 메모리 사용
	
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
			InputData(Std, StdNum);
			break;
		case 2:	//학생 전체 정보 출력
			PrintAllData(Std, StdNum);
			break;
		case 3:	//학생 이름 검색 후 출력
			student * SearchStd;
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL)
				PrintOneData(*SearchStd);
			break;
		case 4: //학생 리스트 출력
			PrintAllStdList(Std, StdNum);
			break;
		case 5: //학생 정보 수정
			ModifyStdInfo(StdSearch(Std, StdNum));
			break;
		case 6:
			cout << "\n프로그램을 종료합니다\n";
			break;
		default:
			cout << "지원하지 않는 형식입니다.\n";
			break;
		}
	}
	return 0;
}

/* 교과목 성적 처리 */
void CalcGPA(Subject& Sub) {
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
	else if (strcmp(Sub.grade, "D+") == 0)
		Sub.GPA = (float)Sub.hakjum * 1.5;
	else if ((strcmp(Sub.grade, "D0") == 0) || (strcmp(Sub.grade, "D") == 0))
		Sub.GPA = (float)Sub.hakjum * 1.0;
	else if (strcmp(Sub.grade, "F") == 0)
		Sub.GPA = (float)Sub.hakjum * 0;
}

/* 평균 처리 */
float CalcAveGPA(Subject* Sub, int SubNum) {
	float sumGPA = 0;
	for (int i = 0; i < SubNum; i++)
		sumGPA += Sub[i].GPA;
	return (sumGPA / SubNum);
}

/* 1. 학생 정보 입력 */
void InputData(student* pSt, int StudentNum) {
	int i, j;			// i = 학생 j = 학생의 세 과목
	float AveGPA;
	int SubNum;
	for (i = 0; i < StudentNum; i++) {
		cout << endl << "* " << i + 1 << " 번 째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : "; InputValue(pSt[i].stdname);
		cout << "학번 : "; InputValue(pSt[i].hakbun);
		cout << endl;

		cout << "수강한 과목 수를 입력 : ";
		InputValue(SubNum);
		pSt[i].SubNum = SubNum; //i번째 학생 과목수 저장
		/* i번 학생의 과목수 만큼 동적 할당 */
		pSt[i].Sub = new Subject[SubNum];

		//n번째 학생의 입력받은 과목 수 만큼 동적 할당.
		cout << "\n* 수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
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

/* 2. 전체 학생 정보 출력 */
void PrintAllData(const student* pSt, int StudentNum) {
	cout.width(10);
	cout << "\n전체 학생 성적보기\n";
	for (int i = 0; i < StudentNum; i++, pSt++) PrintOneData(*pSt);
}

/* 학생 개인 정보 출력*/
void PrintOneData(const student& rSt) {
	cout << "\n=========================================\n";
	cout << setw(10) << "이름 : " << rSt.stdname << " 학번 : " << rSt.hakbun << endl;
	cout << "=========================================\n";
	cout << setw(10) << "과목명" << setw(10) << "과목학점" << setw(10) << "과목등급 " << setw(10) << "과목평점" << endl;
	cout << "=========================================\n";

	for (int j = 0; j < rSt.SubNum; j++)	//과목 반복 출력문
		cout << rSt.Sub[j].subname << setw(10) << rSt.Sub[j].hakjum << setw(10) << rSt.Sub[j].grade << setw(10) << rSt.Sub[j].GPA << endl;
	cout << "=========================================\n";
	cout.width(35);
	cout << "평균평점  " << rSt.aveGPA << endl;
}

/* 3. 이름을 검색하여 학생의 정보 출력 */
student* StdSearch(student* pSt, int StudentNum) {
	string SearchName;
	cout << "\n찾을 학생의 이름을 입력해주세요.\n이름 : ";
	InputValue(SearchName);
	for (int i = 0; i < StudentNum; i++, pSt++) {
		if (pSt->stdname.size() == SearchName.size() && pSt->stdname == SearchName) //Searchname과 이름의 글자수가 같고, 저장된 이름이 같을 시 해당 이름 리턴
			return &pSt[i]; 
	}
	return NULL;
}

/* 4. 전체 학생의 목록: 학번과 이름을 출력 */
void PrintAllStdList(student* pSt, int StudentNum) {
	cout << "\n====================================\n"
		<< setw(10) << "학번" << setw(10) << "이름\n"
		<< "====================================\n";
	for (int i = 0; i < StudentNum; i++, pSt++) 
		cout << setw(10) << pSt->hakbun << setw(10) << pSt->stdname << endl;
	cout << "====================================\n";
}

/* 5. 특정 학생의 이름과 학번 수정 */
void ModifyStdInfo(student* pSt) {
	/* 학생정보, 과목정보 문자열 입력받고 수정 */
	if (pSt != NULL) {
		string TYPE;

		cout << "수정할 정보를 입력하세요<학생정보/과목정보> : ";
		InputValue(TYPE);
		/*학생정보 or 과목정보 수정*/
		if (TYPE == "학생정보") {
			cout << "\n* <" << pSt->stdname << " " << pSt->hakbun << ">의 정보를 수정하세요" << endl;
			cout << "이름 : "; InputValue(pSt->stdname);
			cout << "학번 : "; InputValue(pSt->hakbun);
		}
		else if (TYPE == "과목정보") {
			Subject* Sub = SubSearch(pSt);
			if (Sub != NULL) {
				cout << "* <" << pSt->Sub->subname << ", 학점: " << pSt->Sub->hakjum << ", 등급: " << pSt->Sub->grade << ">의 정보를 수정하세요" << endl;
				cout << "교과목명 : "; InputValue(pSt->Sub->subname);
				cout << "과목학점 : "; InputValue(pSt->Sub->hakjum);
				cout << "과목등급 : "; InputValue(pSt->Sub->grade);
				CalcGPA(*Sub);
				int SubNum = pSt->SubNum;
				pSt->aveGPA = CalcAveGPA(Sub,SubNum);
			}
		}
	}
}
/* 학생의 과목정보 수정 함수 */
Subject* SubSearch(const student* pSt) {
	string SearchSub;
	cout << "검색할 과목 이름 : ";
	InputValue(SearchSub);
	int SubNum = pSt->SubNum;
	for (int i = 0; i < SubNum;i++) {
		if (pSt->Sub[i].subname.size() == SearchSub.size() && pSt->Sub[i].subname == SearchSub)
			return &pSt->Sub[i];
	}
	return NULL;
}
