// reference.cpp
#include <string>

void f1(std::string s) {}		 // bad, call by value. 복사본 생성
void f2(const std::string& s) {} // good, 복사본 없음

// 다음중 좋은 코드는 ?
void f3(int n)        { int k = n; }
void f4(const int& n) { int k = n; }

int main()
{
	int a = 10;
	f3(a);
	f3(b);
}
