
template<typename T> void f1(T arg)
{
}

// 가변인자 함수 템플릿
// 인자가 한개인 함수 템플릿 : 인자가 한개 인 함수를 생성하겠다는 것
// 가변인자     함수 템플릿 : 인자에 갯수 상관없이 어떤 형태의 함수도 만들수 있다.
// => 이부분을 학습할때는 "godbolt.org" 로 직접 확인해 보세요
template<typename ... Types> void f2(Types ... args)
{
}

int main()
{
	f1(1);
	f1(3.4);

	f2(1, 3.4, 'A');
}