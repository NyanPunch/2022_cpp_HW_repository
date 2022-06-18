#ifndef Interface_h
#define Interface_h

#include<iostream>
#include<string>
using namespace std;

/* �߻�Ŭ������ ����
 *  �����ڻ���, �����������, �������Լ�����
 */
class IOInterface {
public :
	virtual ~IOInterface() { cout << "\nIOInterface �Ҹ��� ȣ��\n"; };
	virtual void InputData() = 0;
	virtual void PrintData() const = 0;
	virtual void Modify() = 0;
};
#endif // !Interface_h
