// 5_람다표현식6
// 람다표현식은 인자를 받는 방법 - 143p 아래 부분

// 방법 #1. 함수 포인터
// => 장점 : template 이 아니다, foo 는 한개
// => 단점 : 캡쳐한 람다는 받을수 없다.
void foo(int(*f)(int, int))
{
}

// 방법#2. T&
template<typename T>
void foo(T& f)		// error. 람다표현식은 rvalue
{
}

// 방법#3. const T&
// => 모든 람다표현식 받을수 있다.
// => mutable 람다는 사용할수 없다.(호출 안됨)
// => f 사용시 결국 포인터를 통해서 접근 하는것. 약간의 성능저하
template<typename T>
void foo(const T& f)
{
	f(1, 2);
}

// 방법 #4. T
// => 람다 표현식, 함수객체, 일반함수(포인터)
// => 모두 일반적으로 크기가 크지 않다.
// => 복사본 만들어 사용해도 오버헤드 없다.
// => 가장 권장!
template<typename T>
void foo(T f)
{
	f(1, 2);
}

// #5. 만일 많은 데이타를 캡쳐한 람다, 함수객체를 사용하면
// => T&&
template<typename T>
void foo(T&& f)
{
	f(1, 2); // 이렇게도 되지만

	std::forward<T>(f)(1, 2); // 권장
}


int main()
{
	foo([](int a, int b) { return a + b; });
	foo([](int a, int b) mutable { return a - b; });
}


