// reference.cpp
#include <string>

void f1(std::string s) {}		 // bad, call by value. ���纻 ����
void f2(const std::string& s) {} // good, ���纻 ����

// ������ ���� �ڵ�� ?
void f3(int n)        { int k = n; }
void f4(const int& n) { int k = n; }

int main()
{
	int a = 10;
	f3(a);
	f3(b);
}
