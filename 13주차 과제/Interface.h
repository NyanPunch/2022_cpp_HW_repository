#ifndef Interface_h
#define Interface_h

#include<iostream>
#include<string>
using namespace std;

class IOInterface {
protected :
	string m_name;
	int m_data;
public :
	IOInterface() {
		cout << "\nIOInterface 디폴트생성자 호출\n";
	}
	IOInterface(string m_name) {
		cout << "\nIOInterface 인자생성자 호출\n";
		this->m_name = m_name;
	}
	~IOInterface() { cout << "\nIOInterface 소멸자 호출\n"; };
	void Inputdata() {
		cout << "m_name : "; getline(cin, m_name);
		cout << "m_data : "; cin >> m_data; cin.ignore();
	}
	void PrintData() const {
		cout << "\n============================================\n";
		cout << " m_name : " << m_name << "\tm_data : " << m_data << endl;
		cout << "\n============================================\n";
	}
	void Modify() {
		cout << "값을 수정합니다.\n";
		cout << "m_name : "; getline(cin, m_name);
		cout << "m_data : "; cin >> m_data; cin.ignore();
	}
	string GetName() const {
		return m_name;
	}
	int GetData() const {
		return m_data;
	}
};
#endif // !Interface_h
