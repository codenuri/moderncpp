// QA1.cpp
// 인자로 전달된 값을 읽기만 하려고 합니다.
// 다음중 좋은 코드는 ?
void f1(int n)        { int a = n; }
void f2(const int& n) { int a = n; }

int main()
{
	int x = 3;
	f1(x);
	f2(x);
}