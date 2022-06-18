#ifndef Interface_h
#define Interface_h

#include<iostream>
#include<string>
using namespace std;

/* 추상클래스로 변경
 *  생성자삭제, 멤버변수삭제, 접근자함수삭제
 */
class IOInterface {
public :
	virtual ~IOInterface() { cout << "\nIOInterface 소멸자 호출\n"; };
	virtual void InputData() = 0;
	virtual void PrintData() const = 0;
	virtual void Modify() = 0;
};
#endif // !Interface_h
