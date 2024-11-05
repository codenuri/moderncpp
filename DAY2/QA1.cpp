// QA1.cpp
// 인자로 전달된 값을 읽기만 하려고 합니다.
// 다음중 좋은 코드는 ?
void f1(int n)        { int a = n; } // good
					// int a = 복사본에서 꺼내기. 


void f2(const int& n) { int a = n; } // bad
					// int a = *n 의 의미
					// => 주소를 따라가서 꺼내 오기 때문에 오버헤드있음

int main()
{
	int x = 3;
	f1(x);
	f2(x);
}
// 