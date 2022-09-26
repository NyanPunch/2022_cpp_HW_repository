/*******************************
프로그램명: 성적처리프로그램
작 성 자: 2019038054 김경민
작 성 일: 2022 03 04 ~ 2022 03 11
프로그램 설명: 학생의 정보를 입력받고 요구사항에 맞게 출력
********************************/
#include <iostream>
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

void inputdata(student s[]);			//성적입력함수
void print_list(student s[]);			//성적출력함수
void cal_grade(student s[]);			//평점계산함수

int main() {
	student s[MAX_Stu];
	cout.precision(2);
	cout << fixed;
	int flag = 0;
	while (1) {
		cout << "\n===== 메뉴 =====\n"
			<< "1. 학생 성적 입력\n"
			<< "2. 전체 학생 성적 보기\n"
			<< "3. 프로그램 종료" << endl;

		cout << "원하는 기능을 입력하세요 : ";
		
		int menu;
		cin >> menu;
		cout << endl;
		
		if (menu == 1)		//성적 미 기입 및 성적 출력을 하려 할때
			flag = 1;
		else if ((menu == 2) && (flag == 0)) {
			cout << "학생 성적 부터 입력해주세요\n" << "성적 입력란으로 이동합니다." << endl;
			menu = 1;		//break 사용 시 종료됨 강제로 1번 이동
			flag = 1;
		}
		
		switch (menu) {
		case 1:
			inputdata(s);
			cal_grade(s);		
			break;
		case 2:
			print_list(s);
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "\n1~3번을 입력하세요.\n";		// 1 ~ 3 외 입력 시 출력 (번호만 해당, 글자 입력시 무한루프)
			break;
		}
	}
	return 0;
}

void inputdata(student s[]) {						//정보 입력 함수 case 1:
	int i, j;							// i = 학생 j = 학생의 세 과목

	for (i = 0; i < MAX_Stu; i++) {		
		cout << endl << "* " << i + 1 << " 번 째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		cin >> s[i].stdname;
		cout << "학번 : ";
		cin >> s[i].hakbun;
		cout << endl << "* 수강한 과목 세 개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (j = 0; j < MAX_Sub; j++) {
			cout << "교과목명 : ";
			cin >> s[i].Sub[j].subname;
			cout << "과목학점 : ";
			cin >> s[i].Sub[j].hakjum;
			cout << "과목등급(A+ ~ F) : ";
			cin >> s[i].Sub[j].grade; cout << endl;

			//과목 평점 처리	//오류 //오류 해결
			if (strcmp(s[i].Sub[j].grade, "A+") == 0)
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 4.5;
			else if ((strcmp(s[i].Sub[j].grade, "A0") == 0) || (strcmp(s[i].Sub[j].grade, "A") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 4.0;
			else if ((strcmp(s[i].Sub[j].grade, "B+") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 3.5;
			else if ((strcmp(s[i].Sub[j].grade, "B0") == 0) || (strcmp(s[i].Sub[j].grade, "B") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 3.0;
			else if ((strcmp(s[i].Sub[j].grade, "C+") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 2.5;
			else if ((strcmp(s[i].Sub[j].grade, "C0") == 0) || (strcmp(s[i].Sub[j].grade, "C") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 2.0;
			else if ((strcmp(s[i].Sub[j].grade, "D+") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 1.5;
			else if ((strcmp(s[i].Sub[j].grade, "D0") == 0) || (strcmp(s[i].Sub[j].grade, "D") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 1.0;
			else if ((strcmp(s[i].Sub[j].grade, "F") == 0))
				s[i].Sub[j].GPA = s[i].Sub[j].hakjum * 0.0;
		}
	}
}


void cal_grade(student s[]) {		//평균평점 계산 함수 //오류 해결
	int i, j;

	for (i = 0; i < MAX_Stu; i++) {
		for (j = 0; j < MAX_Sub; j++) {
			s[i].avgGPA = s[i].Sub[j].GPA / s[i].Sub[j].hakjum;
		}
	}
}

void print_list(student s[]) {						//학생 성적 출력함수 case 2:
	cout.width(10);
	cout << "전체 학생 성적보기\n";

	int i, j;

	for (i = 0; i < MAX_Stu; i++) {					//학생 반복 출력문
		cout << "=========================================\n";
		cout << "이름 : " << s[i].stdname << " 학번 : " << s[i].hakbun << endl;
		cout << "=========================================\n";
		cout.width(10); cout << "과목명";
		cout.width(10); cout << "과목학점";
		cout.width(10); cout << "과목등급";
		cout.width(10); cout << "과목평점" << endl;
		cout << "=========================================\n";

		for (j = 0; j < MAX_Sub; j++) {				//과목 반복 출력문
			cout.width(10); cout << s[i].Sub[j].subname;
			cout.width(10); cout << s[i].Sub[j].hakjum;
			cout.width(10); cout << s[i].Sub[j].grade;
			cout.width(10); cout << s[i].Sub[j].GPA << endl;
		}
		cout << "=========================================\n";
		cout.width(35);
		cout << "평균평점  " << s[i].avgGPA << endl;
	}
}