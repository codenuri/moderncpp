// 6_enable_if1.cpp

// 아래 코드가 실제 C++ 표준에 있습니다. (표준도 아래와 거의 동일합니다.)
template<bool, typename T = void > struct enable_if
{
	using type = T;
};

template<typename T> struct enable_if<false, T> 
{
	// 핵심 : 이 안에는 type 이 없습니다.
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2  void 타입변수안되므로 error
	enable_if<false, int>::type n3; // error. "::type" 이 없다.

//	enable_if<false>::type n4; // 
//  enable_if<false, void>::type n4; // 위 코드는 이코드
}