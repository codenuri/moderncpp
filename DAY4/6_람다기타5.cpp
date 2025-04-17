// 5_람다표현식6
// 람다표현식은 인자를 받는 방법 - 143p 아래 부분

// #1. 함수 포인터
// => 캡쳐한 람다는 받을수 없다.!!
void foo( int(*f)(int, int) )
{
}

// #2. std::function
// => 모든 람다 표현식 가능. 
void foo( std::function<int(int, int)> f )
{
	f(1, 2); // 단, 이경우 인라인 치환은 안됨
			 // foo 자체는 템플릿 아니므로 한개만 존재
}

// #3. template
template<typename T>
void foo(T f)
{
	f(1, 2); // 인라인 치환 가능
			 // 템플릿이므로 여러개 foo 생성됨. 
}

// #4. T&
template<typename T>
void foo(T& f) {} // error. 람다 표현식은 rvalue!


int main()
{
	foo([](int a, int b) { return a + b; });
	foo([](int a, int b) { return a - b; });
}


