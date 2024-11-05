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
// godbolt.org

// 복사 생성자가 있거나, 크기가 8(12)바이트 이상 되는 타입
// => const & 권장

// 복사생성자가 없고, 크기가 작은 타입 
// => call by value
// => primitive type, iterator, std::initializer_list
// => range 의 타양한 view 들..
// => std::string_view
