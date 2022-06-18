/*******************************
���α׷���: ���� ����
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 27
���α׷� ����: ����Ŭ������ Ȱ���� ���� ���� ���α׷� �ۼ�
********************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std; //std:: ����

struct WORD {
	string str;
	int count;
};
vector <WORD*> words;

int SameWords(const string& s);		//���� ���� ����
void CountWords(const string& s);	//���� ����
void PrintWords();					//���
void RemoveAll();					//����

int main() {
	cout << "���ڿ� �Է�, ���� : Ctrl+Z\n";
	string buffer;
	while (cin >> buffer)
		CountWords(buffer); //���ڿ� �Է¹ޱ�

	PrintWords();
	RemoveAll();
	return 0;
}
/* ������ �Է��� �ܾ �ԷµǴ��� �Ǵ� */
int SameWords(const string& str) {
	for (int i = 0; i < words.size(); i++)
		if (words[i]->str == str) return i;
	return -1;
}
/* �ܾ� �� ���� */
void CountWords(const string& str) {
	int index = SameWords(str);
	/* ���� �ܾ ���� �� �ܾ� �߰� */
	if (index == -1) {
		WORD* p = new WORD;
		p->str = str;
		p->count = 1;
		words.push_back(p);
	}
	/* ���� �ܾ� ���� �� ī��Ʈ�� �߰� */
	else words[index]->count++;
}
/* �ܾ� ��� �Լ� */
void PrintWords() {
	cout << "\n==========\n";
	for (int i = 0; i < words.size(); i++)
		cout << words[i]->str << " : " << words[i]->count << "��\n";
	cout << "==========\n";
}
/* �Ҵ� ���� �Լ� */
void RemoveAll() {
	for (int i = 0; i < words.size(); i++)
		delete words[i];
}
