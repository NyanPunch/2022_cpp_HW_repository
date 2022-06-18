#include "GradeManager.h"

GradeManager::GradeManager()
{
	cout << "GradeManager 디폴트 생성자 호출\n";
	m_std = NULL;
	m_stdnum = 0;
}

GradeManager::GradeManager(int m_stdnum)
{
	cout << "GradeManager 인자 생성자 호출\n";
	this->m_stdnum = m_stdnum;
	this->m_std = new Student[m_stdnum];
}

GradeManager::~GradeManager()
{
	delete[] this->m_std;
}

void GradeManager::Execute()
{
	int command = 0;
	int i = 0, temp = 0; //temp = 일부 작동 제한 변수
	string stdname;
	Student* std;

	while (command != 6) {
		PrintMenu();		//메뉴 출력
		cin >> command; cin.ignore(); //커맨드 입력
		/* 2~5번을 학생 정보 미입력상태로 입력시 */
		if (command != 1 && temp == 0 && command != 6) {
			cout << "\n!!!학생 정보부터 입력해주세요!!!\n";
			continue;
		}
		/* 학생 정보가 입력된 상태로 한 번 더 입력 시 덮어쓰기 방지 */
		if (command == 1 && temp == 1) {
			cout << "\n!!수정을 원하시면 5번을 입력해주세요!!\n";
			continue;
		}

		switch(command) {
		case 1: //정보 입력
			for (i = 0; i < this->m_stdnum; i++) {
				m_std[i].InputData();
			}
			temp = 1;		//정보 재입력 방지
			break;
		case 2: //정보 출력
			for (i = 0; i < this->m_stdnum; i++) {
				m_std[i].PrintData();
			}
			break;
		case 3: //학생 검색
			cout << "찾을 학생의 이름을 입력해주세요 : ";
			getline(cin, stdname);
			std = StdSearch(stdname);
			std->PrintData();
			break;
		case 4: //학생 리스트 출력
			PrintAllStdList();
			break;
		case 5: //정보 수정
			Modify();
			break;
		case 6:
			cout << "\n 프로그램을 종료합니다.\n";
			break;
		default:
			cout << "\n 지원하지 않는 명령어입니다.\n";
			break;
		}
	}
}

void GradeManager::PrintMenu()
{
	cout << "\n====== 메뉴 ======\n";
	cout << " 1. 학생 성적 입력\n";
	cout << " 2. 전체 성적 보기\n";
	cout << " 3. 학생 검색\n";
	cout << " 4. 학생 목록 보기\n";
	cout << " 5. 학생 정보 수정\n";
	cout << " 6. 프로그램 종료\n";
	cout << "\n 원하는 기능을 입력하세요(1~6) : ";
}
//stdname == 검색할 이름
Student* GradeManager::StdSearch(string stdname) const
{
	int temp = 0, i;
	for (i = 0; i < this->m_stdnum; i++) { //return == 메모리주소 전달할것
		if (this->m_std[i].GetName().compare(stdname) == 0) {
			temp = 1; break;
		}
	}
	if (temp == 1) return &(this->m_std[i]);
	cout << "\n찾으시는 학생이 없습니다!\n";
	return NULL;
}

void GradeManager::PrintAllStdList() const
{
	cout << "===============================\n";
	cout << "  이름            학번	        \n";
	cout << "===============================\n";
	for (int i = 0; i < m_stdnum; i++) {
		cout <<"  " << m_std[i].GetName() << "\t" << m_std[i].GetHakbun() << endl;
	}
	cout << "===============================\n";
}

void GradeManager::Modify()
{
	string stdname; //수정할 학생이름
	Student* std;
	cout << "수정할 할 학생의 이름을 입력하세요 : ";
	getline(cin, stdname);
	std = StdSearch(stdname);
	if (std) std->Modify();
}
