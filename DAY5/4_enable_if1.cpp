// 6_enable_if1.cpp
// 아래 enable_if 는 이미 C++ 표준에 있습니다(아래와 거의 동일)
template<bool, typename T = void > struct enable_if
{
	using type = T;
};
template<typename T> struct enable_if<false, T> 
{
	// type 이 없다
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1;	// int n1
	enable_if<true>::type       n2; // void n2. 그런데, void 는 변수 생성안됨. error
	enable_if<false, int>::type n3; // error. 타입없음.
	enable_if<false>::type      n4; // error. 타입없음.
				// 부분 특수화 버전은 디폴트값 없지만, primary 때문에사용가능
}
