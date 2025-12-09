#include <iostream>

// C++11 스타일 
// => 아래 코드는 리턴 타입을 표기한것 : decltype(a * b)
// => 따라서, return 문장이 여러개 있어도 아무 문제 없음. 
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b) ->decltype(a * b)
{
    if ( a == 0 ) return 0; 
	return a * b;
}

// C++14 부터 반환 타입 위치에 "auto" 만 표기하는 것도 허용 -C++11은 안됨
// => "return 표현식" 을 보고 반환 타입을 추론해 달라.
// => return 문장이 2개 이상이고 서로 다른 타입을 반환 한다면 에러
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b) 
{
    // a: int, b: double 인경우
    if ( a == 0 ) return 0;  // return int 반환
	return a * b;            // return double 반환
                             // => auto 가 타입 결정 못함. error
}

int main()
{
    Mul2(0, 3.4);


}

