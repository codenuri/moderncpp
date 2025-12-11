// QA4
#include <string>

// 인자를 읽기만 하려고 합니다.
// 다음중 좋은 코드는 ?

void f1(std::string s)        {}	// bad 복사본의 오버헤드가 있다
void f2(const std::string& s) {}	// good

// 좋은 코드는 ?
void f3(int n)		// good
{
	int k = n; // n 을 바로 읽어서k 에 넣기
}

void f4(const int& n)	// bad
{
	int k = n; // k = *(n.내부주소)
}

int main()
{
	int a = 10;
	f3(a);
	f4(a);
}










