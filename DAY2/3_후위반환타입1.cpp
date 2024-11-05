// 1_후위반환타입1.cpp - 교재 73 page

// 전통적인 함수 모양 : 반환 타입이 함수 이름 앞에. 
/*
int square(int a)
{
	return a * a;
}
*/
// C++11 부터 나오는 새로운 모양
// => 리턴 타입을 함수 () 뒤에 표기
// => suffix return type(trailing return type, 후위 반환타입)
auto square(int a) -> int
{
	return a * a;
}

int main()
{
	square(3);
}

// C, C#, Java : 이름앞에 반환 타입 표기
// swift, rust, python : 이름뒤에 반환 타입 표기

// 파이썬
//def add(x, y):	// 보통 이렇게 하지만
//def add(x : int, y : int) -> int // 이렇게 해도 됩니다.
								// annotation 문법