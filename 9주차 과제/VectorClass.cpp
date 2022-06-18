/*******************************
프로그램명: 문자 세기
작 성 자: 2019038054 김경민
작 성 일: 2022 04 27
프로그램 설명: 벡터클래스를 활용해 문자 세는 프로그램 작성
********************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std; //std:: 생략

struct WORD {
	string str;
	int count;
};
vector <WORD*> words;

int SameWords(const string& s);		//동일 문자 세기
void CountWords(const string& s);	//문자 세기
void PrintWords();					//출력
void RemoveAll();					//해제

int main() {
	cout << "문자열 입력, 종료 : Ctrl+Z\n";
	string buffer;
	while (cin >> buffer)
		CountWords(buffer); //문자열 입력받기

	PrintWords();
	RemoveAll();
	return 0;
}
/* 이전에 입력한 단어가 입력되는지 판단 */
int SameWords(const string& str) {
	for (int i = 0; i < words.size(); i++)
		if (words[i]->str == str) return i;
	return -1;
}
/* 단어 수 세기 */
void CountWords(const string& str) {
	int index = SameWords(str);
	/* 동일 단어가 없을 시 단어 추가 */
	if (index == -1) {
		WORD* p = new WORD;
		p->str = str;
		p->count = 1;
		words.push_back(p);
	}
	/* 동일 단어 존재 시 카운트만 추가 */
	else words[index]->count++;
}
/* 단어 출력 함수 */
void PrintWords() {
	cout << "\n==========\n";
	for (int i = 0; i < words.size(); i++)
		cout << words[i]->str << " : " << words[i]->count << "번\n";
	cout << "==========\n";
}
/* 할당 해제 함수 */
void RemoveAll() {
	for (int i = 0; i < words.size(); i++)
		delete words[i];
}
